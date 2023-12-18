#include<stdio.h>
#include<math.h>
int sum,minus;
int tong(int x, int y)
{
    sum = x +y;
    printf("%d+%d=%d\n",x,y,sum);
    return sum;
}
int hieu(int x, int y)
{
    minus = abs(x- y);
    printf("%d-%d=%d\n",x,y,minus);
    return minus;
}
int main() {
    int a,b,c;
    printf("Nhap a, b, c lan luot:");
    scanf("%d %d %d", &a,&b,&c);
    tong(a,b);
    hieu(a,b);
    tong(a,c);
    hieu(a,c);
    tong(b,c);
    hieu(b,c);

}