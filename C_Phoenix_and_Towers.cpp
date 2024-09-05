#include <bits/stdc++.h>
using namespace std;

int n, x, m, temp;
pair<int, int> p;
void solve()
{
    cout << "YES" << endl;
    cin >> n >> m >> x;
    set<pair<int, int>> s;
    for (int i = 0; i < m; i++)
        s.insert({0, i + 1});

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        p = *s.begin();
        s.erase(p);
        p.first += temp;
        s.insert(p);
        cout << p.second << ' ';
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}