#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//  Definition for a binary tree node.
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
    vector<int> levelOrder(TreeNode *root)
    {
        vector<int> res;
        if (root != nullptr)
        {
            queue<TreeNode *> v;
            v.push(root);
            while (!v.empty())
            {
                root = v.front();
                v.pop();
                res.push_back(root->val);
                if (root->left != NULL)
                    v.push(root->left);
                if (root->right != NULL)
                    v.push(root->right);
            }
        }
        return res;
    }
};