# FAQ

Date: 2024-11-21

Author: CCX开发环境搭建交流群成员

---



## Q1: clangd报错找不到标准库的头文件, stdio.h, stdint.h这些

这是因为没有像clangd指定我们所使用的编译器.

可以在`DEMO.code-workspace`文件中的settings里加上如下字段:

```json
"clangd.arguments": [
  "--query-driver=D:/Developer_Tools/Toolchain/arm-gnu-toolchain-13.3.1/bin/arm-none-eabi-gcc.exe,D:/Developer_Tools/Toolchain/arm-gnu-toolchain-13.3.1/bin/arm-none-eabi-g++.exe"
],
```

即, 向clangd指定你所使用的编译器, 这样clangd就会根据编译器, 相对找到标准头文件所在的位置, 然后将那些目录给包含进来, 这样clangd就可以找到这些头文件了.

> 注意: 上面的路径注意替换为自己电脑上的路径. 设置完毕之后, 删除.cache文件夹, 然后ctrl+shift+p, 选择"重启clangd语法服务器".

clangd里面其实专门有一个东西叫System Includes Extractor的东西, 专门用来根据指定的编译器路径相对找到头文件路径.

![](Picutres/微信图片_20241121230129.jpg)

![](Picutres/微信图片_20241121230141.jpg)

> `--log=verbose`参数可以让clangd打印出更详细的信息, 大家可以看看它输出的信息里面有关于System Includes Extractor的东西.

==强烈大家去clangd官网上看一下它的文档, 真的讲的非常详细==



## 会讲CMakeLists.txt怎么写吗

不会.

CMake东西太多了, 我不可能全部讲完, 而且里面很多东西我也不会.

所以最好是先去大致学一下CMake, 有一点基础, 然后再来看这个教程.

