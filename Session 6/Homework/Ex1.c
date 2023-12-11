#include <stdio.h>
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 1; i <= 10; i++)
    {
        int ket_qua = n * i;
        printf("%d x %d = %d\n", n, i, ket_qua);

    }
}