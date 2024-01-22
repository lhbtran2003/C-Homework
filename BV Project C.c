
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max_length 100
#define FILE_NAME "book.txt"

typedef struct {
    char maSach[6];
    char tenSach[max_length];
    char tacGia[max_length];
    char theLoai[max_length];
    int gia;
} sach;

void menu();
void kyTu(char *name);
void themSach(sach s[], int *n);  // case 1
void inDanhSach(sach s[], int n); // case 4
void luuDuLieu(sach s[], int n);
void capNhat(sach s[], int n);   // case 2
void xoa(sach s[], int *n);      // case 3
void sapXepGiaTang(sach s[], int n);   // case 5
void sapXepGiaGiam(sach s[], int n);   // case 6
void timSachTheoTenTacGia(sach s[], int n);    // case 7
void timSachTheoKhoangGia(sach s[], int n);   // case 8
void xoaDuLieu();          // case 9

int main() {
    int n = 0;
    sach s[max_length];
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp != NULL) {
        while (fscanf(fp, "%s %[^$] %[^$] %d %s\n", s[n].maSach, s[n].tenSach, s[n].tacGia, &s[n].gia, s[n].theLoai) == 5) {
            n++;
        }
        fclose(fp);
    }

    int choice;
    do {
        menu();
        printf("Vui long chon cac chuc nang tu 1 - 8: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                themSach(s, &n);
                luuDuLieu(s, n);
                break;
            case 2:
                capNhat(s, n);
                luuDuLieu(s, n);
                break;
            case 3:
                xoa(s, &n);
                luuDuLieu(s, n);
                break;
            case 4:
                inDanhSach(s, n);
                break;
            case 5:
                sapXepGiaTang(s, n);
                break;
            case 6:
                sapXepGiaGiam(s, n);
                break;
            case 7:
                timSachTheoTenTacGia(s, n);
                break;
            case 8:
                timSachTheoKhoangGia(s, n);
                break;
            case 9:
                xoaDuLieu();
                break;
            case 10:
                printf("Da thoat khoi chuong trinh!\n");
                break;
            default:
                printf("Chuc nang chon khong hop le. Vui long chon lai cac chuc nang tu 1 - 8\n");
        }
    } while (choice != 10);

    return 0;
}

void menu() {
    printf("CHUONG TRINH QUAN LY SACH C/C++\n");
    printf("*************************MENU**************************\n");
    printf("**  1. Them sach.                                    **\n");
    printf("**  2. Cap nhat thong tin sach bang ma sach.         **\n");
    printf("**  3. Xoa sach boi ma sach.                         **\n");
    printf("**  4. Hien thi thong tin sach.                      **\n");
    printf("**  5. Sap xep sach theo gia tang dan.               **\n");
    printf("**  6. Sap xep sach theo gia giam dan.               **\n");
    printf("**  7. Tim kiem sach theo ten tac gia.               **\n");
    printf("**  8. Tim kiem sach theo khoang gia.                **\n");
    printf("**  9. Xoa du lieu.                                  **\n");
    printf("**  10. Thoat.                                       **\n");
    printf("*******************************************************\n");
}

void kyTu(char *str) {         // viết hoa chữ đầu tiên
    for (int i = 0; str[i] != '\0'; i++){
        if (i == 0 || (i > 0 && str[i - 1] == ' ')) {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

void luuDuLieu(sach s[], int n) {  //luu dữ liệu từ mảng s vào file book.txt
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp != NULL) {
        fprintf(fp, "%-10s %-30s %-20s %-20s %-10s\n", "Ma sach", "Ten sach", "Tac gia", "The loai", "Gia tien");
        for (int i = 0; i < n; i++) {
            fprintf(fp, "%-10s %-30s %-20s %-20s %-10d\n",
                    s[i].maSach,
                    s[i].tenSach,
                    s[i].tacGia,
                    s[i].theLoai,
                    s[i].gia);
        }
        fclose(fp);
        printf("Da ghi du lieu vao file thanh cong!\n");
    } else {
        printf("Khong the mo file de ghi du lieu.\n");
    }
}

void themSach(sach s[], int *n) {   //Nhập thông tin và luu vào mảng s
    int a;
    printf("Nhap so luong sach can them: ");
    scanf("%d", &a);

    for (int i = *n; i < *n + a; i++) {
        printf("\nNhap thong tin quyen sach thu %d\n", i + 1);
        printf("Nhap ma sach (5 ky tu): ");
        scanf("%s", s[i].maSach);

        while (strlen(s[i].maSach) != 5) {
            printf("\nMa sach khong dung. Vui long nhap lai: ");
            scanf("%s", s[i].maSach);
        }

        printf("\nNhap ten sach (tu 10 ky tu tro len): ");
        fflush(stdin);
        fgets(s[i].tenSach, max_length, stdin);
        s[i].tenSach[strcspn(s[i].tenSach, "\n")] = 0;

        while (strlen(s[i].tenSach) < 10) {
            printf("Ten sach khong dung dinh dang. Vui long nhap lai: ");
            fflush(stdin);
            fgets(s[i].tenSach, max_length, stdin);
            s[i].tenSach[strcspn(s[i].tenSach, "\n")] = 0;
        }

        kyTu(s[i].tenSach);

        printf("Nhap ten tac gia: ");
        fflush(stdin);
        fgets(s[i].tacGia, max_length, stdin);
        s[i].tacGia[strcspn(s[i].tacGia, "\n")] = 0;

        printf("Nhap the loai sach: ");
        fflush(stdin);
        fgets(s[i].theLoai, max_length, stdin);
        s[i].theLoai[strcspn(s[i].theLoai, "\n")] = 0;

        printf("Nhap gia tien (>=1000): ");
        scanf("%d", &s[i].gia);

        while (s[i].gia < 1000) {
            printf("\nGia sach khong hop le. Vui long nhap lai: ");
            scanf("%d", &s[i].gia);
        }
    }

    *n += a;
    luuDuLieu(s, *n);
}

void inDanhSach(sach s[], int n) {    // hiển thị thông tin trong mảng s ra terminal
    printf("\nDanh sach cac quyen sach:\n");
    printf("%-10s %-20s %-20s %-20s %-10s\n", "Ma sach", "Ten sach", "Tac gia", "The loai", "Gia tien");
    for (int i = 0; i < n; i++) {
        printf("%-10s %-20s %-20s %-20s %-10d\n", s[i].maSach, s[i].tenSach, s[i].tacGia, s[i].theLoai, s[i].gia);
    }
    luuDuLieu(s, n);
}

void capNhat(sach s[], int n) {  // cập nhật thông tin sách dựa vào mã
    char id[6];
    printf("Nhap ma sach muon sua: ");
    fflush(stdin);
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(s[i].maSach, id) == 0) {
            printf("Nhap thong tin sach moi\n");

            printf("Nhap ten sach: ");
            fflush(stdin);
            fgets(s[i].tenSach, sizeof(s[i].tenSach), stdin);
            s[i].tenSach[strcspn(s[i].tenSach, "\n")] = '\0';

            printf("Nhap ten tac gia: ");
            fflush(stdin);
            fgets(s[i].tacGia, sizeof(s[i].tacGia), stdin);
            s[i].tacGia[strcspn(s[i].tacGia, "\n")] = '\0';

            printf("Nhap the loai: ");
            fflush(stdin);
            fgets(s[i].theLoai, sizeof(s[i].theLoai), stdin);
            s[i].theLoai[strcspn(s[i].theLoai, "\n")] = '\0';

            printf("Nhap gia sach: ");
            scanf("%d", &s[i].gia);

            printf("Cap nhat thong tin sach thanh cong\n");
            return;
        }
    }

    printf("Khong tim thay sach\n");
}

void xoa(sach s[], int *n) {  // xóa sách dựa vào mã
    char id[6];
    printf("Nhap ma sach muon xoa: ");
    fflush(stdin);
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    int i;
    for (i = 0; i < *n; i++) {
        if (strcmp(s[i].maSach, id) == 0) {
            break;
        }
    }

    if (i != *n) {
        for (int j = i; j < *n - 1; j++) {
            s[j] = s[j + 1];
        }

        (*n)--;
        printf("Sach da duoc xoa\n");
    } else {
        printf("Khong tim thay sach %s\n", id);
    }

    luuDuLieu(s, *n);
}

void sapXepGiaTang(sach s[], int n) {   // sắp xếp giá tiền tăng dần
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].gia > s[j].gia) {
                sach temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    inDanhSach(s, n);
    printf("Danh sach da duoc sap xep theo gia tien tang dan\n");
}

void sapXepGiaGiam(sach s[], int n) {  // sắp xếp giá giảm dần
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].gia < s[j].gia) {
                sach temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    inDanhSach(s, n);
    printf("Danh sach da duoc sap xep theo gia tien giam dan\n");
}

void timSachTheoTenTacGia(sach s[], int n) {  // tìm kiếm sách bằng tên tác giả
    char tg[max_length];
    printf("Nhap ten tac gia muon tim: ");
    scanf(" %[^\n]", tg);

    int found = 0;
    printf("\nKet qua tim kiem theo tac gia < %s >:\n", tg);
    printf("%-10s %-20s %-20s %-20s %-10s\n", "Ma sach", "Ten sach", "Tac gia", "The loai", "Gia tien");
    for (int i = 0; i < n; i++) {
        if (strstr(s[i].tacGia, tg) != NULL) {
            printf("%-10s | %-20s | %-20s | %-20s | %-10d\n", s[i].maSach, s[i].tenSach, s[i].tacGia, s[i].theLoai, s[i].gia);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach cua tac gia '%s'\n", tg);
    }
}

void timSachTheoKhoangGia(sach s[], int n) {  // tìm sách trong khoảng giá a-b
    int giaLonNhat, giaNhoNhat;
    printf("Nhap gia nho nhat: ");
    scanf("%d", &giaNhoNhat);

    printf("Nhap gia lon nhat: ");
    scanf("%d", &giaLonNhat);

    int found = 0;
    printf("\nSach trong khoang gia %d - %d:\n", giaNhoNhat, giaLonNhat);
    printf("%-10s %-20s %-20s %-20s\n", "STT", "Ten sach", "Tac gia", "Gia tien");

    for (int i = 0; i < n; i++) {
        if (s[i].gia >= giaNhoNhat && s[i].gia <= giaLonNhat) {
            printf("%-10d %-20s %-20s %-20d\n", i + 1, s[i].tenSach, s[i].tacGia, s[i].gia);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach nao trong khoang gia nay!\n");
    }
}

void xoaDuLieu(){  // xóa dữ liệu trong file book.txt
    FILE *file = fopen("book.txt", "w");

    if (file != NULL) {
        fclose(file);
        printf("Da xoa du lieu trong file book.txt.\n");
    } else {
        printf("Khong the mo file de xoa du lieu.\n");
    }
}