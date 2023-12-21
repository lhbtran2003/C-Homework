#include<stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-1; j++)
        {
            if (a[j] < a[j+1])
            swap(&a[j], &a[j+1]);
        }
}
void array_after(int a[], int size)
{
    for (int i=0; i<size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
//void chenSo(int a[], int *n, int key)
//{
//    int i;
//    if (key > a[0])
//    {
//        for (i = *n - 1; i >=0; i--)
//        {
//            a[i+1] = a[i];
//        }
//        a[0] = key;
//    }else
//    {
//        for(i=1; i<*n; i++)
//        {
//            if (a[i] >= key && a[i-1] < key)
//                break;
//        }
//        for(int j = *n-1; j >= i; j--)
//        {
//            a[j+1] = a[j];
//        }
//        a[i] = key;
//    }
//    (*n)++;
//}

void chen(int arr[], int size)
{
    int m;
    printf("Enter m: ");
    scanf("%d", &m);
    arr[size] = m;
}
int main(){
    int a[100];
    int n;
    printf("MENU:\n");
    printf("1. Nhap gia tri n phan tu cua mang.\n");
    printf("2. In gia tri cac phan tu trong mang.\n");
    printf("3. Tinh trung binh cac phan tu duong trong mang.\n");
    printf("4. In ra vi tri cac phan tu co gia tri bang k (k nhap tu ban phim) trong mang.\n");
    printf("5. Su dung thuat toan sap xep noi bot sap xep mang giam dan.\n");
    printf("6. Tinh so luong cac phan tu la so nguyen to trong mang.\n");
    printf("7. Sap xep cac phan tu chan chia het cho 3 ...\n");
    printf("8. Nhap gia tri m tu ban phim, chen gia tri m vao mang (sap xeo giam dan) dung vi tri.\n");
    printf("9. Thoat.\n");
    int chuc_nang;

    while (1)
    {
        int chuc_nang, total, bienDem, k, count, j, b, found, m ;
        float trungBinhCong;
        printf("Muc ban chon la:");
        scanf("%d", &chuc_nang);
        switch(chuc_nang)
        {
            case 1:
                printf("Gia tri n phan tu cua mang la:");
                scanf("%d", &n);
                break;
            case 2:
                for(int i=0; i<n; i++)
                {
                    printf("Nhap gia tri phan tu thu %d:", i+1);
                    scanf("%d", &a[i]);
                }
                printf("\nGia tri cac phan tu trong mang la:\n");
                for(int i=0; i<n; i++)
                {
                    printf("%d\n", a[i]);
                }
                break;
            case 3:
                total = 0;
                bienDem = 0;
                 for(int i=0; i<n; i++)
                {
                    if (a[i] > 0)
                    {
                        total += a[i];
                        bienDem++;
                    }
                }
                if (bienDem > 0)
                {
                    trungBinhCong = (float)total / bienDem;
                    printf("Trung binh cac phan tu duong trong mang = %f\n", trungBinhCong);
                }else
                    printf("Khong co phan tu duong nao trong mang.\n");
                break;
            case 4:
                printf("Nhap gia tri k:");
                scanf("%d", &k);
                found = 0;
                for(int i=0; i<n; i++)
                {
                    if(a[i] == k)
                    {
                        printf("Cac vi tri co gia tri = %d la: %d\n", k, i);
                        found++;
                    }
                }
                if(!found)
                    printf("Khong co vi tri nao!\n");
                break;
            case 5:
                bubbleSort(a, n);
                printf("Mang sau khi duoc sap xep theo thu tu giam dan: \n");
                array_after(a, n);
                break;
            case 6:
                count = 0;
                printf("Danh sach cac so nguyen to la: ");
                for (int i=0; i<n; i++)
                {
                    j = 2;
                    b = 1;
                    while (j < a[i])
                    {
                        if(a[i] % j == 0)
                            b = 0;
                        break;
                        j++;
                    }
                    if(b == 1)
                    {
                        count = count + 1;
                        printf("%d ", a[i]);
                    }
                }
                printf("\nSo luong so nguyen to trong mang la: %d\n", count);
                break;
            case 8:
                printf("Nhap gia tri cua m:");
                scanf("%d", &m);
                chenSo(a, &n, m);

                printf("Mang sau khi duoc chen gia tri m: ");
                for(int i=0; i<n; i++)
                {
                    printf("%d ", a[i]);
                }printf("\n");
                break;
            case 9:
                return 0;
            default: printf("Thoat");
        }
    }while (chuc_nang!=9);
return 0;
}