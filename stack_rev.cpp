#include <bits/stdc++.h>
using namespace std;

void bottom_push_stack(stack<int> &s, int i)
{
    if (s.empty())
        s.push(i);
    else
    {
        int t = s.top();
        s.pop();
        bottom_push_stack(s, i);
        s.push(t);
    }
}
void revStack(stack<int> &s)
{
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    revStack(s);
    bottom_push_stack(s, x);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    revStack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}