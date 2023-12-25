#include<stdio.h>
void input( int *a, int n)
{
    int i;
    printf("Enter ptu:");
    scanf("%d", n);
    for(i = 0; i < n; i++)
    {
        printf("Enter a[%d]", i);
        scanf("%d", a+i);
    }
}

int main()
{
    int a[100], n;
    input(a, n);
}

    void input_array(int *a, int n) {
        printf("Nhập phần tử của mảng: ");
        scanf("%d", &n);

        for(int i = 0; i < n; i++) {
            printf("Nhập a[%d]: ", i);
            scanf("%d", (a+i));
        };
    }






