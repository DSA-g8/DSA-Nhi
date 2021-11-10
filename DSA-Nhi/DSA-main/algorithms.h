#include <iostream>
using namespace std;

void selectionSortWithComparison(int a[], int n, unsigned long long &count_compare);
void selectionSortWithTime(int a[], int n);

void mergeSortWithTime(int *arr, int low, int high);
void mergeSortWithComparison(int *arr, int low, int high, unsigned long long &count_compare);

void radixSortWithComparison(int a[], int n, unsigned long long &count_compare);
void radixSortWithTime(int a[], int n);
