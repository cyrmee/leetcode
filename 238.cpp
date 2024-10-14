#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int size = nums.size();
    vector<int> products(size, 1);

    for (int i = 1; i < size; i++)
    {
        products[i] = products[i - 1] * nums[i - 1];
    }

    int rightProduct = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        products[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return products;
}