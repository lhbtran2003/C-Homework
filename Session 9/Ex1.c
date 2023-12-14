#include<stdio.h>
int a[100];
int n,sum;
int main(){
    printf("Ban hay chon 1 trong 3 muc duoi day\n");
    printf("1.Nhap so phan tu can nhap va gia tri cac phan tu\n");
    printf("2.In ra gia tri cac phan tu dang quan li\n");
    printf("3.In ra gia tri cac phan tu chan va tinh tong\n");
    while(1)
    {
        int chuc_nang;
        printf("Muc ban chon la: ");
        scanf("%d", &chuc_nang);
        switch (chuc_nang)
        {
            case 1:
                printf("Nhap so phan tu can nhap: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++)
                {
                    printf("Nhap gia tri phan tu thu %d: ", i);
                    scanf("%d", &a[i]); // đã lưu gtri vào mảng, khi chạy tiếp case 2 sẽ lấy gtri từ đây
                }
                break;
            case 2:
                if (n == 0)
                {
                    printf("Khong co gia tri nao\n");
                } else
                {
                    printf("Gia tri cac phan tu dang quan ly:\n");
                    for (int i = 0; i < n; i++)
                    {
                        printf("%d\n",a[i]);
                    }
                }
                break;
            case 3:
                sum = 0;
                for (int i = 0; i < n; i++) {
                    if (a[i] % 2 == 0) {
                        printf("So chan: %d\n ", a[i]);
                        sum += a[i];
                    }
                }
                printf("Tong so chan: %d\n ", sum);
                break;
            default:
                printf("Khong co muc nay trong menu!");
                printf("\n");
                break;
        }
    }
    return 0;
}