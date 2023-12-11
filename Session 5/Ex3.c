#include <stdio.h>
int main () {
    int phut;
    int cuocThueBao;
    int cuocDienThoai;
    cuocThueBao = 25000;
    printf("Nhap so phut su dung: ", phut);
    scanf("%d", &phut);
    if (phut <= 50)
    {
        cuocDienThoai = cuocThueBao + phut * 600;
        printf("Gia cuoc dien thoai = %d", cuocDienThoai);
    }
    else if (phut>50&&phut<=200)
    {
        cuocDienThoai = cuocThueBao + (50 * 600) + (phut - 50 ) * 400;
        printf("Gia cuoc dien thoai = %d", cuocDienThoai);
    }
    else if (phut<200&&phut<=400)//sao m non vậy ????????????????
    {
        cuocDienThoai = cuocThueBao + (50 * 600) + (150 * 400) + (phut - 200) * 200;
        printf("Gia cuoc dien thoai = %d ",cuocDienThoai);
    }
    else if ( phut > 400)
    {
        cuocDienThoai = cuocThueBao + (50 * 600) + ( 150 * 400) + (200 * 200) + (phut - 400) * 100;
        printf("Gia cuoc dien thoai = %d", cuocDienThoai);
    }
    return 0;
}