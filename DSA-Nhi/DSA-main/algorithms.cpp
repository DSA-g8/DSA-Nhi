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
    int j, min;
    for (int i = 0; ++count_compare && i < n; i++)
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

// 2. InsertionSort, souce:https://www.geeksforgeeks.org/insertion-sort/
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

// 3. BubbleSort, souce:https://www.geeksforgeeks.org/bubble-sort/
void bubbleSortWithTime(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

void bubbleSortWithComparison(int a[], int n, unsigned long long &compareCountBubble)
{
    for (int i = 0; ++compareCountBubble && i < n - 1; i++)
        for (int j = 0; ++compareCountBubble && j < n - i - 1; j++)
            if (++compareCountBubble && a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

// 4. HeapSort
void heapBuildWithTime(int index, int a[], int n)
{
    bool isHeap = false;
    int l, k = index;

    while (!isHeap && (2 * k + 1) < n)
    {
        l = 2 * k + 1;

        if (l < n - 1)
            if (a[l] < a[l + 1])
                l = l + 1;

        if (a[k] > a[l])
            isHeap = true;
        else
        {
            swap(a[k], a[l]);
            k = l;
        }
    }
}

void heapSortWithTime(int a[], int n)
{
    int pos = (n - 1) / 2;
    while (pos >= 0)
    {
        heapBuildWithTime(pos, a, n);
        pos = pos - 1;
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        n = n - 1;
        heapBuildWithTime(0, a, n);
    }
}

void heapBuildWithComparison(int index, int a[], int n, unsigned long long &compareCountHeap)
{
    bool isHeap = false;
    int l, k = index;

    while ((++compareCountHeap && !isHeap) && (++compareCountHeap && (2 * k + 1) < n))
    {

        l = 2 * k + 1;

        if (++compareCountHeap && l < n - 1)
        {
            if (++compareCountHeap && a[l] < a[l + 1])
            {
                l = l + 1;
            }
        }

        if (++compareCountHeap && a[k] > a[l])
        {
            isHeap = true;
        }
        else
        {
            swap(a[k], a[l]);
            k = l;
        }
    }
}

void heapSortWithComparison(int a[], int n, unsigned long long &compareCountHeap)
{
    int pos = (n - 1) / 2;
    while (++compareCountHeap && pos >= 0)
    {
        heapBuildWithComparison(pos, a, n, compareCountHeap);
        pos = pos - 1;
    }

    for (int i = n - 1; ++compareCountHeap && i > 0; i--)
    {
        swap(a[0], a[i]);
        n = n - 1;
        heapBuildWithComparison(0, a, n, compareCountHeap);
    }
}

// 6. QuickSort, souce:https://www.geeksforgeeks.org/quick-sort/
int partitionTime(int *arr, int low, int high)
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

int partitionComparison(int *arr, int low, int high, unsigned long long &countCompareQuick)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);

    for (int j = low; ++countCompareQuick && j <= high - 1; j++)
    {
        if (++countCompareQuick && arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSorWithTime(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partitionTime(arr, low, high);
        if (pi - low < high - pi)
        {
             quickSorWithTime(arr, low, pi - 1);
              low = pi + 1;
        }
        else
        {
            quickSorWithTime(arr, pi + 1, high);
            high = pi -1;
        }
        
    }
}

void quickSorWithComparison(int *arr, int low, int high, unsigned long long &countCompareQuick)
{
    if (++countCompareQuick && low < high)
    {
        int pi = partitionComparison(arr, low, high, countCompareQuick);
        if (++countCompareQuick && (pi - low < high - pi))
        {
            quickSorWithComparison(arr, low, pi - 1, countCompareQuick);
            low = pi + 1;
        } else {
            quickSorWithComparison(arr, pi + 1, high, countCompareQuick);
            high = pi -1;
        }
    }
}

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
int MaxNumber(int a[], int n, unsigned long long &count_compare)
{
    int m = a[0];
    count_compare = 0;
    for (int i = 1; ++count_compare && i < n; i++)
        if (++count_compare && a[i] > m)
            m = a[i];
    return m;
}

void Count(int arr[], int n, int exp, unsigned long long &count_compare)
{
    int bucket[n];
    int i, box[10] = {0};
    count_compare = 0;

    for (i = 0; ++count_compare && i < n; i++)
        box[(arr[i] / exp) % 10]++;

    for (i = 1; ++count_compare && i < 10; i++)
        box[i] += box[i - 1];

    for (i = n - 1; ++count_compare && i >= 0; i--)
    {
        bucket[box[(arr[i] / exp) % 10] - 1] = arr[i];
        box[(arr[i] / exp) % 10]--;
    }

    for (i = 0; ++count_compare && i < n; i++)
        arr[i] = bucket[i];
}

void radixSortWithComparison(int a[], int n, unsigned long long &count_compare)
{
    int m = MaxNumber(a, n, count_compare);

    for (int exp = 1; m / exp > 0; exp *= 10)
        Count(a, n, exp, count_compare);
}

int MaxNumber1(int a[], int n)
{
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m)
            m = a[i];
    return m;
}

void Count1(int arr[], int n, int exp)
{
    int bucket[n];
    int i, box[10] = {0};

    for (i = 0; i < n; i++)
        box[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        box[i] += box[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        bucket[box[(arr[i] / exp) % 10] - 1] = arr[i];
        box[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = bucket[i];
}

void radixSortWithTime(int a[], int n)
{
    int m = MaxNumber1(a, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        Count1(a, n, exp);
}
