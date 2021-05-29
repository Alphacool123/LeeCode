#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        mid_travel(root, result);
        return result;
    }

    void mid_travel(TreeNode *root, vector<int> &result)
    {
        if (root == nullptr)
            return;
        mid_travel(root->left, result);
        result.push_back(root->val);
        mid_travel(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root != nullptr)
        {
            stack<TreeNode *> v;
            while (!v.empty() || root != nullptr)
            {
                if (root != nullptr)
                {
                    v.push(root);
                    root = root->left;
                }
                else
                {
                    root = v.top();
                    v.pop();
                    result.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return result;
    }
};