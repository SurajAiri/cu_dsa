#include <bits/stdc++.h>
using namespace std;

map<int, int> findFreqBrut(vector<int> &arr)
{
    map<int, int> freq;
    int c = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (freq.find(arr[i]) != freq.end())
            continue;
        c = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
                c++;
        }
        freq[arr[i]] = c;
    }
    return freq;
}

map<int, int> findFreqSort(vector<int> &arr)
{

    map<int, int> freq;
    sort(arr.begin(), arr.end());
    int c = 0, r = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (r == arr[i])
        {
            c++;
        }
        else
        {
            freq[r] = c;
            r = arr[i];
            c = 1;
        }
    }
    freq[r] = c;

    return freq;
}

map<int, int> findFreqMap(vector<int> &arr)
{
    map<int, int> freq;
    for (auto a : arr)
    {
        freq[a]++;
    }
    return freq;
}

void printMap(map<int, int> mp)
{
    for (auto p : mp)
        cout << p.first << " : " << p.second << endl;
}

int main()
{
    vector<int> arr = {1, 1, 5, 2, 1, 5, 3, 6, 6, 3, 4, 2};

    int choice = 0;
    cout << "Enter choice: 0-BruteForce, 1-Sorted, 2-Map" << endl;
    cin >> choice;
    switch (choice)
    {
    case 0:
        cout << "BruteForce" << endl;
        printMap(findFreqBrut(arr));
        break;

    case 1:
        cout << "Sorted" << endl;
        printMap(findFreqSort(arr));
        break;

    case 2:
        cout << "Map" << endl;
        printMap(findFreqMap(arr));
        break;

    default:
        cout << "Invalid choice" << endl;
        break;
    }

    return 0;
}