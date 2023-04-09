#include <stdio.h>

int get_endianness(void)
{
    unsigned int i = 1;
    char *c = (char *)&i;
    return (*c == 1);
}

