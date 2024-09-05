#include <bits/stdc++.h>
using namespace std;

/*
Develop a program to implement power function to determine a^b and time complexity should be O(log(n)).
*/

// brute force
unsigned long long power(int num, int p)
{
    if (p < 1)
        return 1;
    if (p == 1)
        return num;
    return num * power(num, p - 1);
}

// binary exponential
unsigned long long powerBinExp(int num, int p)
{
    if (p < 1)
        return 1;
    if (p == 1)
        return num;
    if (p % 2 == 0)
        return powerBinExp(num, p / 2) * powerBinExp(num, p / 2);
    return num * powerBinExp(num, p / 2) * powerBinExp(num, p / 2);
}

// binary exponential optimized
unsigned long long powerBinExpOpt(int num, int p)
{
    if (p < 1)
        return 1;
    if (p == 1)
        return num;
    int temp = powerBinExp(num, p / 2);
    if (p % 2 == 0)
        return temp * temp;
    return num * temp * temp;
}

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
    cout << pow(990, 40) << endl;
    cerr << "time: " << (double)clock() / (double)CLOCKS_PER_SEC << endl;
    cout << powerBinExpOpt(990, 40) << endl;
    cerr << "time: " << (double)clock() / (double)CLOCKS_PER_SEC << endl;
    cout << powerBinExp(990, 40) << endl;
    cerr << "time: " << (double)clock() / (double)CLOCKS_PER_SEC << endl;
    cout << power(990, 40) << endl;
    cerr << "time: " << (double)clock() / (double)CLOCKS_PER_SEC << endl;

    // final power mod
    cout << "\nFinal function: " << endl;
    long long n, p, m;
    n = 10;
    p = 20;
    m = 1e9 + 7;

    cout << powMod(n, p, m) << endl;

    return 0;
}