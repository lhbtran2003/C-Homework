#include<stdio.h>
#include<math.h>
int tich, thuong;
int phep_nhan(int x, int y)
{
    tich = x * y;
    printf("%d * %d = %d", x,y,tich);
    printf("\n");
    return tich;
}
int phep_chia(int x, int y)
{
    if(x > y)
    {
        if(x % y == 0)
        {
            printf("%d / %d = %d\n", x,y, x/y);
        }
        else if(x % y != 0)
        {
            printf("%d khong chia het cho %d\n", x,y);
        }
    }
    else if(y > x)
        if(y % x == 0)
        {
            printf("%d / %d = %d\n", y,x, y/x);
        }
        else if(y % x != 0)
        {
            printf("%d khong chia het cho %d \n", y,x);
        }
        return thuong;
}
int main(){
    int a,b,c;
    printf("Nhap a,b,c lan luot la: ");
    scanf("%d %d %d", &a, &b, &c);
    phep_nhan(a,b);
    phep_chia(a,b);
    phep_nhan(a,c);
    phep_chia(a,c);
    phep_nhan(b,c);
    phep_chia(b,c);
    return 0;
}

