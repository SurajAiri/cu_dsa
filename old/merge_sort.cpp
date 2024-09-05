#include<iostream>
using namespace std;

void printArray(int arr[], int len){
    cout << "The array element are: ";
    for(int i = 0; i < len; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void conquer(int *arr, int beg, int mid, int end){
    int len = end - beg + 1;
    int arr2[len];
    // int k = 0;
    int i = beg, j = mid+1, k = 0;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            arr2[k] = arr[i];
            i++;
        }else{
            arr2[k] = arr[j];
            j++;
        }
        k++;
    } 
    while(i <= mid){
        arr2[k] = arr[i];
        i++;
        k++;
    }

    while(j <= end){
         arr2[k] = arr[j];
        j++;
        k++;
    }

    for(int i = beg, k = 0; k < len; i++, k++){
        arr[i] = arr2[k];
    }
}


void divide(int *arr, int beg, int end){
    if(beg >= end)return;
    int mid = beg + (end - beg)/ 2;
    // cout << beg << "|" << mid << "|" << end << endl;
    divide(arr,beg, mid);
    divide(arr, mid +1, end);
    conquer(arr, beg, mid, end);
}

int main(){
    int arr[5];
    cout << "Enter 5 array elements: ";
    for(int i = 0; i < 5; i++)
        cin >> arr[i];
    divide(arr, 0, 4);
    printArray(arr, 5);

    return 0;
}
