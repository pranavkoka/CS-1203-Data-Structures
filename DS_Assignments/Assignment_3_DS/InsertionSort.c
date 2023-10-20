#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionsort(int arr[], int n)
{
    int i;
    for (i = 1; i < n; i = i+1)
    {   
        while (i !=0 && arr[i] < arr[i-1]) 
        {
            swap(&arr[i],&arr[i-1]);
            i = i-1;
        }
    }
    int j;
    for (j = 0; j < n-1; j = j+1)
    {
        printf(" %d,", arr[j]);
    }
    printf(" %d", arr[j]);
    printf("\n");   
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n-1; i = i+1)
        {
            printf(" %d,", arr[i]);
        }
    printf(" %d", arr[i]);
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
    insertionsort(arr, n);
    printArray(arr, n);
}

/*Time Complexity:
Worst case is O(n^2) if array is in decreasing order
Best case is O(n) if array is sorted or in increasing order
Average case is O(n^2) because the it uses nested loop and outer loop runs n times and inner loop runs n times so n*n

The time complexity in all three cases is the same as bubble sort.
*/
