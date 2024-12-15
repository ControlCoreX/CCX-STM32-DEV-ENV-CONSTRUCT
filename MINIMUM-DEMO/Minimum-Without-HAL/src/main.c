#include "cmsis_compiler.h"

int main()
{
    for (unsigned int i = 0; i < 10000000; i++)
    {
        __NOP();
        __NOP();
        __NOP();
        __NOP();
    }
}
