#include <iostream>
#include <vector>
#include <algorithm>

void findFrequencies(std::vector<int> &arr)
{
    // Sort the array
    std::sort(arr.begin(), arr.end());

    // Traverse the sorted array and count frequencies
    int n = arr.size();
    for (int i = 0; i < n;)
    {
        int count = 1;
        while (i + count < n && arr[i] == arr[i + count])
        {
            count++;
        }
        std::cout << "Element " << arr[i] << " occurs " << count << " times." << std::endl;
        i += count; // Skip to the next distinct element
    }
}

int main()
{
    std::vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5};
    findFrequencies(arr);
    return 0;
}