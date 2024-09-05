#include <bits/stdc++.h>
using namespace std;

long long int powMod(long long int num, long long int p, long long int M)
{
    if (p < 1)
        return 1;
    if (p == 1)
        return num % M;
    long long temp = powMod(num, p / 2, M);
    temp = (temp * temp) % M;
    if (p % 2 == 0)
        return temp;
    return ((num % M) * temp) % M;
}

int main()
{

    // final power mod
    cout << "Final power function: " << endl;
    long long n, p, m;
    n = 10;
    p = 20;
    m = 1e9 + 7;

    cout << powMod(n, p, m) << endl;

    return 0;
}