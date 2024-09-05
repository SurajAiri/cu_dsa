/*
Given a schedule containing the arrival and departure time of train in a station. Find the minimum no of platform needed to avoid the delay in trains's arrival.

arr[] = {
    9.00, 9.45, 9.55, 11.00, 15.00, 18.00
}

dep[] = {
    9.20, 12.00, 11.30, 11.50, 19.00, 20.00
}
*/

#include <iostream>
using namespace std;

int platformCount(float arr[], float dep[], int len)
{
    int tot = 0;
    int cur = 0;
    int depInd = 0;
    for (int i = 0; i < len; i++)
    {
        while (arr[i] > dep[depInd])
        {
            depInd++;
            cur--;
        }
        if (tot <= cur)
        {
            tot++;
            cur++;
        }
        else
        {
            cur++;
        }
    }
    return tot;
}

int main()
{
    float arr[] = {
        9.00, 9.45, 9.55, 11.00, 15.00, 18.00};

    float dep[] = {
        9.20,
        12.00,
        11.30,
        11.50,
        19.00,
        20.00};
    int len = 6;

    int plat = platformCount(arr, dep, len);
    cout << "The total no of platforms required is: " << plat << endl;
}