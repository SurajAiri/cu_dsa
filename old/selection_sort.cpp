#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection(int *arr, int len)
{
    int min;
    for (int i = 0; i < len; i++)
    {
        min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        if (min != i)
            swap(&arr[min], &arr[i]);
    }
}
void displayArray(int arr[], int len)
{
    cout << "The array elements are: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << ", ";
    }
}

int main()
{
    int arr[] = {5, 2, 1, 4, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    selection(arr, len);
    displayArray(arr, len);
    return 0;
}