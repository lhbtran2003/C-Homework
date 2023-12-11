#include<stdio.h>
int main() {
    for(int i= 100; i<=999; i++)
    {
        int tram, chuc, donVi;
        tram = i/100;
        chuc = (i%100)/10;
        donVi = i%10;
        while((tram*tram*tram)+(chuc*chuc*chuc)+(donVi*donVi*donVi) == i )
        {
            printf("%d", i);
        }
    }
    return 0;
}