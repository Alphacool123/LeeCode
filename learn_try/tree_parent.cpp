#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right), parent(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode *parent) : val(x), left(left), right(right), parent(parent) {}
};

void next_node(TreeNode *node)
{
    if (node->right != nullptr)
    {
        node = node->right;
        while (node->left != nullptr)
            node = node->left;
        cout << node->val;
    }
    else
    {
        TreeNode *pre = node;
        node = node->parent;
        // 限制是头节点之上，边界考虑
        while (node != nullptr || node->right == pre)
        {
            pre = node;
            node = node->parent;
        }
        cout << node->val;
    }
}

int main()
{
    // 初始化一棵树
    TreeNode *a1 = new TreeNode(1);
    TreeNode *a2 = new TreeNode(2);
    TreeNode *a3 = new TreeNode(3);
    TreeNode *a4 = new TreeNode(4);
    TreeNode *a5 = new TreeNode(5);
    TreeNode *a6 = new TreeNode(6);
    TreeNode *a7 = new TreeNode(7);
    TreeNode *a8 = new TreeNode(8);
    a1->left = a2;
    a1->right = a3;
    a2->parent = a1;
    a2->left = a4;
    a4->parent = a2;
    a2->right = a5;
    a5->parent = a2;
    a3->parent = a1;
    a3->left = a6;
    a6->parent = a3;
    a3->right = a7;
    a7->parent = a3;
    a4->right = a8;
    a8->parent = a4;

    next_node(a2);

    return 0;
}