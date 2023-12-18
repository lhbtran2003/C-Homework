#include <stdio.h>
#include<math.h>
int convert(long long bin)
{
    int oct = 0; //bat phan
    int dec = 0; //thap phan
    int i = 0;
    while (bin != 0)
    {
        dec += (bin %10) * pow(2, i);
        i++;
        bin /= 10;
    }
    i = 1;
    while (dec != 0)
    {
        oct +=  (dec % 8) * i;
        dec /= 8;
        i *= 10;
    }
    return oct;
}
int main() {
    long long bin;
    printf("Nhap 1 so he nhi phan: ");
    scanf("%lld", &bin);
    printf("%lld trong he nhi phan = %d trong he bat phan", bin, convert(bin));
    return 0;
}


