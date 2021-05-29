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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root != nullptr)
        {
            queue<TreeNode *> v1;
            queue<TreeNode *> v2;
            v1.push(root);
            vector<vector<int>> res;
            vector<int> temp;
            while (!v1.empty() || !v2.empty())
            {
                while (!v1.empty())
                {
                    if (v1.front()->left != nullptr)
                        v2.push(v1.front()->left);
                    if (v1.front()->right != nullptr)
                        v2.push(v1.front()->right);
                    temp.push_back(v1.front()->val);
                    v1.pop();
                }
                res.push_back(temp);
                temp.clear();
                v1 = v2;
                while (!v2.empty())
                    v2.pop();
            }
            return res;
        }
        return {};
    }
};

int main()
{
    TreeNode *a1 = new TreeNode(1);
    TreeNode *a2 = new TreeNode(2);
    TreeNode *a3 = new TreeNode(3);
    TreeNode *a4 = new TreeNode(4);
    TreeNode *a5 = new TreeNode(5);
    TreeNode *a6 = new TreeNode(6);
    TreeNode *a7 = new TreeNode(7);
    a1->left = a2;
    a1->right = a3;
    a2->left = a4;
    a2->right = a5;
    a3->left = a6;
    a3->right = a7;

    Solution a;
    vector<vector<int>> res = a.levelOrder(a7->left);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}