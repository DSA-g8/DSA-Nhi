#include <iostream>
using namespace std;

void selectionSortWithComparison(int a[], int n, unsigned long long &count_compare);
void selectionSortWithTime(int a[], int n);

void insertionSortWithTime(int arr[], int n);
void insertionSortWithComparison(int arr[], int n, unsigned long long &compareCountInsert);

void quickSortWithTime(int *arr, int low, int high);
void quickSortWithComparison(int *arr, int low, int high, unsigned long long &countCompareQuick);

void mergeSortWithTime(int *arr, int low, int high);
void mergeSortWithComparison(int *arr, int low, int high, unsigned long long &count_compare);

void radixSortWithComparison(int a[], int n, unsigned long long &count_compare);
void radixSortWithTime(int a[], int n);

void bubbleSortWithTime(int a[], int n);
void bubbleSortWithComparison(int a[], int n, unsigned long long &compareCountBubble);

void heapSortWithTime(int a[], int n);
void heapSortWithComparison(int a[], int n, unsigned long long &compareCountHeap);
