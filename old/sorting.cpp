// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void swap(int *a, int * b){
    // cout << *a << "|" << *b << endl;
    int temp = *a;
    *a = *b;
    *b = temp;
}

void displayArray(int *arr, int len){
    cout << "The array elements are: ";
    for(int i = 0; i < len; i++){
        cout << arr[i] << ", ";
    }
}

void bubbleSort(int *arr, int len){
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len - i; j++){
            if(arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
        // displayArray(arr,len);
        // cout << endl;
    }
}

void insertionSort(int *arr, int len){
    int key, j;
    for(int i = 1; i < len; i++){
        key = arr[i], j = i - 1;
        while(key < arr[j] && j >= 0){
            arr[j + 1] = arr[j];
            j --;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int *arr, int len){
    int min;
    for(int i = 0; i < len; i ++){
        min = i;
        for(int j = i; j < len; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}

void mergeSort(int *arr, int beg, int end){
    int mid = beg + (end - beg) / 2;
    mergeSort(arr, beg, mid);
    mergeSort(arr, mid + 1, end);
    finalMergeSort(arr, beg, mid, end);
}

void finalMergeSort(int *arr, int beg, int mid, int end){
    int len2 = end - beg + 1;
    int  arr2[] = new arr[len2]
    int i = beg, j = mid + 1, x = 0;
    while(i <= mid && j < end){
        if(arr[i] < arr[j]){
            arr2[x] = arr[i];
            i++;
        }else{
            arr2[x] == arr[j];
            j++;
        }
            x++;
    }
    
    while(i <= mid){
        arr2[x] = arr[i];
        i++;
        x++;
    }
    
    while(j < end){
        arr2[x] == arr[j];
        j++;
        x++;
    }
    
    for(int c = beg, x = 0; c < end; c++, x++){
        arr[c] = arr2[x];
    }
}


int main() {
    int arr[5];
    cout << "Enter array Elements: ";
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }
    // selectionSort(arr, 5);
    mergeSort(arr, 0,4);
    displayArray(arr, 5);
    return 0;
}