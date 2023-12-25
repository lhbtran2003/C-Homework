#include<stdio.h>
#include<stdlib.h>
void swap_y(int** arr, int hang_1, int hang_2, int cot)
{
    for(int i=0; i<cot; i++) {
        int temp = arr[hang_1][i];
        arr[hang_1][i] = arr[hang_2][i];
        arr[hang_2][i] = temp;
    }
}

void swap_x(int** arr, int cot_1, int cot_2, int hang)
{
    for(int i = 0; i < hang; i++) {
        int temp = arr[i][cot_1];
        arr[i][cot_1] = arr[i][cot_2];
        arr[i][cot_2] = temp;
    }
}

void input(int** arr, int y, int x)
{
    printf("Nhap gia tri tung phan tu:\n");
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}


int main() {
    int y, x;
    printf("Nhap so hang:");
    scanf("%d", &y);
    printf("Nhap so cot:");
    scanf("%d", &x);

    int** arr = (int**)malloc(y * sizeof(int*));
    for(int i = 0; i < y; i++) {
        arr[i] = (int*)malloc(x * sizeof(int));
    }

    input(arr, y, x);

    int r1, r2, c1, c2;
    printf("Nhap hai hang can hoan vi: ");
    scanf("%d %d", &r1, &r2);
    swap_y(arr, r1, r2, x);

    printf("Nhap hai cot can hoan vi: ");
    scanf("%d %d", &c1, &c2);
    swap_x(arr, c1, c2, y);

    printf("Mang sau khi hoan vi:\n");
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < y; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

