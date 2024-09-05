// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, len;
    cin >> t;
    while (t--)
    {
        cin >> len;
        vector<int> v(len);
        int max_v = v[0];
        bool sorted = true, o1 = true;
        for (int i = 1; i < len; i++)
            cin >> v[i];
        for (int i = 0; i < len; i++)
        {
            if (max_v < v[i])
            {
                sorted = false;
            }
        }
    }
    return 0;
}