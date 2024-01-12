#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

typedef struct{
    char ma_sach[N];
    char ten_sach[N];
    char tac_gia[N];
    int gia;
    char the_loai[N];
}book;

void ghi_file(book sach[], int n);
void them_sach(book sach[], int *n);
void chuan_hoa_ten_sach(char str[]);
void sua_sach(book sach[], int n);
void xoa_sach(book sach[], int *n);
void hien_thi_sach(book sach[], int n);
void sap_xep_tang(book sach[], int n);
void sap_xep_giam(book sach[], int n);
void question(char *continueMenu);
void search_book_by_author(book sach[], int *n);
void search_book_by_price(book sach[], int *n);
void ghi_file_title();

int main(){
    int chon, n=0;
    char continue_menu = 'y';
    book sach[N];
    ghi_file_title();
    do{
        printf("\t\t\t\t\t\t ===================    MENU     ====================\n");
        printf("\t\t\t\t\t\t |       1. Cap nhat thong tin sach (them).         |\n");
        printf("\t\t\t\t\t\t |       2. Cap nhat thong tin sach (sua).          |\n");
        printf("\t\t\t\t\t\t |       3. Cap nhat thong tin sach (xoa).          |\n");
        printf("\t\t\t\t\t\t |       4. Hien thi thong tin sach.                |\n");
        printf("\t\t\t\t\t\t |       5. Sap xep sach theo gia (tang dan).       |\n");
        printf("\t\t\t\t\t\t |       6. Sap xep sach theo gia (giam dan).       |\n");
        printf("\t\t\t\t\t\t |       7. Tim kiem sach theo ten tac gia.         |\n");
        printf("\t\t\t\t\t\t |       8. Tim kiem sach theo khoang gia.          |\n");
        printf("\t\t\t\t\t\t ====================================================\n");
        printf(">>>>> Ban chon muc nao (1->8): ");
        scanf("%d", &chon);
        getchar();
        switch(chon){
            case 1:
                them_sach(sach, &n);
                question(&continue_menu);
                break;
            case 2:
                sua_sach(sach, n);
                ghi_file(sach,n);
                question(&continue_menu);
                break;
            case 3:
                xoa_sach(sach, &n);
                ghi_file(sach, n);
                question(&continue_menu);
                break;
            case 4:
                hien_thi_sach(sach, n);
                question(&continue_menu);
                break;
            case 5:
                sap_xep_tang(sach, n);
                question(&continue_menu);
                break;
            case 6:
                sap_xep_giam(sach, n);
                question(&continue_menu);
                break;
            case 7:
                search_book_by_author(sach, &n);
                question(&continue_menu);
                break;
            case 8:
                search_book_by_price(sach, &n);
                question(&continue_menu);
                break;
            case 9:
                break;
            default:
                printf("Khong ton tai muc nay! Moi ban chon lai:");
                printf("\n\n");
                break;
        }
    }
    while(chon != 9 && continue_menu == 'y');
    printf("***CHUONG TRINH KET THUC.***");
    return 0;
}

// GHI DỮ LIỆU VÀO FILE
void ghi_file(book sach[], int n) {
    FILE *fp;
    fp = fopen("book.txt", "w");
    if(fp!=NULL) {
        fprintf(fp, "%-10s| %-30s| %-17s| %-10s| %-20s\n", "Ma Sach", "Ten Sach", "Tac Gia", "Gia", "The Loai");
        for (int i = 0; i < n; i++) {
            fprintf(fp, "%-10s| %-30s| %-17s| %-10d| %-20s\n",
                    sach[i].ma_sach, sach[i].ten_sach, sach[i].tac_gia,
                    sach[i].gia, sach[i].the_loai);
        }
        fclose(fp);
    }
    if(fclose(fp) ==0){
        printf(  "Du lieu da duoc them vao tep tin.\n");
    }
}

// CHUẨN HÓA TÊN SÁCH
void chuan_hoa_ten_sach(char str[]) {
    // Chuẩn hóa kí tự đầu của mỗi từ
    for (int i = 0; str[i] != '\0'; i++) {
        // Nếu là kí tự đầu hoặc sau dấu cách
        if (i == 0 || isspace(str[i - 1])) {
            if (isalpha(str[i])) {
                str[i] = toupper(str[i]);
            }
        } else {
            str[i] = tolower(str[i]);
        }
    }
}



// CASE 1
void them_sach(book sach[], int *n){
    int so_sach;
    printf("Nhap vao so luong sach ban muon them:");
    scanf("%d", &so_sach);
    getchar();
    printf("\n");

    for(int i = 0; i < *n+so_sach; i++) {
        printf("** Quyen sach thu %d **\n", i + 1);

        do {
            printf("Ma sach (5 ki tu):");
            fflush(stdin);
            fgets(sach[i].ma_sach, sizeof(sach[i].ma_sach), stdin);
            sach[i].ma_sach[strcspn(sach[i].ma_sach, "\n")] = '\0';
            if (strlen(sach[i].ma_sach) != 5) {
                printf("Ma sach phai co 5 ki tu. Vui long nhap lai.\n");
            }
        } while (strlen(sach[i].ma_sach) != 5);

        printf("Ten sach:");
        fflush(stdin);
        fgets(sach[i].ten_sach, sizeof(sach[i].ten_sach), stdin);
        sach[i].ten_sach[strcspn(sach[i].ten_sach, "\n")] = '\0';
        chuan_hoa_ten_sach(sach[i].ten_sach);

        printf("Ten tac gia:");
        fflush(stdin);
        fgets(sach[i].tac_gia, sizeof(sach[i].tac_gia), stdin);
        sach[i].tac_gia[strcspn(sach[i].tac_gia, "\n")] = '\0';

        do {
            printf("Gia:");
            scanf("%d", &sach[i].gia);
            if (sach[i].gia < 1000)
                printf("Gia khong hop le. Vui long nhap lai.");
        } while (sach[i].gia < 1000);

        printf("The loai:");
        fflush(stdin);
        fgets(sach[i].the_loai, sizeof(sach[i].the_loai), stdin);
        sach[i].the_loai[strcspn(sach[i].the_loai, "\n")] = '\0';
        printf("\n");
    }
    *n += so_sach;

    printf("THONG BAO: THEM THANH CONG. ");
    ghi_file(sach, *n);

}



//CASE 3
void xoa_sach(book sach[], int *n){
    char ID[N];
    printf("Nhap ID sach can xoa:");
    fflush(stdin);
    fgets(ID, sizeof(ID), stdin);
    ID[strcspn(ID, "\n")] = '\0';
    int i;
    for (i = 0; i < *n; i++) {
        if (strcmp(sach[i].ma_sach, ID) == 0) break;
    }
    if (i != *n) {
        for (int j = i; j < *n - 1; j++) {
            sach[j] = sach[j + 1];
        }
        (*n)--;
        printf("THONG BAO: DA XOA SACH CO MA %s\n", ID);
        ghi_file(sach, *n);
    }
    else {
        printf("Khong tim thay ma sach da nhap!\n");
    }
    ghi_file(sach, *n);
}


//CASE 2
void sua_sach(book sach[], int n) {
    char search_ID[N];
    printf("Nhap ID muon cap nhap: ");
    fflush(stdin);
    fgets(search_ID, sizeof(search_ID), stdin);
    search_ID[strcspn(search_ID, "\n")] = '\0'; //loại bỏ kí tu newline "\n"


    for (int i = 0; i < n; i++) {
        if (strcmp(sach[i].ma_sach, search_ID) == 0) {
            printf("Nhap ten sach moi: ");
            fflush(stdin);
            fgets(sach[i].ten_sach, sizeof(sach[i].ten_sach), stdin);
            sach[i].ten_sach[strcspn(sach[i].ten_sach, "\n")] = '\0';
            chuan_hoa_ten_sach(sach[i].ten_sach);

            printf("Nhap ten tac gia: ");
            fflush(stdin);
            fgets(sach[i].tac_gia, sizeof(sach[i].tac_gia), stdin);
            sach[i].tac_gia[strcspn(sach[i].tac_gia, "\n")] = '\0';

            printf("Gia sach moi: ");
            scanf("%d", &sach[i].gia);

            printf("The loai: ");
            fflush(stdin);
            fgets(sach[i].the_loai, sizeof(sach[i].the_loai), stdin);
            sach[i].the_loai[strcspn(sach[i].the_loai, "\n")] = '\0';

            printf("***UPDATE SUCCESSFULLY.***\n");
            return;
        }
    }
    printf("Khong tim thay ma sach nay \n");
//    ghi_file(sach, n);
}



//CASE 4
void hien_thi_sach(book sach[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%-10s| %-30s| %-17s| %-10s| %-20d\n",
               sach[i].ma_sach, sach[i].ten_sach, sach[i].tac_gia,
               sach[i].the_loai, sach[i].gia);
    }
}


//CASE 5
void sap_xep_tang(book sach[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (sach[j].gia > sach[j+1].gia) {
                book temp = sach[j];
                sach[j] = sach[j+1];
                sach[j+1] = temp;
            }
        }
    }
    hien_thi_sach(sach, n);
}


//CASE 6
void sap_xep_giam(book sach[], int n){
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (sach[j].gia < sach[j+1].gia) {
                book temp = sach[j];
                sach[j] = sach[j+1];
                sach[j+1] = temp;
            }
        }
    }
    hien_thi_sach(sach, n);
}

//CASE 7
void search_book_by_author(book sach[], int *n){
    char author[N];
    printf("Nhap ten tac gia: ");
    getchar();
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';

    int found = 0;

    for(int i = 0; i < *n; i++) {
        if (strcmp (sach[i].tac_gia, author ) == 0) {
            printf("Ma sach: %s\n", sach[i].ma_sach);
            printf("Ten sach: %s\n", sach[i].ten_sach);
            printf("Tac gia: %s\n", sach[i].tac_gia);
            found = 1;
        }
    }
    if (!found){
        printf("Khong tim thay sach cua tac gia nay!");
    }
}

//CASE 8
void search_book_by_price(book sach[], int *n){
    int min_price, max_price;
    printf("Gia thap nhat (>= 1000): ");
    scanf("%d", &min_price);
    printf("Gia cao nhat: ");
    scanf("%d", &max_price);

    int found = 0;

    for (int i = 0; i < *n; i++) {
        if (min_price <= sach[i].gia && sach[i].gia <= max_price ){
            printf("| %-10s | %-18s | %-13s | %-13.2f | %-13s |\n",
                   sach[i].ma_sach, sach[i].ten_sach, sach[i].tac_gia,
                   sach[i].gia, sach[i].the_loai);
            found= 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sach trong khoang gia nay");
    }
}


void question(char *continueMenu) {
    printf("Ban co muon tiep tuc cac thao tac? (y/n): ");
    // nhập y nếu muốn tiếp tục sử dụng menu, n nếu muốn kết thúc chương trình
    scanf("%c", continueMenu);
    printf("\n\n");
}

void ghi_file_title() {
    FILE *fp;
    fp = fopen("book.txt", "a");

    if (fp == NULL) {
        printf("Khong the mo file.\n");
        return;
    }

    fprintf(fp, "%-10s| %-30s| %-17s| %-10s| %-20s\n", "Ma Sach", "Ten Sach", "Tac Gia", "Gia", "The Loai");

    fclose(fp);
}

