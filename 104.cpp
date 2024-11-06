#include <iostream>
#include <stack>
#include <utility>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int maxDepth = 0;
    stack<pair<TreeNode *, int>> s;
    s.push({root, 1});

    while (!s.empty())
    {
        auto [node, depth] = s.top();
        s.pop();

        cout << node->val << " ";
        maxDepth = max(maxDepth, depth);

        if (node->right)
            s.push({node->right, depth + 1});
        if (node->left)
            s.push({node->left, depth + 1});
    }

    return maxDepth;
}