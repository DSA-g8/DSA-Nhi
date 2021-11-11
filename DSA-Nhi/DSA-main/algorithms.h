#include <iostream>
using namespace std;

void selectionSortWithComparison(int a[], int n, unsigned long long &count_compare);
void selectionSortWithTime(int a[], int n);

void insertionSortWithTime(int arr[], int n);
void insertionSortWithComparison(int arr[], int n, unsigned long long &compareCountInsert);

void quickSorWithTime(int arr[], int low, int high);
void quickSorWithComparison(int arr[], int low, int high, unsigned long long &countCompareQuick);

void mergeSortWithTime(int *arr, int low, int high);
void mergeSortWithComparison(int *arr, int low, int high, unsigned long long &count_compare);

void radixSortWithComparison(int a[], int n, unsigned long long &count_compare);
void radixSortWithTime(int a[], int n);
