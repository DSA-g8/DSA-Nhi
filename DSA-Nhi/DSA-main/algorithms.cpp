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
    int j;
    for (int i = 0; ++count_compare && i < n; i++)
    {
        for (j = i + 1; ++count_compare && j < n; j++)
            if (++count_compare && a[j] < a[i])
            {
                swap(a[i], a[j]);
            }
    }
}
void selectionSortWithTime(int a[], int n)
{
    int j;
    for (int i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
            if (a[j] < a[i])
            {
                swap(a[i], a[j]);
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

void mergeWithComparison(int array[], int const left, int const mid, int const right, int &count_compare)
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

void mergeSortWithComparison(int array[], int const begin, int const end, int &count_compare)
{
    if (++count_compare && begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSortWithComparison(array, begin, mid, count_compare);
    mergeSortWithComparison(array, mid + 1, end, count_compare);
    mergeWithComparison(array, begin, mid, end, count_compare);
}

// 9.RadixSort
void radixSortWithComparison(int a[], int n, int &count_compare)
{
    int b[n], temp, i;
    int box[10] = {0}, m = a[0];

    for (i = 0; ++count_compare && i < n; i++)
    {
        if (++count_compare && a[i] > m)
            m = a[i];
    }
    while (++count_compare && m / temp > 0)
    {
        for (i = 0; ++count_compare && i < n; i++)
            box[a[i] / temp % 10]++;
        for (i = 1; ++count_compare && i < 10; i++)
            box[i] += box[i - 1];
        for (i = n - 1; ++count_compare && i >= 0; i--)
            b[--box[a[i] / temp % 10]] = a[i];
        for (i = 0; ++count_compare && i < n; i++)
            a[i] = b[i];
        temp *= 10;
    }
}

void radixSortWithTime(int a[], int n)
{
    int b[n], temp, i;
    int box[10] = {0}, m = a[0];

    for (i = 0; i < n; i++)
    {
        if (a[i] > m)
            m = a[i];
    }
    while (m / temp > 0)
    {
        for (i = 0; i < n; i++)
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
