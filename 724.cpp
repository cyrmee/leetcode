#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int> &nums)
{
    int count = nums.size(), leftSum = 0, rightSum = 0;
    vector<int> sumLeft(count), sumRight(count);

    for (size_t i = 1; i < count; i++)
    {
        leftSum += nums[i - 1];
        sumLeft[i] = leftSum;
    }

    for (size_t i = count - 1; i > 0; i--)
    {
        rightSum += nums[i];
        sumRight[i - 1] = rightSum;
    }

    for (size_t i = 0; i < count; i++)
    {
        if (sumLeft[i] == sumRight[i])
            return i;
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << pivotIndex(nums) << endl;
    return 0;
}