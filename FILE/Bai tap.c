#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

int main() {
    FILE *fp_in, *fp_out;
    char fname_in[] = "sinhvien";
    char fname_out[] = "sinhvien_out";
    char line[N];
    char name[N];
    char *word;
    int n;

    fp_in = fopen("sinhvien.txt", "r");
    if (fp_in == NULL) {
        printf("%s file not open!\n", fname_in);
        return -1;
    }

    fp_out = fopen("sinhvien_out.txt", "w");
    if (fp_out == NULL) {
        printf("%s file not open!\n", fname_out);
        return -1;
    }

    fgets(line, N, fp_in);
    sscanf(line, "%d", &n);
    sprintf(line, "%d\n", n);
    fputs(line, fp_out);

    while (fgets(line, N, fp_in) != NULL) {
        name[0] = '\0';
        word = strtok(line, " \n");
        while (word != NULL) {
            word[0] = toupper(word[0]);
            for (int i = 1; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }
            strcat(name, word);
            strcat(name, " ");
            word = strtok(NULL, " \n");
        }
        name[strlen(name) - 1] = '\n';
        fputs(name, fp_out);
    }

    fclose(fp_in);
}