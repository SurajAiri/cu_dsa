#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {4, 8, 5, 2, 25};
    int len = arr.size();
    vector<int> res(len);

    int sm = arr[len - 1];
    res[len - 1] = -1;
    for (int i = len - 2; i >= 0; i--)
    {
        if (arr[i] > sm)
            res[i] = sm;
        else
            res[i] = -1;

        if (sm > arr[i])
            sm = arr[i];
    }

    cout << "Printing Result " << endl;
    for (int i = 0; i < len; i++)
        cout << arr[i] << " | " << res[i] << endl;
    return 0;
}