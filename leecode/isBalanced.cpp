#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    struct info
    {
        bool is_balanced;
        int height;
        info(bool x, int y) : is_balanced(x), height(y) {}
    };

    info *process(TreeNode *root)
    {
        if (root == NULL)
            return new info(true, 0);
        info *left_tree = process(root->left);
        info *right_tree = process(root->right);
        int height = max(left_tree->height, right_tree->height) + 1;
        bool is_balanced = false;
        if (left_tree->is_balanced && right_tree->is_balanced && abs(left_tree->height - right_tree->height) < 2)
            is_balanced = true;
        return new info(is_balanced, height);
    }
    bool isBalanced(TreeNode *root)
    {
        return process(root)->is_balanced;
    }
};
