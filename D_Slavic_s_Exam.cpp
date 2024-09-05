#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, vac, ind;
    cin >> t;
    string s, s2;

    for (int i = 0; i < t; i++)
    {
        cin >> s >> s2;
        vac = 0, ind = 0;
        vector<char> ve(s.size());

        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '?' || s2[ind] == s[j])
            {
                // if (ind < s2.size())
                //     cout << s2[ind];
                // else
                //     cout << 'a';
                if (ind < s2.size())
                    ve.emplace_back(s2[ind]);
                else
                    ve.emplace_back('a');
                ind++;
            }
            else
            {

                ve.emplace_back(s[j]);
            }
            // cout << s[j];
        }
        if (ind >= s2.size())
        {
            cout << "YES" << endl;
            for (auto a : ve)
                cout << a;
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}