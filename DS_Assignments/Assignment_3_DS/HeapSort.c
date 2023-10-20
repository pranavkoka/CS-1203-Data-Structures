#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp;
    temp = *xp; *xp = *yp; *yp = temp;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}

void heapInsert(int arr[], int n, int elm)
{
    int i, parent;
    arr[n] = elm; i = n;
    if (i == 0) return;
    while (i != 0)
    {
        parent = (i-1)/2;
        if (arr[parent] < arr[i]) swap(&arr[i], &arr[parent]);
        else break;
        i = parent;
    }
}

int heapDelete(int arr[], int n)
{
    int i, left, right, largest, val, flag = 1;
    if (n == 0) return -9999;
    val = arr[0]; arr[0] = arr[n-1]; i = 0;
    while (flag == 1)
    {
        flag = 0; largest = i;
        left = 2*i+1; right = 2*i+2;
        if (left <= n-1 && arr[left] > arr[largest])
        {
            largest = left; flag = 1; 
        }
        if (right <= n-1 && arr[right] > arr[largest])
        {
        largest = right; flag = 1; 
        }
        if (flag == 1)
        {
        swap(&arr[i], &arr[largest]); i = largest;
        }
    }
    return val;
}

void heapSort(int arr[], int n)
{
    int i, elm;
    for(i = 0; i < n; i++)
    heapInsert(arr, i, arr[i]);
    for(i = n; i > 0; i--)
    {
        elm = heapDelete(arr, i);
        arr[i-1] = elm;
    }
}

int main()
{
    int arr[10000];
    int n = 10000, i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    arr[i] = rand()%1000;
    printArray(arr, n);
    heapSort(arr, n);
    printArray(arr, n);
}