#include <bits/stdc++.h>
using namespace std;

long long hamburger(int &rb, int &rs, int &rc, int &nb, int &ns, int &nc, int &pb, int &ps, int &pc, long long &money)
{
    long long low = 0, mid = 1, high = -1, prev = 0;
    long long pay = 0;
    if (rb == 0)
        nb = 0;
    if (rs == 0)
        ns = 0;
    if (rc == 0)
        nc = 0;
    while (low <= high || high == -1)
    {
        mid = (high == -1) ? mid * 2 : low + (high - low) / 2;
        cout << "mid" << mid << endl;
        pay = (rb * mid - nb) * pb + (rs * mid - ns) * ps + (rc * mid - nc) * pc;
        cout << "pay" << pay << endl;

        if (pay == money)
            return mid;
        else if (pay < money)
        {
            prev = mid;
            cout << "prev " << prev << endl;
            low = mid;
        }
        else
        {
            cout << "high" << endl;
            high = mid;
        }
    }
    // cout << "rb " << rb << " rs " << rs << " rc " << rc << endl;
    // cout << "nb " << nb << " ns " << ns << " nc " << nc << endl;
    // cout << "pb " << pb << " ps " << ps << " pc " << pc << endl;
    // cout << "money " << money << endl;

    // mid = 7;
    // pay = (rb * mid - nb) * pb + (rs * mid - ns) * ps + (rc * mid - nc) * pc;
    // cout << "Pay " << pay << endl;

    return prev;
}

int main()
{
    string st;
    cin >> st;
    int rb = 0, rs = 0, rc = 0;
    for (auto ch : st)
        if (ch == 'B')
            rb++;
        else if (ch == 'S')
            rs++;
        else
            rc++;

    // in the kitchen
    int nb, ns, nc;
    cin >> nb >> ns >> nc;

    // price of each ingredient
    int pb, ps, pc;
    cin >> pb >> ps >> pc;

    // money
    long long r;
    cin >> r;

    cout << hamburger(rb, rs, rc, nb, ns, nc, pb, ps, pc, r);
}