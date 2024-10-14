#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool increasingTriplet(vector<int> &nums)
{
    if (nums.size() < 3)
        return false;

    int firstValue = INT_MAX,
        secondValue = INT_MAX,
        firstIndex = 0,
        secondIndex = 0,
        size = nums.size();

    for (int i = 0; i < size; i++)
    {
        if (nums[i] <= firstValue)
        {
            firstValue = nums[i];
            firstIndex = i;
        }
        else if (nums[i] <= secondValue && i > firstIndex)
        {
            secondValue = nums[i];
            secondIndex = i;
        }
        else if (i > secondIndex)
        {
            return true;
        }
    }

    return false;
}