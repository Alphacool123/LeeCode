#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

struct Info
{
    int height;
    int max_distance;
    Info(int x, int y) : height(x), max_distance(y) {}
};

Info *max_dis(TreeNode *root)
{
    if (root == nullptr)
        return new Info(0, 0);
    Info *leftInfo = max_dis(root->left);
    Info *rightInfo = max_dis(root->right);
    int height = max(leftInfo->height, rightInfo->height) + 1;
    int distance = max(max(leftInfo->max_distance, rightInfo->max_distance), leftInfo->height + rightInfo->height + 1);
    return new Info(height, distance);
}

void process(TreeNode *root)
{
    cout << max_dis(root)->max_distance << endl;
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
    TreeNode *a9 = new TreeNode(9);
    a1->left = a2;
    a1->right = a3;
    a2->left = a4;
    a2->right = a5;
    a3->left = a6;
    a3->right = a7;
    a7->left = a8;
    a8->left = a9;

    process(a1);
    return 0;
}