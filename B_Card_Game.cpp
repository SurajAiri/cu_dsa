#include <bits/stdc++.h>
using namespace std;

bool check(int &a, int &b, int &c, int &d)
{
    int po = 0;
    if (a > c)
        po++;
    else if (a < c)
        po--;
    if (b > d)
        po++;
    else if (b < d)
        po--;

    return po > 0;
}

int main()
{
    int t, a, b, c, d, win;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        win = 0;
        cin >> a >> b >> c >> d;
        win += check(a, b, c, d);
        win += check(a, b, d, c);
        win += check(b, a, c, d);
        win += check(b, d, d, c);
        cout << win << endl;
    }
    return 0;
}