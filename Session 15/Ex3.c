#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
    if (n <= 1) return 0;
    if (n <= 3) return 1;

    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;

    return 1;
}

int main() {
    int hang, cot;
    printf("Nhap so hang: ");
    scanf("%d", &hang);
    printf("Nhap so cot: ");
    scanf("%d", &cot);

    int** arr = (int**)malloc(hang * sizeof(int*));
    for(int i = 0; i < hang; i++)
    {
        arr[i] = (int*)malloc(cot * sizeof(int));
    }

    printf("Nhap cac phan tu cua mang:\n");
    for(int i = 0; i < hang; i++)
    {
        for(int j = 0; j < cot; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int max_primes = 0;
    int cot_index = -1;
    for(int j = 0; j < cot; j++)
    {
        int prime_count = 0;
        for(int i = 0; i < hang; i++)
        {
            if(is_prime(arr[i][j]))
            {
                prime_count++;
            }
        }
        if(prime_count >= max_primes)
        {
            max_primes = prime_count;
            cot_index = j;
        }
    }

    printf("Cot co nhieu so nguyen to nhat la: %d\n", cot_index);

    for(int i = 0; i < hang; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
