#include<stdio.h>
int swap(int *n1, int *n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
int main() {
    int a = 100, b= 200;
    printf("Hieu a,b truoc khi doi cho = %d\n", a-b);
    swap(&a, &b);
    printf("Hieu a, b sau khi doi cho = %d", a-b);
    return 0;
}