#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int swpcnt, cmpcnt;
// Function to swap two elements
void swap(int* a, int* b) 
{
	int t = *a;
	*a = *b;
	*b = t;
	swpcnt++;
}

int partition(int arr[], int low, int high) 
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) 
	{
		cmpcnt++;
		if (arr[j] < pivot) 
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high) 
{
	if (low < high) 
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// Function to print the array
void printArray(int arr[], int size) 
{
	int i;
	for (i = 0; i < size; i++)
	printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
    int arr[1000];
    int n = 1000, i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    arr[i] = rand()%1000;
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
}