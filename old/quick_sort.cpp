#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[high]);
    return i;
}

void quickSort(int *arr, int low, int high)
{
    if (low > high)
        return;
    int pidx = partition(arr, low, high);
    quickSort(arr, low, pidx - 1);
    quickSort(arr, pidx + 1, high);
}

void display(int *arr, int len)
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
    int arr[] = {2, 1, 3, 5, 6, 4, 8, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    display(arr, len);
    quickSort(arr, 0, len - 1);
    display(arr, len);
}