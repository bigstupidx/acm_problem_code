#include <stdio.h>

char stack[10000000000];
int vesp, vebp;

int main() {
    vesp = (int) stack + (sizeof stack) - 0x10;
    __asm__(
            "movl %%ebp,%1;"
            "movl %0,%%ebp;"
            "mov %%esp,%0;"
            "mov %%ebp,%%esp;"
            "sub $0x100,%%esp;"
            ::"m"(vesp), "m"(vebp));
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",a+b);
    __asm__(
            "movl %1,%%ebp;"
            "mov %0,%%esp;"
            ::"m"(vesp), "m"(vebp));
}
