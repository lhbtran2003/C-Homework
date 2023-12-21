#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int chuc_nang;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi ki tu\n");
        printf("2. In ra độ dài chuỗi và nội dung chuỗi vừa nhập\n");
        printf("3. In ra chuoi đao nguoc\n");
        printf("4. In ra so luong chu cai trong chuoi\n");
        printf("5. In ra so luong chu so trong chuoi\n");
        printf("6. In ra so luong ky tu đac biet trong chuoi\n");
        printf("7. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chuc_nang);
        getchar();

        switch(chuc_nang)
        {
            case 1:
                printf("Nhap vao chuoi ki tu: ");
                fgets(str, sizeof(str), stdin);
                str[strlen(str) - 1] = '\0';  // Loai bo dong moi o cuoi
                break;
            case 2:
                printf("Đo dai chuoi: %lu\n", strlen(str));
                printf("Noi dung chuoi: %s\n", str);
                break;
            case 3:
                printf("Chuoi đao nguoc: ");
                for(int i = strlen(str) - 1; i >= 0; i--)
                {
                    printf("%c", str[i]);
                }
                printf("\n");
                break;
            case 4:
            {
                int count = 0;
                for(int i = 0; i < strlen(str); i++)
                {
                    if(isalpha((unsigned char)str[i]))
                        count++;
                }
                printf("So luong chu cai trong chuoi: %d\n", count);
            }
                break;
            case 5:
            {
                int count = 0;
                for(int i = 0; i < strlen(str); i++)
                {
                    if(isdigit((unsigned char)str[i]))
                        count++;
                }
                printf("So luong chu so trong chuoi: %d\n", count);
            }
                break;
            case 6:
            {
                int count = 0;
                for(int i = 0; i < strlen(str); i++)
                {
                    if(!isalnum((unsigned char)str[i]) && !isspace((unsigned char)str[i]))
                        count++;
                }
                printf("So lưuong ki tu đac biet trong chuoi: %d\n", count);
            }
                break;
            case 7:
                printf("Thoat.\n");
                break;
            default:
                printf("Khong co lua chon nay!\n");
        }
    } while(chuc_nang != 7);

    return 0;
}
