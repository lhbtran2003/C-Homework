#include <stdio.h>
int main() {
    int n, i;
    printf("Nhap kich co mang: ");
    scanf("%d", &n);
    int array[n];
    int *ptr = array;
    //  nhap so
    printf("Nhap %d so nguyen vao trong mang:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    //   in mang dao nguoc
printf("mang dao nguoc: ");
    for(i = n - 1; i >= 0; i--) {
        printf("\n%d\n",  *ptr);
        ptr--;
    }
    return 0;
}
