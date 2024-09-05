#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string rev(string str)
{
    stack<int> stack;
    int t;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            // cout << i;
            stack.push(i);
        }
        else if (str[i] == ')')
        {
            t = stack.top();
            stack.pop();
            cout << t << "|" << i << endl;
            // string st = str.substr(t + 1, i - t - 1);
            reverse(str.begin() + t + 1, str.begin() + i - t - 1);
        }
    }
    cout << str;
}

int main()
{
    rev("Sr(raja)");
    // string str = "Suraj";
    // reverse(str.begin() + , str.end());
    // cout
    //     << str;
    return 0;
}
