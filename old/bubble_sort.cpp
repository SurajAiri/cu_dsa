#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
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
    bubble(arr, len);
    displayArray(arr, len);
    return 0;
}