
#include<stdio.h>
int prime(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    if (count == 2)
    {
       return 1;
    }
    else
    {
       return 0;
    }
}
int main() {
    int a, b, n;
    printf("Nhap so dau va cuoi lan luot = ");
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        if (prime(i) == 1)
            printf("%d ", i);
    }
    if (prime(n) == 0)
        printf("Khong ton tai so nguyen to nao");

}

