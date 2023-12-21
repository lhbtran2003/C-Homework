#include <stdio.h>
void swap( int *num1, int *num2)
{
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}
void sort(int arr[], int size)
{
    for ( int i = 0; i < size; i++)
    {
        for (int j =i +1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}



void input(int arr[], int size)
{
    for ( int  i= 0; i< size; i++)
    {
        scanf("%d", &arr[i]);
    }
}
 void chenso(int arr[], int size, int m)
 {
    printf("\n Nhap so can chen: ");
    scanf("%d", &m);
    arr[size - 1] = m;
 }

 void output(int arr[], int size)
 {
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
 }

int main()
{
    int arr[100];
    int n,m;
    printf("Enter size: ");
    scanf("%d", &n);
    input(arr, n);
    chenso(arr, n+1, m);

    sort(arr, n+1);
    output(arr, n+1);
    return 0;




}