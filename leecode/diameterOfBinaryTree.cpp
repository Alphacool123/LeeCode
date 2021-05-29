#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

class Solution
{

public:
    struct info
    {
        int height;
        int max_routes;
        info(int x, int y) : height(x), max_routes(y) {}
    };

    info *process(TreeNode *root)
    {
        if (root == nullptr)
            return new info(0, 0);
        info *leftinfo = process(root->left);
        info *rightinfo = process(root->right);
        int height = max(leftinfo->height, rightinfo->height) + 1;
        int max_routes = max(max(leftinfo->max_routes, rightinfo->max_routes), leftinfo->height + rightinfo->height);
        return new info(height, max_routes);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        return process(root)->max_routes;
    }
};

int main()
{

    return 0;
}