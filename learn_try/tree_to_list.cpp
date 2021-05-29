#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void Front_travel(vector<string> &res, TreeNode *root)
{
    if (root == nullptr)
    {
        res.push_back("null");
        return;
    }
    string str = to_string(root->val);
    res.push_back(str);
    Front_travel(res, root->left);
    Front_travel(res, root->right);
}

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

    vector<string> result;
    Front_travel(result, a1);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}