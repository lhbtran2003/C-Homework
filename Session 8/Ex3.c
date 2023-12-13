#include <stdio.h>

int main()
{
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++)
    {
        printf("Nhap gia tri cua phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    int findNumber; // giá trị cần tìm
    printf("Nhap gia tri can tim: ");
    scanf("%d", &findNumber);
    int sum = 0;
    printf("Cac phan tu co gia tri bang %d la: \n", findNumber);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == findNumber)
        {
            printf("a[%d] = %d\n", i, a[i]);
            sum += a[i];
        }
    }

    printf("Tong cac phan tu co gia tri bang %d la: %d\n", findNumber, sum);
    return 0;
}
