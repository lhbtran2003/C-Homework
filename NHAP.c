#include<stdio.h>
#include<math.h>
int max(int a, int b){
    if(a > b) return a;
    else return b;
}
int change(int n){
    n += 10;
    return n;
}
int tong(int n){
    return n * (n+1) /2;
}
void xinchao(){
    printf("xin chao");
    printf("%d", tong(3));
}

void chinhphuong(int n){
    int can = sqrt(n);
    if (can * can == n) printf("Yes");
    else printf("No");
}

int chinhphuong2(int n){
    int can = sqrt(n);
    if(can*can==n) return 1;
    else return 0;
}
int main(){
    printf("%d", max(100, 200));
    int m = 100;
    printf("%d", change(m));
    xinchao();
    chinhphuong(20);
    if(chinhphuong2(16) == 1) printf("Yes");
    else printf("No");
    return 0;
}