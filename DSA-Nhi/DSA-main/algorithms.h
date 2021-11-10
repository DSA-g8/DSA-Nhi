#include <iostream>
using namespace std;

void selectionSortWithComparison(int a[], int n, int &count_compare);
void selectionSortWithTime(int a[], int n);


void mergeSortWithTime(int *arr, int low, int high);
void mergeSortWithComparison(int *arr, int low, int high, int &comparisons_count);


void radixSortWithComparison(int a[], int n, int &count_compare);
void radixSortWithTime(int a[], int n);

void insertionSortWithComparison(int arr[], int n, int& compareCountInsert);
void insertionSortWithTime(int arr[], int n);

int partitionTime(int arr[], int low, int high);
int partitionComparison(int arr[], int low, int high, int& countCompareQuick);
void quickSorWithTime(int arr[], int low, int high);
void quickSorWithComparison(int arr[], int low, int high, int& countCompareQuick)

