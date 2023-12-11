#include <stdio.h>
#include <math.h>
int main()
{
    float r, chuVi, dienTich;
    printf("Nhap r = ");
    scanf("%f", &r);
    int Pi = 3.14;
    chuVi = (r * 2) * Pi;
    dienTich = r*r * Pi;
    printf("Dien tich hinh tron = %.2f\n", dienTich);
    printf("Chu vi hinh tron = %.2f", chuVi);

}
