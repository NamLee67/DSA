#include <stdio.h>
#include <stdint.h>

struct abc
{   
    uint8_t b[1];
    uint8_t a[1];
    int i;
}__BIGGEST_ALIGNMENT__;

int main(int argc, char const *argv[])
{
    struct abc aaa;
    printf("%d",sizeof(aaa));
    return 0;
}
