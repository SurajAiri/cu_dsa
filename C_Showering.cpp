#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, s, m, l, r, low = 0;
    bool isYes = false;
    cin >> n >> s >> m;
    for (int j = 0; j < n; j++)
    {
        cin >> l >> r;
        if ((l - low) >= s)
        {
            isYes = true;
        }
        low = r;
    }
    if (m - r >= s || isYes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}