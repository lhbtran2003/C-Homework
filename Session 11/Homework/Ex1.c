#include<stdio.h>
int a[100];
int m,n,temp,j,min;
void menu()
{
    printf("1. In gia tri cac phan tu cua mang");
    printf("2. Su dung Insertion Sort sap xep mang giam dan và in ra");
    printf("3. Su dung Selection Sort sap xep mang tang dan va in ra");
    printf("4. Su dung Bubble Sort sap xep mang giam dan va in ra");
    printf("5. Thoat");
}

void output()
{
    printf("phan tu trong mang la: ");
    for(int i=0;i<m;i++)
    {
        printf("%d",a[i]);
    }
}

void insertionSort()
{
    for (int i=1;i<m;i++)
    {
        j=i-1;
        temp=a[i];
        while(temp>a[j]&&j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}


void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *b = *a;
    *b = temp;
};
void selectionSort()
{
    for(int i = 0; i < n-1; i++)
    {
        // Dung 1 bien de luu chi so cua ptu nho nhat
        int min_pos = i;
        // Duyent tat ca cac phan tu dung sau
        for(int j = i+1; j < n; j++)
        {
            if(a[j] < a[min_pos])
                min_pos = j;
        }
        swap(&a[i], &a[min_pos]);
    }
}

void bubbleSort()
{
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            if(a[i]>a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
    }
    for(int i=m-1;i>=0;i--)
    {
        printf("%d\n",a[i]);
    }
}

int main()
{   // Bước khởi đầu
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        printf("nhap phan tu thu %d: ",i);
        scanf("%d",&a[i]);
    }

    int choice;
    do {
        menu();
        printf("choose: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                output();
                break;
            case 2:
                insertionSort();
                output();
                break;
            case 3:
                selectionSort();
                output();
                break;
            case 4:
                bubbleSort();
                break;
            case 5:
                return 0;
            default: printf("nhap sai lenh roi be");
        }

    }while (choice!=5);
}