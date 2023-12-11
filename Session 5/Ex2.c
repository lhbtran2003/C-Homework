#include <stdio.h>
#include <math.h>
int main () {
    float doanh_thu, hoa_hong_1, hoa_hong_2, hoa_hong_3;
    printf("Doanh thu =   (don vi: trieu)", doanh_thu);
    scanf("%f", &doanh_thu);
    if (doanh_thu <= 100)
    {
        hoa_hong_1 = 0.05 * doanh_thu;
        printf("Hoa hong = %f\n", hoa_hong_1);
    }
    else if (100 < doanh_thu <= 300)
    {
        hoa_hong_2 = 0.1 * doanh_thu;
        printf("Hoa hong = %f", hoa_hong_2);
    }
    else if (doanh_thu > 300)
    {
        hoa_hong_3 = 0.2 * doanh_thu;
        printf("Hoa hong = %f", hoa_hong_3);
    }

}