#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    char *ptr = str;
    int i = 0;
    printf("Nhap chuoi:\n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;// strcspn: dùng để không đếm xuống dòng khi in ra kết quả
    while(*ptr != '\0')
    {
        ptr++;
        i++;
    }
    printf("Do dai cua chuoi la: %d\n", i);
    return 0;
}