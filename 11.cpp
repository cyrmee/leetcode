#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height)
{
    int left = 0,
        right = height.capacity() - 1,
        maxArea = 0,
        minHeight = 0,
        area = 0;

    while (left < right)
    {
        minHeight = min(height[left], height[right]);
        area = minHeight * (right - left);

        if (area > maxArea)
            maxArea = area;
        if (minHeight == height[left])
            left++;
        else
            right--;
    }

    return maxArea;
}

int main()
{
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(heights) << endl;
    return 0;
}