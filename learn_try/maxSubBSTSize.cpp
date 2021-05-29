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

struct info
{
    int maxSubbstsize;
    bool is_allbst;
    int max_node;
    int min_node;
    info(int x, bool y, int m, int n) : maxSubbstsize(x), is_allbst(y), max_node(m), min_node(n) {}
};

info *max_SubBTS_size(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    info *leftinfo = max_SubBTS_size(root->left);
    info *rightinfo = max_SubBTS_size(root->right);

    int max_node = root->val;
    int min_node = root->val;
    if (leftinfo != nullptr)
    {
        max_node = max(max_node, leftinfo->max_node);
        min_node = min(min_node, leftinfo->min_node);
    }
    if (rightinfo != nullptr)
    {
        max_node = max(max_node, rightinfo->max_node);
        min_node = min(min_node, rightinfo->min_node);
    }
    int maxSubbstsize = 0;
    if (leftinfo != nullptr)
    {
        maxSubbstsize = leftinfo->maxSubbstsize;
    }
    if (rightinfo != nullptr)
    {
        maxSubbstsize = max(maxSubbstsize, rightinfo->maxSubbstsize);
    }
    bool is_allbst = false;
    if ((leftinfo == nullptr ? true : leftinfo->is_allbst) && (rightinfo == nullptr ? true : rightinfo->is_allbst) && (leftinfo == nullptr ? true : leftinfo->max_node < root->val) && (rightinfo == nullptr ? true : rightinfo->min_node > root->val))
    {
        maxSubbstsize = (leftinfo == nullptr ? 0 : leftinfo->maxSubbstsize) + (rightinfo == nullptr ? 0 : rightinfo->maxSubbstsize) + 1;
        is_allbst = false;
    }

    return new info(maxSubbstsize, is_allbst, max_node, min_node);
}