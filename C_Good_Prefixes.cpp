// #include <bits/stdc++.h>
// using namespace std;

// int solve(vector<int> &vec)
// {
//     int ans = 0, max_val = 0;
//     long long sum = 0;

//     if (vec[0] == 0)
//         ans++;

//     max_val = vec[0];
//     // sort(vec.begin(), vec.end());
//     for (int i = 1; i < vec.size(); i++)
//     {
//         // sum += vec[i - 1];
//         // if (sum == vec[i])
//         //     ans++;
//         if (vec[i] > max_val)
//         {
//             sum += max_val;
//             max_val = vec[i];
//         }
//         else
//         {
//             sum += vec[i];
//         }
//         if (sum == max_val)
//             ans++;
//     }
//     return ans;
// }

// int main()
// {
//     int t, n;
//     cin >> t;
//     for (int i = 0; i < t; i++)
//     {
//         cin >> n;
//         vector<int> ve(n);
//         for (int j = 0; j < n; j++)
//             cin >> ve[j];

//         cout << solve(ve) << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a;
    cin >> t;

    while (t--)
    {
        int max = 0, count = 0;
        long long sum = 0;
        cin >> n;
        while (n--)
        {
            cin >> a;
            if (a < sum)
            {
                sum += a;
            }
            else
            {
                max = a;
                sum += a;
            }
            if ((sum - max) == max)
            {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}