/* ĐỐI VỚI MẢNG 1 CHIỀU
#include <stdio.h>
#include<stdlib.h>
int values[] =
        { 88,56,200,2,25,101,4,6,10,18};
int cmpfunc(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
int main() {
    int n;
    printf("Truoc khi sap xep, list co dang: \n");
    for (n = 0; n < 9; n++) {
        printf("%d ", values[n]);
    }
    qsort(values, 9, sizeof(int), cmpfunc);

    printf("\nSau khi sap xep, list co dang: \n");
    for (n = 0; n < 9; n++) {
        printf("%d ", values[n]);
    }
    return ;
} 8 */




//S2 DOI VS MANG 2 CHIEU
#include <stdio.h>
#include <stdlib.h>
int values[]= {7,10, 20, 0, 5, 20, 2};
int cmp(const void *a, const void *b){
    int *x=(int*)a;
    int *y=(int*)b;
    return *x-*y;
}
int main(){
    printf("===Moi ban nhap vao mang 2 chieu===\n");
    int x, y;
    printf("Gia tri x cua mang 2 chieu: ");
    scanf("%d", &x);
    printf("Gia tri y cua mang 2 chieu: ");
    scanf("%d", &y);
    int a[y][x];
    for (int i=0; i<y; i++){
        for (int j=0; j<x; j++) {
            printf("Nhap vao gia tri cua phan tu theo cot %d hang %d :    ", i, j);
            scanf("%d \n", &a[i][j]);
        }
    }
    printf("\n mang truoc khi sap xep\n");
    for (int i=0; i<y; i++){
        for(int j=0; j<x; j++)
            printf("%d", a[i][j]);
    }
    for (int i=0; i<y; i++){
        qsort(a[i], x, sizeof(int), cmp);
    }
    printf("\n Mang 2 chieu sau khi sap xep\n");
    for (int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
