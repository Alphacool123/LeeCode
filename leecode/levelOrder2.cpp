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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        vector<int> temp;
        if (root != nullptr)
        {
            queue<TreeNode *> v1;
            queue<TreeNode *> v2;
            v1.push(root);
            while (!v1.empty() || !v2.empty())
            {
                while (!v1.empty())
                {
                    root = v1.front();
                    v1.pop();
                    temp.push_back(root->val);
                    if (root->left != nullptr)
                        v2.push(root->left);
                    if (root->right != nullptr)
                        v2.push(root->right);
                }
                res.push_back(temp);
                temp.clear();
                v1.swap(v2);
            }
        }
        return res;
    }
};