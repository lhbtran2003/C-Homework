#include<stdio.h>
#include<string.h>
int main(){
    char str1[100], *p1;
    p1 = str1;
    char str2[100], *p2;
    p2 = str2;
    printf("Nhap do dai chuoi 1:");
    gets(p1);
    printf("Do dai chuoi 1 la: %d\n", strlen(p1));
    printf("Nhap do dai chuoi 2:");
    gets(p2);
    printf("Do dai chuoi 2 la: %d\n", strlen(p2));
    if(strlen(p1) > strlen(p2))
        printf("Chuoi co do dai lon hon la: %s", p1);
    else if(strlen(p2) > strlen(p1))
        printf("CHuoi co do dai lon hon la: %s", p2);
    return 0;
}