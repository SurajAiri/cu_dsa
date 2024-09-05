#include <iostream>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    vector<pair<int, int>> st(heights.size());
    int area = heights[0], ind, cursor = 0;
    st[0] = {heights[0], 0};

    for (int i = 1; i < heights.size(); i++)
    {
        ind = i;
        while (cursor >= 0 && st[cursor].first > heights[i])
        {
            ind = st[cursor].second;
            cursor--;
        }
        st[++cursor] = make_pair(heights[i], ind);

        for (int j = 0; j <= cursor; j++)
        {
            int t = st[j].first * (i + 1 - st[j].second);
            if (t > area)
                area = t;
        }
    }
    return area;
}