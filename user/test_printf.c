#include "kernel/types.h"
#include "user/user.h"

void main(int argc, char **argv) {
    printf("%d, %d, %d\n", 12,-12, 0xFFFFFFFFF);
    printf("%l, %l\n", 0xFFFFFFFFF, -0xFFFFFFFFF);
    printf("%x, %x\n", 0xFF, -0xFF);
    printf("%p\n", 0xFFFFFFFFF);
    printf("%s\n", "hi");
    printf("%u, %u\n", 12,-12);
    printf("%ul, %ul\n", 0xFFFFFFFFF, -0xFFFFFFFFF);
}