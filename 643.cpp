#include <iostream>
#include <vector>

using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    int n = nums.size();
    double windowSum = 0;

    for (int i = 0; i < k; i++)
        windowSum += nums[i];

    double maxSum = windowSum;

    for (int i = k; i < n; i++)
    {
        windowSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum / k;
}

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    double result = findMaxAverage(nums, 4);

    cout << endl
         << "Result: " << result << endl;
    return 0;
}