#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 1.SelectionSort
void selectionSortWithComparison(int a[], int n, int &count_compare)
{
    int  j, min;
    for (int i = 0; ++count_compare && i < n  ; i++)
    {
	    min = i;
    	for (j = i + 1; ++count_compare && j < n; j++)
        	if (++count_compare && a[j] < a[min])
        	 {
        	    swap(a[min], a[j]);
             }
    }
}
void selectionSortWithTime(int a[], int n)
{
    int  j, min;
    for (int i = 0;  i < n  ; i++)
    {
	    min = i;
    	for (j = i + 1; j < n; j++)
        	if (a[j] < a[min])
        	 {
        	    swap(a[i], a[j]);
             }
    }

}

//2. InsertionSort, souce:https://www.geeksforgeeks.org/insertion-sort/
void insertionSortWithComparison(int arr[], int n, int &compareCountInsert)
{
    int i, key, j;
    for (i = 1; ++compareCountInsert && i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (++compareCountInsert && j >= 0 && ++compareCountInsert && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortWithTime(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//5.MergeSort, souce: https://www.softwaretestinghelp.com/merge-sort/
void mergeWithTime(int *arr, int low, int high, int mid) {
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}

void mergeSortWithTime(int *arr, int low, int high) {
    int mid;
    if (low < high){
        mid=(low+high)/2;
        mergeSortWithTime(arr,low,mid);
        mergeSortWithTime(arr,mid+1,high);
        mergeWithTime(arr,low,high,mid);
    }
}

void mergeWithComparison(int *arr, int low, int high, int mid, int &comparisons_count) {
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (++comparisons_count && i <= mid && j <= high) {
        if (++comparisons_count && arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (++comparisons_count && i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (++comparisons_count && j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; ++comparisons_count && i < k; i++)  {
        arr[i] = c[i];
    }
}

void mergeSortWithComparison(int *arr, int low, int high, int &comparisons_count) {
    int mid;
    if (++comparisons_count && low < high) {
        mid=(low+high)/2;
        mergeSortWithComparison(arr,low,mid, comparisons_count);
        mergeSortWithComparison(arr,mid+1,high, comparisons_count);
        mergeWithComparison(arr,low,high,mid, comparisons_count);
    }
}
 //6. QuickSort, souce:https://www.geeksforgeeks.org/quick-sort/
int partitionTime(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int partitionComparison(int arr[], int low, int high, int &countCompareQuick)
{
    int pivot = arr[high]; // pivot 
    int i = (low - 1);

    for (int j = low; ++countCompareQuick && j <= high - 1; j++)
    {
        if (++countCompareQuick &&arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSorWithTime(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSorWithTime(arr, low, pi - 1);
        quickSorWithTime(arr, pi + 1, high);
    }
}

void quickSorWithComparison(int arr[], int low, int high, int &countCompareQuick)
{
    if ( ++countCompareQuick && low < high)
    {
        int pi = partitionComparison(arr, low, high, countCompareQuick);
        quickSorWithComparison(arr, low, pi - 1, countCompareQuick);
        quickSorWithComparison(arr, pi + 1, high, countCompareQuick);
    }
}

// 7.RadixSort
void radixSortWithComparison(int a[], int n, int &count_compare)
{
	int b[n], temp, i ;
    int box[10] = {0}, m = a[0];
    
	for (i = 0;++count_compare && i < n; i++)
	{
		if (++count_compare && a[i] > m)
			m = a[i];
	}
	while (++count_compare && m / temp > 0)
	{
		for (i = 0;++count_compare && i < n; i++)
			box[a[i] / temp % 10]++;
		for (i = 1;++count_compare && i < 10; i++)
			box[i] += box[i - 1];
		for (i = n - 1;++count_compare && i >= 0; i--)
			b[--box[a[i] / temp % 10]] = a[i];
		for (i = 0;++count_compare && i < n; i++)
			a[i] = b[i];
		temp *= 10;
	}
}


void radixSortWithTime(int a[], int n)
{
	int b[n], temp, i ;
    int box[10] = {0},  m = a[0];
    
	for (i = 0; i < n; i++)
	{
		if (a[i] > m)
			m = a[i];
	}
	while (m / temp > 0)
	{
		for (i = 0;i < n; i++)
			box[a[i] / temp % 10]++;
		for (i = 1; i < 10; i++)
			box[i] += box[i - 1];
		for (i = n - 1; i >= 0; i--)
			b[--box[a[i] / temp % 10]] = a[i];
		for (i = 0; i < n; i++)
			a[i] = b[i];
		temp *= 10;
	}
}

