#include <stdio.h>
int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: \n");
    scanf("%d", &n);
    int a[n];
    {
        for(int i=0; i<n; i++)
        {
            printf("Gia tri phan tu %d: ",i+1);
            scanf("%d", &a[i]);
        }
    }
    int sum=0;
    int *ptr;
    ptr = a; //gan dia chi con tro = dia chi cua phan tu dau tien cua mang
    //duyet qua cac phan tu cua mang va tinh tong
    for (int i=0; i<n; i++)
    {
        sum += *ptr;
        *ptr ++; //tang con tro len 1 don vi de tro toi ptu tiep theo
    }
    printf("Tong gia tri = %d", sum);
    return 0;

}


