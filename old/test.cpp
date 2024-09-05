// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
/*
// void swap(int *a, int *b){
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

// void bubble(int *arr, int len){
//     for(int i = 0; i < len; i++){
//         for(int j = 0; j < len - i; j++){
//           if(arr[j] > arr[j + 1]){
//               swap(&arr[j], & arr[j+1]);
//           }
//         }
//     }
// }

// void selection(int *arr, int len){
//     int min;
//     for(int i = 0; i < len; i++){
//         min = i;
//         for(int j = i; j < len; j ++){
//             if(arr[j] < arr[min])
//                 min = j;
//         }
//         if(min != i)
//             swap(&arr[min], &arr[i]);
//     }
// }

// void insertion(int *arr, int len){
//     int key, j;
//     for(int i = 1; i < len; i++){
//         key = arr[i];
//         j = i - 1;

//         while(key < arr[j] && j >= 0){
//             arr[j + 1] = arr[j];
//             j--;
//         }

//         arr[j+1] = key;
//     }
// }
*/

void merge(int *arr, int beg, int mid, int end)
{
    int len = end - beg + 1;
    int arr2[len];
    int i = beg, j = mid + 1, x = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            arr2[x] = arr[i];
            i++;
        }
        else
        {
            arr2[x] = arr[j];
            j++;
        }

        x++;
        // cout << x << endl;
    }

    while (i <= mid)
    {
        arr2[x] = arr[i];
        i++;
        x++;
    }
    while (j <= end)
    {
        arr2[x] = arr[j];
        j++;
        x++;
    }

    for (int x = 0, i = beg; x < len; x++, i++)
    {
        arr[i] = arr2[x];
    }
}

void divide(int *arr, int beg, int end)
{
    if (beg >= end)
        return;
    int mid = beg + (end - beg) / 2;
    divide(arr, beg, mid);
    divide(arr, mid + 1, end);
    merge(arr, beg, mid, end);
}

void display(int arr[], int len)
{
    cout << "The array elements are: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {3, 2, 4, 1, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    // selection(arr, len);
    display(arr, len);
    divide(arr, 0, len - 1);
    display(arr, len);
    return 0;
}