// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int permutation(int arr[], int len)
{
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i == j)
                continue;
            cout << "(" << arr[i] << " , " << arr[j] << " ), ";
            cnt++;
        }
    }
    return cnt;
}

int fact(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * fact(n - 1);
}

int pCount(int n, int r)
{
    return fact(n) / fact(n - r);
}

int main()
{
    int arr[] = {5, 1, 2};
    int cnt = permutation(arr, 3);
    int pCnt = pCount(3, 2);
    cout << endl
         << "Total number of permutations: " << cnt << "||" << pCnt << endl;
    return 0;
}