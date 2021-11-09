#include <iostream>
using namespace std;

void selectionSortWithComparison(int a[], int n, int &count_compare);
void selectionSortWithTime(int a[], int n);

void mergeSortWithTime(int *arr, int low, int high);
void mergeSortWithComparison(int *arr, int low, int high, int &comparisons_count);

void radixSortWithComparison(int a[], int n, int &count_compare);
void radixSortWithTime(int a[], int n);
