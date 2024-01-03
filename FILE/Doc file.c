#include<stdio.h>
#define N 256



int main(void){
    // ĐỌC TỪNG KÍ TỰ
//    FILE *fp = NULL;
//    fp = fopen("sample.txt", "r");
////    printf("%c\n", fgetc(fp));
////    printf("%c\n", fgetc(fp));
//     char c;
//     while ((c = fgetc(fp)) != EOF){
//         printf("%c", c);
//     }
//     fclose(fp);

     // ĐỌC TỪNG DÒNG
//     FILE *fp = NULL;
//     char arr[128];
//     fp = fopen("sample.txt", "r");
//     fgets(arr, 128, fp);
//     printf("%s\n", arr);
//     fgets(arr, 4, fp);
//     printf("%s\n", arr);
//    fgets(arr, 4, fp);
//    printf("%s\n", arr);
//    fgets(arr, 4, fp);
//    printf("%s\n", arr);
    // Thấy chưa, muốn đọc 1 dòng phải có 1 thằng fgets và printf nên mệt vl although có thể copy nhưng nhìn dài
    // Nên là, sài WHILE đi cho ló ngắn ok ko bấy bì :))))

//      while(fgets(arr, 4, fp) != NULL){
//          printf("%s",arr);
//      }


    // ĐỌC TỪNG DÒNG THEO ĐỊNH DẠNG
//        FILE *fp = NULL;
//        char name[32] = {0}; //Tên
//        int age = 0;
//        double height = 0;
//        int blood = 0;
//        fopen_s(&fp, "sample.txt", "r");
//        while(fscanf(fp, "%s %d %lfcm %c", name, &age, &height, &blood) != EOF) {
//            printf("%d %3.2lf \n", age, height);
//        }
//        fclose(fp);

        // sscanf
    FILE *fp;
    char fname[] ="sample.txt";
    char line[N];
    char str[16];
    float f1, f2, f3, f4, f5;

    fp = fopen(fname,"r");
    if(fp ==NULL) {
        printf("%s file not open!\n", fname);
        return-1;
    }

    while(fgets(line, N, fp) !=NULL){
        sscanf(line,"%s, %[^, %f, %[^, %f, %[^, %f, %[^, %f, %[^, %f", str, &f1, &f2, &f3, &f4, &f5);
        printf("%s %[^, %.1f, %[^, %.1f, %[^, %.1f, %[^, %.1f, %[^, %.1f\n", str, f1, f2, f3, f4, f5);
    }
    fclose(fp);//Đóng file






    return 0;

}