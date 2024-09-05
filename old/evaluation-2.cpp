

/*
Given an array with many duplicate values. Write an algo. to efficiently sort it linear time where order of qual elements does not matter.
Input: 4,2,40, 10,10, 1, 4,2, 1, 10,40
*/
#include <iostream>
using namespace std;

void conquer(int *arr, int beg, int mid, int end)
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
            x++;
        }
        else
        {
            arr2[x] = arr[j];
            j++;
            x++;
        }
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

    for (int i = beg, x = 0; x < len; x++, i++)
    {
        arr[i] = arr2[x];
    }
}

void sort(int *arr, int beg, int end)
{
    if (beg >= end)
        return;
    int mid = beg + (end - beg) / 2;
    sort(arr, beg, mid);
    sort(arr, mid + 1, end);
    conquer(arr, beg, mid, end);
}

void displayArr(int *arr, int len)
{
    cout << "\nThe array elements are: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << ", ";
    }
}

int main()
{
    int arr[] = {4, 2, 40, 10, 10, 1, 4, 2, 1, 10, 40};
    int len = sizeof(arr) / sizeof(arr[0]);

    displayArr(arr, len);
    sort(arr, 0, len - 1);
    displayArr(arr, len);
    return 0;
}