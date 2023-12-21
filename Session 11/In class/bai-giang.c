 Sắp xếp chèn - Insertion Sort

 Sắp xếp chọn - Selection Sort
 Sắp xếp từ bé đến lớn
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *b = *a;
    *b = temp;
};
void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        // Dung 1 bien de luu chi so cua ptu nho nhat
        int min_pos = i;
        // Duyent tat ca cac phan tu dung sau
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min_pos])
                min_pos = j;
        }
        swap(&arr[i], &arr[min_pos]);
    }
}
//
// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n-1  )
    {

    }
}

