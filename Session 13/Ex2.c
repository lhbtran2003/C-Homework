#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char ch;
    int chuc_nang;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi ki tu\n");
        printf("2. In ra noi dung chuoi\n");
        printf("3. Nhap vao 1 ki tu, đem so lan xuat hien ki tu trong chuoi\n");
        printf("4. Nhap vao 2 ki tu, thay the cac ki tu thu 2 trong chuoi thanh ki tu thu nhat\n");
        printf("5. Nhap vao 1 ki tu, xoa bo cac ki tu trong chuoi\n");
        printf("6. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &chuc_nang);
        getchar();  // To consume the newline character after number input

        switch(chuc_nang)
        {
            case 1:
                printf("Nhap vao chuoi ki tu: ");
                fgets(str, sizeof(str), stdin);
                str[strlen(str) - 1] = '\0';
                break;
            case 2:
                printf("Noi dung chuoi: %s\n", str);
                break;
            case 3:
            {
                printf("Nhap vao 1 ki tu: ");
                scanf("%c", &ch);
                getchar();
                int count = 0;
                for(int i = 0; i < strlen(str); i++)
                {
                    if(str[i] == ch)
                        count++;
                }
                printf("So lan xuat hien caa ki tu '%c' trong chuoi: %d\n", ch, count);
            }
                break;
            case 4:
            {
                char thay_the, kitu_moi;
                printf("Nhap vao ki tự can thay the: ");
                scanf("%c", &thay_the);
                getchar();
                printf("Nhap vao ki tu moi: ");
                scanf("%c", &kitu_moi);
                getchar();
                for(int i = 0; i < strlen(str); i++)
                {
                    if(str[i] == thay_the)
                        str[i] = kitu_moi;
                }
                printf("Chuoi sau khi thay the: %s\n", str);
            }
                break;
            case 5:
            {
                printf("Nhap vao ki tu can xoa: ");
                scanf("%c", &ch);
                getchar();
                int j = 0;
                for(int i = 0; i < strlen(str); i++)
                {
                    if(str[i] != ch)
                        str[j++] = str[i];
                }
                str[j] = '\0';  // ket thuc chuoi
                printf("Chuoi sau khi xoa: %s\n", str);
            }
                break;
            case 6:
                printf("Thoat.\n");
                break;
            default:
                printf("Khong co lua chon nay.\n");
        }
    } while(chuc_nang != 6);

    return 0;
}
