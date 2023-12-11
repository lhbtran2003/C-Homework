#include<stdio.h>
int main(){
    float tienGui, lai, soThang;
    printf("So tien gui = ");
    scanf("%f\n",&tienGui);
    printf("Lai ngan hang");
    scanf("%f \n", &lai);
    printf("So thang gui = ");
    scanf("%f \n", &soThang);
    float tienNhanDuoc;
    tienNhanDuoc = tienGui * (1+lai)*(1+lai)*(1+lai);
    printf("Tien nhan duoc =", tienNhanDuoc);
    return 0;

}