#include<stdio.h>
int main() {
    int thousandDigit, hundredDigit, dozenDigit, unitDigit, n, sum;
    printf("Enter n: ");
    scanf("%d", &n);
    unitDigit = n % 10 ;
    dozenDigit = (n / 10) % 10;
    hundredDigit = (n / 100) % 10;
    thousandDigit = n / 1000;
    sum = unitDigit + thousandDigit + dozenDigit + hundredDigit;
    printf("Tinh tong cac chu so: %d \n", sum);
    printf("Dao nguoc: %d%d%d%d", unitDigit, dozenDigit, hundredDigit, thousandDigit);
}