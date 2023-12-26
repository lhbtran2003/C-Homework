#include<stdio.h>
typedef struct {
    char name[50];
    int population;
    double literacyRate;
    int totalIncome;
}state;

void incomeSort (state arr[], int n){
    int maxIncome = 0, i;
    for(i = 0; i < n; i++){
        if(arr[i].totalIncome > arr[maxIncome].totalIncome ){
            maxIncome = i;
        }

    } printf("Thanh pho co tong thu nhap cao nhat la: %s", arr[maxIncome].name);
}

void literacyRateSort(state arr[], int m){
    int maxRate = 0, i;
    for(i = 0; i < m; i++){
        if(arr[i].literacyRate > arr[maxRate].literacyRate){
            maxRate = i;
        }
    } printf("Thanh pho co ti le doc viet cao nhat la: %s\n", arr[maxRate].name);
}

int main() {
    int n, i;
    printf("Nhap so thanh pho:");
    scanf("%d", &n);
    state arr[n];
    for (i = 0; i < n; i++) {
        printf("***Nhap chi tiet thanh pho thu %d\n", i + 1);
        printf("Nhap ten thanh pho:");
        getchar();
        gets(arr[i].name);
        printf("Nhap tong so dan:");
        scanf("%d", &arr[i].population);
        printf("Nhap ti le biet doc viet:");
        scanf("%lf", &arr[i].literacyRate);
        printf("Nhap tong thu nhap:");
        scanf("%d", &arr[i].totalIncome);
        printf("\n");
    }

    incomeSort(arr, n);
    literacyRateSort(arr, n);

    return 0;
}

