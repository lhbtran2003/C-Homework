#include<stdio.h>
int main(){
    FILE *fp;
    fp = fopen("sample.txt","r");
    int N =256l;
    char str[N];
    while(fgets(str, N , fp) !=NULL) {
        printf("%s", str);
    }
}