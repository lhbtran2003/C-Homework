#include <stdio.h>
int main() {
    int diemToan, diemVan, diemAnh, tongDiem, diemTrungBinh;
    printf("Nhap diem 3 mon theo thu tu toan, van, anh: ", diemToan, diemVan, diemAnh);
    scanf("%d  %d  %d", &diemToan, &diemVan, &diemAnh);
    tongDiem = diemToan + diemAnh + diemVan;
    diemTrungBinh = (diemVan + diemToan + diemAnh) / 3;
    printf("Tong diem = %d\n", tongDiem);
    printf("Diem trung binh = %d", diemTrungBinh);


}
