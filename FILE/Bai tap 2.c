#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 200

typedef struct {
    char ten[N];
    char lop[N];
    char ngaysinh[N];
    double gpa;
}sinh_vien;



int cmp(const void *a, const void *b){
    sinh_vien *x = (sinh_vien *)a;
    sinh_vien *y = (sinh_vien *)b;
    if(x->gpa > y->gpa)
        return -1;
    return 1;
}

int main(){
    FILE *fp_in;
    sinh_vien a[1000]; int n = 0;
    fp_in = fopen("sinhvien.txt", "r");
    if(fp_in == NULL){
        printf("File not found !\n");
    }
    else{
        FILE *fp_out;
        fp_out = fopen("sinhvien_out.txt", "w");
        char data[N];
        char email[N];

        while(fgets(data, 200, fp_in) != NULL){
            data[strlen(data) - 1] = '\0';
            int stt = 0;
            char *chinh_sua = strtok(data, ",");
            while(chinh_sua != NULL){
                ++stt; // thu tu
                if(stt == 1){
                    strcpy(a[n].ten, chinh_sua);
                }
                else if(stt == 2){
                    strcpy(a[n].lop, chinh_sua);
                }
                else if(stt == 3){
                    strcpy(a[n].ngaysinh, chinh_sua);
                }
                else{
                    a[n].gpa = atof(chinh_sua);
                }
                chinh_sua = strtok(NULL, ",");
            }
            ++n;
        }

        qsort(a, n, sizeof(sinh_vien), cmp);
        for(int i = 0; i < n; i++){
            fprintf(fp_out, "%s,%s,%s,%.1lf\n", a[i].ten, a[i].lop, a[i].ngaysinh, a[i].gpa);
        }
        fclose(fp_in);
        fclose(fp_out);
    }
    return 0;
}

int search(list &ds, int x){
    for(int i = 0; i<ds.n; i++){
        if(ds.nodes[i]->máo == x) return i;
        return -1;
    }
}