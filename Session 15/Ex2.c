#include<stdio.h>
#include<stdlib.h>
void input(int y, int x);
int main(){
    int y, x;
    input(y, x);




}
void input(int y, int x) {
    int i, j;
    printf("Nhap so hang:");
    scanf("%d", &y);
    printf("Nhap so cot:");
    scanf("%d", &x);
    int *nums;
    //Cấp phát bộ nhớ động và gán vào biến con trỏ
    nums = malloc(sizeof(int) * x * y);
    printf("Nhap gia tri tung phan tu:");
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            scanf("%d", &nums[i * x + j]);
        }
    }
}
void swap_y(int *)