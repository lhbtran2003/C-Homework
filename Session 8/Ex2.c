#include <stdio.h>

int main()
{
    int row, col; // số hàng và số cột của mảng
    printf("Nhap so hang cua mang: ");
    scanf("%d", &row);
    printf("Nhap so cot cua mang: ");
    scanf("%d", &col);
    double a[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Nhap gia tri cua phan tu a[%d][%d]: ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    double sum = 0; // biến lưu trữ tổng các phần tử chẵn
    // in ra giá trị các phần tử chẵn và tính tổng chúng
    printf("Cac phan tu co gia tri chan trong mang la: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if ((int)a[i][j] % 2 == 0)
            {
                printf("%lf ", a[i][j]);
                sum += a[i][j];
            }
        }
        printf("\n");
    }

    printf("Tong cac phan tu co gia tri chan trong mang la: %lf\n", sum);
    return 0;
}
