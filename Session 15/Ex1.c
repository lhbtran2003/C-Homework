#include <stdio.h>
#include<stdlib.h>
void fibonnaci(int y, int x);
int main(void) {
    int x, y;
    printf("Nhap so cot cua mang 2 chieu:");
    scanf("%d", &y);
    printf("Nhap so hang cua mang 2 chieu:");
    scanf("%d", &x);
    int *nums;
    //Cấp phát bộ nhớ động và gán vào biến con trỏ
    nums = malloc(sizeof(int) * x * y);
    printf("Nhap gia tri tung phan tu:");
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            scanf("%d", &nums[i * x + j]);
        }
    }
    fibonnaci(y,x);
    free(nums);
    return 0;
}
void fibonnaci(int y, int x)
{
    int a=0, b=1, i, j, c;
    int *fib = (int*)malloc(x * y * sizeof(int));
    fib[0] = a;
    fib[1] = b;
    for(i = 2; i < y*x; i++)
    {
        c = a + b;
        fib[i] = c;
        a = b;
        b = c;
    }
    printf("Cac so fibonnaci la:\n");
    for(i = 0; i < y; i++)
    {
        for(j = 0; j < x; j++)
        {
            printf("%d ", fib[i*x+j]);
        }
        printf("\n");
    }
}