#include <stdio.h>
#include <limits.h>

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
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i]; // cập nhật giá trị lớn nhất
        }
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    // in ra kết quả
    printf("Gia tri lon nhat trong mang la: %d\n", max);
    printf("Gia tri nho nhat trong mang la: %d\n", min);
    return 0;
}
