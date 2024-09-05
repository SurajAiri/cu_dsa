#include <iostream>
using namespace std;

void printArray(int *arr, int len){
    for(int i = 0;i < len; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}
void merge(int *arr, int beg,int mid, int end){
    int len = end-beg + 1;
    int arr2[len];
    int i = beg, j = mid + 1, x = 0;
    
    while(i <= mid & j <= end){
        if(arr[i] < arr[j]){
            arr2[x] = arr[i];
            i++;
        }else{
            arr2[x] = arr[j];
            j++;
        }
            x++;
    }
    
    while(i <= mid){
        arr2[x] = arr[i];
            i++;
            x++;
    }
    while(j <= end){
        arr2[x] = arr[j];
            j++;
            x++;
    }
    for(int i = 0; i < len; i++){
        arr[beg + i] = arr2[i];
    }
}

void mergeSort(int *arr, int beg, int end){
    if(beg >= end)return;
    int mid = beg + (end - beg)/2;
    cout << beg << "|" << mid << "|" << end << endl;

    mergeSort(arr, beg, mid);
    mergeSort(arr,mid + 1, end);
    merge(arr, beg, mid, end);
}

int main() {
    int arr[] = {7,8,3,4,5,1};
    int len = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, len -1 );
    printArray(arr, len);

    return 0;
}