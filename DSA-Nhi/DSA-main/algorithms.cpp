#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 1.SelectionSort
void selectionSortWithComparison(int a[], int n, unsigned long long &count_compare)
{
    int  j,  min;
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
    int j, min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
            {
                swap(a[i], a[j]);
            }
    }
}

<<<<<<< HEAD
//2. InsertionSort, souce:https://www.geeksforgeeks.org/insertion-sort/
void insertionSortWithComparison(int arr[], int n, unsigned long long &compareCountInsert)
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
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int partitionComparison(int arr[], int low, int high, unsigned long long &countCompareQuick)
{
    int pivot = arr[high]; // pivot 
    int i = (low - 1);

    for (int j = low; ++countCompareQuick && j <= high - 1; j++)
    {
        if (++countCompareQuick &&arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSorWithTime(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionTime(arr, low, high);
        quickSorWithTime(arr, low, pi - 1);
        quickSorWithTime(arr, pi + 1, high);
    }
}

void quickSorWithComparison(int arr[], int low, int high, unsigned long long &countCompareQuick)
{
    if ( ++countCompareQuick && low < high)
    {
        int pi = partitionComparison(arr, low, high, countCompareQuick);
        quickSorWithComparison(arr, low, pi - 1, countCompareQuick);
        quickSorWithComparison(arr, pi + 1, high, countCompareQuick);
    }
}


// 7.MergeSort, souce: https://www.geeksforgeeks.org/merge-sort/
void mergeWithTime(int array[], int const left, int const mid, int const right)
=======
// 7.MergeSort, souce: https://www.geeksforgeeks.org/merge-sort/
void mergeWithTime(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
         indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSortWithTime(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSortWithTime(array, begin, mid);
    mergeSortWithTime(array, mid + 1, end);
    mergeWithTime(array, begin, mid, end);
}

void mergeWithComparison(int array[], int const left, int const mid, int const right, unsigned long long &count_compare)
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

<<<<<<< HEAD
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
=======
    for (auto i = 0; ++count_compare && i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; ++count_compare && j < subArrayTwo; j++)
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
         indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

<<<<<<< HEAD
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
=======
    while (++count_compare && indexOfSubArrayOne < subArrayOne && ++count_compare && indexOfSubArrayTwo < subArrayTwo)
    {
        if (++count_compare && leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

<<<<<<< HEAD
    while (indexOfSubArrayOne < subArrayOne)
=======
    while (++count_compare && indexOfSubArrayOne < subArrayOne)
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
<<<<<<< HEAD
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSortWithTime(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSortWithTime(array, begin, mid);
    mergeSortWithTime(array, mid + 1, end);
    mergeWithTime(array, begin, mid, end);
}

void mergeWithComparison(int array[], int const left, int const mid, int const right, unsigned long long &count_compare)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; ++count_compare && i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; ++count_compare && j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
         indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (++count_compare && indexOfSubArrayOne < subArrayOne && ++count_compare && indexOfSubArrayTwo < subArrayTwo)
    {
        if (++count_compare && leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
=======
    }

    while (++count_compare && indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
        indexOfMergedArray++;
    }

    while (++count_compare && indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (++count_compare && indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSortWithComparison(int array[], int const begin, int const end, unsigned long long &count_compare)
{
    if (++count_compare && begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSortWithComparison(array, begin, mid, count_compare);
    mergeSortWithComparison(array, mid + 1, end, count_compare);
    mergeWithComparison(array, begin, mid, end, count_compare);
}

// 9.RadixSort
int MaxNumber(int a[], int n, unsigned long long &count_compare )
{
    int m = a[0];
	count_compare = 0;
    for (int i = 1; ++count_compare && i < n; i++)
        if (++count_compare && a[i] > m)
            m = a[i];
    return m;
}

<<<<<<< HEAD
=======
void mergeSortWithComparison(int array[], int const begin, int const end, unsigned long long &count_compare)
{
    if (++count_compare && begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSortWithComparison(array, begin, mid, count_compare);
    mergeSortWithComparison(array, mid + 1, end, count_compare);
    mergeWithComparison(array, begin, mid, end, count_compare);
}

// 9.RadixSort
int MaxNumber(int a[], int n, unsigned long long &count_compare )
{
    int m = a[0];
	count_compare = 0;
    for (int i = 1; ++count_compare && i < n; i++)
        if (++count_compare && a[i] > m)
            m = a[i];
    return m;
}

>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
void Count(int arr[], int n, int exp, unsigned long long &count_compare)
{
    int bucket[n]; 
    int i, box[10] = { 0 };
 	count_compare = 0;

    for (i = 0; ++count_compare && i < n; i++)
        box[(arr[i] / exp) % 10]++;
 
    for (i = 1; ++count_compare && i < 10; i++)
        box[i] += box[i - 1];
 
    for (i = n - 1; ++count_compare && i >= 0; i--) {
        bucket[box[(arr[i] / exp) % 10] - 1] = arr[i];
        box[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; ++count_compare && i < n; i++)
        arr[i] = bucket[i];
}


void radixSortWithComparison(int a[], int n, unsigned long long &count_compare)
{
	int m =  MaxNumber(a, n, count_compare);
 
    for (int exp = 1; m / exp > 0; exp *= 10)
        Count(a, n, exp, count_compare);
<<<<<<< HEAD
}

int MaxNumber1(int a[], int n )
{
    int m = a[0];
    for (int i = 1;  i < n; i++)
        if (a[i] > m)
            m = a[i];
    return m;
=======
}

int MaxNumber1(int a[], int n )
{
    int m = a[0];
    for (int i = 1;  i < n; i++)
        if (a[i] > m)
            m = a[i];
    return m;
}

void Count1(int arr[], int n, int exp)
{
    int bucket[n]; 
    int i, box[10] = { 0 };

    for (i = 0;  i < n; i++)
        box[(arr[i] / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        box[i] += box[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        bucket[box[(arr[i] / exp) % 10] - 1] = arr[i];
        box[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = bucket[i];
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
}

void Count1(int arr[], int n, int exp)
{
<<<<<<< HEAD
    int bucket[n]; 
    int i, box[10] = { 0 };

    for (i = 0;  i < n; i++)
        box[(arr[i] / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        box[i] += box[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        bucket[box[(arr[i] / exp) % 10] - 1] = arr[i];
        box[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = bucket[i];
}

void radixSortWithTime(int a[], int n)
{
	int m =  MaxNumber1(a, n);
 
    for (int exp = 1; m / exp > 0; exp *= 10)
        Count1(a, n, exp);
}
=======
	int m =  MaxNumber1(a, n);
 
    for (int exp = 1; m / exp > 0; exp *= 10)
        Count1(a, n, exp);
}
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
