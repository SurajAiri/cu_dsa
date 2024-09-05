// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int zeroRemainder(vector<int> arr, int k)
{
    map<int, int> rem;
    int zeroCount = 0, r;
    int maxc = 0, maxi = 0;
    for (int i : arr)
    {
        r = (i % k);
        if (r == 0)
            zeroCount++;
        else
            rem[k - r]++;
    }
    for (auto pair : rem)
    {
        // cout << pair.first << "|" << pair.second <<endl;
        maxi = pair.first + 1;
        if (pair.second > 1)
        {
            // cout << "sec" << pair.first << "|" << k * (pair.second -1)+maxi<<endl;
            maxi += k * (pair.second - 1);
        }

        maxc = max(maxi, maxc);
    }

    return max(zeroCount, maxc);
}

int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        cout << zeroRemainder(arr, k) << endl;
    }
    return 0;
}