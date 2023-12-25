#include<stdio.h>
#include<stdlib.h>
int main(void){
    int y,x;
    printf("Nhap so hang va so cot cua mang 2 chieu:");
    scanf("%d", &y);
    scanf("%d", &x);

    int *nums2;
    // Cấp phát bộ nhớ động cho 1 mảng gồm y*x phần tử
    //Gán địa chỉ mảng trên vào con trỏ nums2
    nums2 = malloc(sizeof(int) * x * y);
    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
            scanf("%d", &nums2[i * x + j]);
    }
    //Vòng lặp đầu tiên
    //1. i=0, i<3: chạy vòng for bên trong
    //1.2. j=0, j<3: chạy scanf("%d", &nums2[i*x+j]);
    //1.3. nums2[0 * 3 + 0] : nums2[0] : là phần tử thứ 1 của mảng 1 chiều
    //1.4 nums2[0 * 3 +1] : nums2[1] : là phần tử thứ 2 của mảng 1 chiều
    //1.5 nums2[0 * 3 +2] : nums2[2] : là phần tử thứ 3 của mảng 1 chiều
    //1.6 Now j=3, kiểm tra dkien (3<3) là false => thoát khỏi vòng lặp
    // Tăng i lên 1 và bắt đầu vòng lặp thứ 2 của for i
    //2. i = 1, i < 3 (true): chạy vòng for j bên trong
    // lặp lại y chang vòng lặp đầu tiên
    // cho đến khi i<y trả về false thì thoát khỏi vòng lặp for i
}