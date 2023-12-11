#include<stdio.h>
int main()
{
    double luongNhanVien;
    printf("luong nhan vien (trieu): ");
    scanf("%lf",&luongNhanVien);
    if (luongNhanVien <= 5)
    {
        printf("luong rong cua nhan vien: %.2lf", (0.95)*luongNhanVien);
    }else if (luongNhanVien >= 5 && luongNhanVien <= 10)
    {
        printf("luong rong cua nhan vien: %.2lf",(0.9)*luongNhanVien);
    }else if (luongNhanVien >= 10 && luongNhanVien <= 18)
    {
        printf("luong rong cua nhan vien: %.2lf",(0.85)*luongNhanVien);
    }else if(luongNhanVien >= 18 && luongNhanVien <= 32)
    {
        printf("luong rong cua nhan vien: %.2lf",(0.8)*luongNhanVien);
    }else if(luongNhanVien >= 32 && luongNhanVien <= 52)
    {
        printf("luong rong cua nhan vien: %.2lf", (0.75) * luongNhanVien);
    }else if(luongNhanVien >= 52 && luongNhanVien <= 80)
    {
        printf("luong rong cua nhan vien: %.2lf", (0.7) * luongNhanVien);
    }else if(luongNhanVien >= 80)
    {
        printf("luong rong cua nhan vien: %.2lf", (0.65) * luongNhanVien);
    }
    return 0;
}
// luong rong <=> lương thực lĩnh của nhân viên