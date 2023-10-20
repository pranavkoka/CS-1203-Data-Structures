#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
 
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create two arrays
    int L[n1], R[n2];
 
    // Copy data to the two arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the arrays
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[] is any
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[] if any
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
 
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 

int main()
{
    int arr[10000];
    int n = 10000, i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    arr[i] = rand()%1000;
    printArray(arr, n);
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
}

/*Time Complexity:
It is nlogn in three cases because it is divded into two halves everytime so the height of the tree would be logn.
It is same for all three cases because the array is always divided into two halves and takes linear time to merge two halves.

The time complexity in all three cases is the same as heap sort.
In worst case it is better than quick sort but the other two cases is same.
*/