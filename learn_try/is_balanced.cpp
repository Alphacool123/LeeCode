#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Info
{
    bool balanced;
    int height;

    Info(bool balanced, int height) : balanced(balanced), height(height) {}
};

Info *process(TreeNode *root)
{
    if (root == nullptr)
        return new Info(true, 0);
    Info *leftInfo = process(root->left);
    Info *rightInfo = process(root->right);
    int height = max(leftInfo->height, rightInfo->height) + 1;
    bool balanced;
    if (leftInfo->balanced && rightInfo->balanced && abs(leftInfo->height - rightInfo->height) < 2)
        balanced = true;
    else
        balanced = false;
    return new Info(balanced, height);
}

// 核心思想，返回左右树高度和是否平衡
void is_balanced(TreeNode *root)
{
    Info *res = process(root);
    if (res->balanced)
        cout << "true";
    else
        cout << "false";
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
    TreeNode *a8 = new TreeNode(8);
    TreeNode *a9 = new TreeNode(9);
    a1->left = a2;
    a1->right = a3;
    a2->left = a4;
    a2->right = a5;
    a3->left = a6;
    a3->right = a7;
    a7->left = a8;
    a8->left = a9;
    is_balanced(a1);
    return 0;
}