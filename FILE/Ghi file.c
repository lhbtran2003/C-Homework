#include<stdio.h>
#include "stdlib.h"
int main() {
    FILE *fp;
    fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("Loi mo file!");
        exit(1);
    }

        int n;
        printf("Nhap n:");
        scanf("%d", &n);
        fprintf(fp, "%d", n);
    fclose(fp);

}
