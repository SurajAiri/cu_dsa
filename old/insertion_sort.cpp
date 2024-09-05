#include <iostream>
using namespace std;

void insertion(int *arr, int len)
{
    int key, j;
    for (int i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertion(arr, len);
    displayArray(arr, len);
    return 0;
}