#include<stdio.h>
int main(){
    int n, soDaoNguoc = 0, temp, soBanDau;
    printf("Nhap 1 so nguyen: ");
    scanf("%d", &n);
    soBanDau = n;
    while (n != 0)
    {
        temp = n % 10;
        soDaoNguoc = soDaoNguoc * 10 + temp;
        n /= 10;
    }
    if(soBanDau = soDaoNguoc)
        printf("True\n");
    else
        printf("False\n");
    return 0;

}