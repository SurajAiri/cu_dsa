#include <bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> &vec, int k)
{
    int beg = 0, end = vec.size() - 1, mid;
    while (beg <= end)
    {
        mid = beg + (end - beg) / 2;
        // mid = (beg + end) / 2;
        if (vec[mid] == k)
            break;
        else if (k < vec[mid])
            end = mid - 1;
        else
            beg = mid + 1;
    }
    if (mid < vec.size() - 1)
        return vec[mid + 1];

    return vec[vec.size() - 1];
}

int main()
{
    vector<int> v = {1, 2, 3, 5, 6, 7, 8, 9};
    cout << lowerbound(v, 4) << endl;
}