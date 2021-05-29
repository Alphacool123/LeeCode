#include <iostream>
using namespace std;

//  Definition for a binary tree node.
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
        bool is_BST;
        int max_num;
        int min_num;
        info(bool x, int y, int z) : is_BST(x), max_num(y), min_num(z) {}
    };

    info *process(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        info *leftinfo = process(root->left);
        info *rightinfo = process(root->right);
        int max_num = root->val;
        int min_num = root->val;
        if (leftinfo != nullptr)
            max_num = max(max(leftinfo->max_num, rightinfo->max_num), root->val);
        if (rightinfo != nullptr)
            min_num = min(min(leftinfo->min_num, rightinfo->min_num), root->val);

        bool is_BST = false;
        if ((leftinfo == nullptr ? true : leftinfo->is_BST) && (rightinfo == nullptr ? true : rightinfo->is_BST) &&
            (leftinfo == nullptr ? true : leftinfo->max_num < root->val) && (rightinfo == nullptr ? true : rightinfo->min_num > root->val))
            is_BST = true;
        return new info(is_BST, max_num, min_num);
    }
    bool isValidBST(TreeNode *root)
    {
        return process(root)->is_BST;
    }
};

int main()
{
    TreeNode *a1 = new TreeNode(1);
    TreeNode *a2 = new TreeNode(1);
    // TreeNode *a3 = new TreeNode(3);
    a1->left = a2;
    // a1->right = a3;
    Solution a;
    cout << (a.isValidBST(a1) ? "true" : "false");
    return 0;
}