#include<stdio.h>
int main () {
    int a = 100;
    int *ptr;
    ptr = &a;
    printf("Gia tri cua a = %d\n",a);
    printf("Gia tri cua a = %d\n", *ptr);
    printf("Dia chi cua bien a = %p\n", ptr);
    printf("Dia chi cua bien a = %p\n", &a);
    return 0;
}
