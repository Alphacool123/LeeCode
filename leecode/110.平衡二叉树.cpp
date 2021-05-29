#include <iostream>
using namespace std;

/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
//
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    struct info
    {
        int height;
        bool is_balanced;
        info(int height, bool is_balanced) : height(height), is_balanced(is_balanced){};
    };

    info *process(TreeNode *root)
    {
        if (root == nullptr)
            return new info(0, true);

        info *leftinfo = process(root->left);
        info *rightinfo = process(root->right);
        int height = max(leftinfo->height, rightinfo->height) + 1;
        bool is_balanced = false;
        if (abs(leftinfo->height - rightinfo->height) <= 1 && leftinfo->is_balanced && rightinfo->is_balanced)
            is_balanced = true;
        return new info(height, is_balanced);
    }
    bool isBalanced(TreeNode *root)
    {
        return process(root)->is_balanced;
    }
};
// @lc code=end
