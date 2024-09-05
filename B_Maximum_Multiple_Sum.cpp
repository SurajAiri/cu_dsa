#include <bits/stdc++.h>
using namespace std;

int firstSum(int k)
{
    return k * (k + 1) / 2;
}

int solve(int n)
{
    int ans = 0, k, sum = 0;
    for (int i = 2; i <= n; i++)
    {
        k = n / i;
        if (sum < firstSum(k) * i)
        {
            sum = firstSum(k) * i;
            ans = i;
        }
    }
    return ans;
}
int main()
{
    int t, n, ans = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}