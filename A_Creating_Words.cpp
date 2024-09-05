#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string s1, s2;
    for (int i = 0; i < t; i++)
    {
        cin >> s1 >> s2;
        cout << s2[0] << s1.substr(1, 2) << " " << s1[0] << s2.substr(1, 2) << endl;
    }
}