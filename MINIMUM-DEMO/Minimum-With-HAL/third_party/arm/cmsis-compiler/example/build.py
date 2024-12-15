#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import logging

from datetime import datetime
from enum import Enum
from glob import glob, iglob
from pathlib import Path

from zipfile import ZipFile

from matrix_runner import main, matrix_axis, matrix_action, matrix_command, matrix_filter


@matrix_axis("compiler", "c", "Compiler(s) to be considered.")
class CompilerAxis(Enum):
    AC6 = ('AC6')
    GCC = ('GCC')
    IAR = ('IAR')
    CLANG = ('Clang')

    @property
    def image_ext(self):
        ext = {
            CompilerAxis.AC6: 'axf',
            CompilerAxis.GCC: 'elf',
            CompilerAxis.IAR: 'out',
            CompilerAxis.CLANG: 'elf',
        }
        return ext[self]

    @property
    def toolchain(self):
        ext = {
            CompilerAxis.AC6: 'AC6',
            CompilerAxis.GCC: 'GCC',
            CompilerAxis.IAR: 'IAR',
            CompilerAxis.CLANG: 'CLANG'
        }
        return ext[self]


@matrix_axis("build", "b", "Build-type(s) to consider.")
class BuildTypeAxis(Enum):
    Debug = ('Debug')
    Release = ('Release')

def solution_file():
    return "retarget.csolution.yml"

def context(config):
    return f"{config.build}+VHT_CM3"

def config_suffix(config, timestamp=True):
    suffix = f"{config.compiler[0]}-{config.build}"
    if timestamp:
        suffix += f"-{datetime.now().strftime('%Y%m%d%H%M%S')}"
    return suffix

def output_basedir():
    return "out"

def output_dir(config):
    return f"{output_basedir()}/retarget/VHT_CM3/{config.build}"

@matrix_action
def clean(config):
    """Build the selected configurations using CMSIS-Build."""
    yield cbuild_clean(solution_file())


@matrix_action
def build(config, results):
    """Build the selected configurations using CMSIS-Build."""

    logging.info("Compiling Tests...")

    yield cbuild(solution_file(), config)

    if not all(r.success for r in results):
        return

    file = f"{output_basedir()}/example-{config_suffix(config)}.zip"
    logging.info("Archiving build output to %s...", file)
    with ZipFile(file, "w") as archive:
        for content in iglob(f"{output_dir(config)}/**/*", recursive=True):
            if Path(content).is_file():
                archive.write(content)


@matrix_action
def extract(config):
    """Extract the latest build archive."""
    archives = sorted(glob(f"{output_basedir()}/example-{config_suffix(config, timestamp=False)}-*.zip"), reverse=True)
    yield unzip(archives[0])

def expect_in(expectation, text):
    if expectation not in text:
        raise AssertionError(f"'{expectation}' not found in '{text}'!")

@matrix_action
def run(config, results):
    """Run the selected configurations."""
    logging.info("Running Example on Arm model ...")
    yield model_exec(config)

    if not all(r.success for r in results):
        return
    
    try:
        output = results[0].output.getvalue()
        for i in range(1, 10):
            expect_in(f"Hello World {i}", output)
        expect_in(f"Finished", output)
    except AssertionError as e:
        logging.error(e)    
        results[0].success = False

@matrix_command()
def cbuild_clean(project):
    return ["cbuild", "-p", "-C", project]


@matrix_command()
def unzip(archive):
    return ["bash", "-c", f"unzip -o {archive}"]


@matrix_command()
def cbuild(solution, config):
    return ["cbuild", "--toolchain", config.compiler.toolchain, "-p", "--update-rte", \
             "--context", f".{context(config)}", solution ]


@matrix_command()
def model_exec(config):
    cmdline = ["FVP_MPS2_Cortex-M3", "-q", "--simlimit", 1, "-f", "fvp-config.txt"]
    cmdline += ["-a", f"{output_dir(config)}/retarget.{config.compiler.image_ext}"]
    return cmdline


@matrix_filter
def filter_iar(config):
    return config.compiler == CompilerAxis.IAR

if __name__ == "__main__":
    main()
