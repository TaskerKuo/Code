#include<stdio.h>
#include<stdlib.h>

void merge(int* arr, int st, int mid, int end){
    int len1 = mid - st + 1;
    int len2 = end - mid;

    int* sub1 = (int*)malloc(len1*sizeof(int));
    int* sub2 = (int*)malloc(len2*sizeof(int));

    for(int i=0; i<len1; i++) sub1[i] = arr[st+i];
    for(int i=0; i<len2; i++) sub2[i] = arr[mid+i+1];

    int i=0, j=0, k=st;
    while (i<len1 && j<len2){
        if(sub1[i]<=sub2[j]) arr[k++] = sub1[i++];
        else arr[k++] = sub2[j++];
    }

    while (i<len1) arr[k++] = sub1[i++];
    while (j<len2) arr[k++] = sub1[j++];

    free(sub1);
    free(sub2);
}

void Mergesort(int* arr, int st, int end){
    if(st>=end) return;
    int mid = st + (end-st)/2;
    Mergesort(arr, st, mid);
    Mergesort(arr, mid+1, end);
    merge(arr, st, mid, end);
}


int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    Mergesort(arr,0,n-1);
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    return 0;
}