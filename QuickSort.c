#include<stdio.h>

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int* arr, int low, int high){
    int pivot = *(arr+high);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (*(arr+j) <= pivot) {
            i++;
            swap(arr+i, arr+j);
        }
    }
    swap(arr+i+1, arr+high);
    return (i + 1);
}

void QuickSort(int* arr, int low, int high) {
    if (low < high) {
        int idx = partition(arr, low, high);
        QuickSort(arr, low, idx - 1);
        QuickSort(arr, idx + 1, high);
    }
}

int main() {
    int arr[] = {3, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}