#include <stdio.h>
#include <string.h>
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
void xoa_sach(book sach[], int *n);
void hien_thi_sach(book sach[], int n);
void sap_xep_tang(book sach[], int n);
void sap_xep_giam(book sach[], int n);
void question(char continueMenu);
void search_book_by_author(book sach[], int *n);
void search_book_by_price(book sach[], int *n);

int main(){
    int chon, n=0;
    char continue_menu;
    book sach[N];
    do{
        printf("\t\t\t ============MENU================================\n");
        printf("\t\t\t |1. Cap nhat thong tin sach (them).                |\n");
        printf("\t\t\t |2. Cap nhat thong tin sach (sua).                 |\n");
        printf("\t\t\t |3. Cap nhat thong tin sach (xoa).                 |\n");
        printf("\t\t\t |4. Hien thi thong tin sach.                       |\n");
        printf("\t\t\t |5. Sap xep sach theo gia (tang dan).              |\n");
        printf("\t\t\t |6. Sap xep sach theo gia (giam dan).              |\n");
        printf("\t\t\t |7. Tim kiem sach theo ten tac gia.                |\n");
        printf("\t\t\t |8. Tim kiem sach theo khoang gia.                 |\n");
        printf("\t\t\t ================================================\n");
        printf("Ban chon: ");
        scanf("%d", &chon);
        switch(chon){
            case 1:
                them_sach(sach, &n);
                question(continue_menu);
                break;
            case 2:
                break;
            case 3:
                xoa_sach(sach, &n);
                question(continue_menu);
                break;
            case 4:
                hien_thi_sach(sach, n);
                question(continue_menu);
                break;
            case 5:
                sap_xep_tang(sach, n);
                question(continue_menu);
                break;
            case 6:
                sap_xep_giam(sach, n);
                question(continue_menu);
                break;
            case 7:
                search_book_by_author(sach, &n);
                question(continue_menu);
                break;
            case 8:
                search_book_by_price(sach, &n);
                question(continue_menu);
                break;
            case 9:
                printf("Dong chuong trinh.");
                break;
            default:
                printf("Khong ton tai muc nay! Moi ban chon lai:");
                break;
        }
    }
    while(chon != 9 || continue_menu == 'y' || continue_menu == 'Y');
    printf("***CHUONG TRINH KET THUC.***");
    return 0;
}

// ==============================================================================================
// GHI DỮ LIỆU VÀO FILE
void ghi_file(book sach[], int n) {
    FILE *fp;
    fp = fopen("book.txt", "w+");
    fprintf(fp, "%-10s %-30s %-20s %-10s %-20s\n", "Ma Sach", "Ten Sach", "Tac Gia", "Gia", "The Loai");

    for(int i = 0; i < n; i++) {
        fprintf(fp, "%-10s %-30s %-20s %-10d %-20s\n",
                sach[i].ma_sach, sach[i].ten_sach, sach[i].tac_gia,
                sach[i].gia, sach[i].the_loai);
    }
    fclose(fp);
}

// ==========================================================================================

void them_sach(book sach[], int *n){
    printf("Nhap vao so luong sach ban muon them:");
    scanf("%d", n);
    getchar();

    for(int i = 0; i < *n; i++){
        printf("** Quyen sach thu %d **\n", i+1);

        printf("Ma sach (5 ki tu):");
        getchar();
        fgets(sach[i].ma_sach, sizeof(sach[i].ma_sach), stdin);
        // Loại bỏ ký tự '\n' thừa trong buffer
        sach[i].ma_sach[strcspn(sach[i].ma_sach, "\n")] = '\0';

        printf("Ten sach:");
        fgets(sach[i].ten_sach, sizeof(sach[i].ten_sach), stdin);
        sach[i].ten_sach[strcspn(sach[i].ten_sach, "\n")] = '\0';

        printf("Ten tac gia:");
        fgets(sach[i].tac_gia, sizeof(sach[i].tac_gia), stdin);
        sach[i].tac_gia[strcspn(sach[i].tac_gia, "\n")] = '\0';

        do {
            printf("Gia:");
            scanf("%d", &sach[i].gia);
            if(sach[i].gia < 1000)
                printf("Gia khong hop le. Vui long nhap lai.");
        }
        while(sach[i].gia < 1000);

        printf("The loai:");
        getchar();
        fgets(sach[i].the_loai, sizeof(sach[i].the_loai), stdin);
        sach[i].the_loai[strcspn(sach[i].the_loai, "\n")] = '\0';
    }
    ghi_file(sach, *n );
    printf("THONG BAO: THEM THANH CONG.");
}

// ==================================================================================================

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
        printf("Da xoa sach co ma %s\n", ID);
        ghi_file(sach, *n);
    }
    else {
        printf("Khong tim thay ma sach da nhap!\n");
    }
    ghi_file(sach, *n);
}


// =================================================================================================

void sua_sach(book sach[], int *n) {
    char search_ID[N];
    printf("Nhap ID muon cap nhap: "); // đây là một chuỗi
    getchar();
    fgets(search_ID, sizeof(search_ID), stdin);
    search_ID[strcspn(search_ID, "\n")] = '\0';

    for (int i = 0; i < *n; i++) {
        if (strcmp(sach[i].ma_sach, search_ID) == 0) { // tìm được mã sách

            printf("Nhap ten sach moi: ");
            fflush(stdin);
            fgets(sach[i].ma_sach, sizeof(sach[i].ma_sach), stdin);
            sach[i].ma_sach[strcspn(sach[i].ma_sach, "\n")] = '\0';

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

            printf("***CAP NHAT THANH CONG.***\n");

            return;
        } else
            printf("Khong tim thay mang co noi dung \"%s\"\n", search_ID);
    }
    ghi_file(sach, *n);
}



// ==================================================================================================

void hien_thi_sach(book sach[], int n) {
//    printf("%-20s%-20s%-20s%-20s%-10s\n", "masach", "Tensach", "tacgia", "theloai", "gia");
    for (int i = 0; i < n; ++i) {
        printf("%-20s%-20s%-20s%-20s%-10d\n",
               sach[i].ma_sach, sach[i].ten_sach, sach[i].tac_gia,
               sach[i].the_loai, sach[i].gia);
    }
}

// =======================================================================================

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

// =========================================================================================

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

// =============================================================================================

void search_book_by_author(book sach[], int *n){
    char author[N];
    printf("Nhap ten tac gia: ");
    getchar();
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';

    int found = 0;
    for(int i = 0; i < n; i++) {
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

// ==============================================================================================

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

// ==============================================================================================

void question(char continueMenu){
    printf("Ban co muon tiep tuc cac thao tac? (Y/N"); // yes/no
    scanf("%c", &continueMenu);
}


