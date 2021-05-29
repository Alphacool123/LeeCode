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

// 递归方法的前中后序遍历
void Front_travel(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    Front_travel(root->left);
    Front_travel(root->right);
}

void mid_travel(TreeNode *root)
{
    if (root == nullptr)
        return;
    mid_travel(root->left);
    cout << root->val << " ";
    mid_travel(root->right);
}

void back_travel(TreeNode *root)
{
    if (root == nullptr)
        return;
    back_travel(root->left);
    back_travel(root->right);
    cout << root->val << " ";
}

// 非递归方法的前中后序遍历
void Front_travel_(TreeNode *root)
{
    stack<TreeNode *> v;
    if (root != nullptr)
    {
        v.push(root);
        while (!v.empty())
        {
            root = v.top();
            cout << root->val << " ";
            v.pop();
            if (root->right != nullptr)
                v.push(root->right);
            if (root->left != nullptr)
                v.push(root->left);
        }
    }
}

void Mid_travel_(TreeNode *root)
{
    stack<TreeNode *> v;
    if (root != nullptr)
    {
        // while中条件很重要
        while (!v.empty() || root != nullptr)
        {
            // 先将所有左边节点遍历，保存在栈中
            if (root != nullptr)
            {
                v.push(root);
                root = root->left;
            }
            // 如果左边没有节点了，弹出栈的节点为头节点，并遍历右树
            else
            {
                root = v.top();
                v.pop();
                cout << root->val << " ";
                root = root->right;
            }
        }
    }
}

void Back_travel_(TreeNode *root)
{
    stack<TreeNode *> v;
    vector<int> t;
    if (root != nullptr)
    {
        v.push(root);
        while (!v.empty())
        {
            root = v.top();
            t.push_back(root->val);
            v.pop();
            if (root->left != nullptr)
                v.push(root->left);
            if (root->right != nullptr)
                v.push(root->right);
        }
    }
    for (int i = t.size() - 1; i >= 0; i--)
    {
        cout << t[i] << " ";
    }
}

// 非递归后序遍历
void Back_travel_1(TreeNode *root)
{
    if (root != nullptr)
    {
        stack<TreeNode *> v;
        TreeNode *c;
        v.push(root);
        while (!v.empty())
        {
            c = v.top();
            // c->left!=nullptr是判断是否有根节点，
            if (c->left != nullptr && c->left != root && c->right != root)
                v.push(c->left);
            else if (c->right != nullptr && c->right != root)
                v.push(c->right);
            else
            {
                root = c;
                cout << root->val << " ";
                v.pop();
            }
        }
    }
}

// 按层遍历
void level_travel(TreeNode *root)
{
    queue<TreeNode *> v;
    TreeNode *a;
    if (root != nullptr)
    {
        v.push(root);
        while (!v.empty())
        {
            a = v.front();
            cout << a->val << " ";
            v.pop();
            if (a->left != nullptr)
                v.push(a->left);
            if (a->right != nullptr)
                v.push(a->right);
        }
    }
}

int max_length(TreeNode *root)
{
    if (root != nullptr)
    {
        queue<TreeNode *> v;
        map<TreeNode *, int> Nodelevel;
        v.push(root);
        Nodelevel.insert(pair<TreeNode *, int>(root, 1));
        int curlevel = 1;
        int curlevelNodes = 0;
        int max_len = 0;
        while (!v.empty())
        {
            root = v.front();
            v.pop();
            int curNodelevel = Nodelevel[root];
            if (root->left != nullptr)
            {
                v.push(root->left);
                Nodelevel.insert(pair<TreeNode *, int>(root->left, curNodelevel + 1));
            }
            if (root->right != nullptr)
            {
                v.push(root->right);
                Nodelevel.insert(pair<TreeNode *, int>(root->right, curNodelevel + 1));
            }

            if (curNodelevel == curlevel)
                curlevelNodes++;
            else
            {
                max_len = max(curNodelevel, max_len);
                curlevelNodes = 1;
                curlevel++;
            }
        }
        return max_len;
    }
    return 0;
}

// 树的序列化，按照先序、中序和后续的顺序遍历
// 前序递归序列化
void tree_to_list(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "null"
             << " ";
        return;
    }
    cout << root->val << " ";
    tree_to_list(root->left);
    tree_to_list(root->right);
}

// 前序非递归序列化
void tree_to_list_(TreeNode *root)
{
    if (root != nullptr)
    {
        stack<TreeNode *> v;
        v.push(root);
        while (!v.empty())
        {
            root = v.top();
            v.pop();
            if (root == nullptr)
                cout << "null"
                     << " ";
            else
            {
                cout << root->val << " ";
                v.push(root->right);
                v.push(root->left);
            }
        }
    }
}

// 打印二叉树
void print_node(TreeNode *node, int height)
{
    for (int i = 0; i < height; i++)
        cout << "      ";
    cout << node->val << endl;
}
void print_tree(TreeNode *root, int height)
{
    if (root == nullptr)
        return;
    print_tree(root->right, height + 1);
    print_node(root, height);
    print_tree(root->left, height + 1);
}

// 折纸凹凸痕迹
void print_paper(int height, int n, bool print)
{
    if (height > n)
        return;
    print_paper(height + 1, n, true);
    if (print)
    {
        cout << "凹"
             << " ";
    }
    else
        cout << "凸"
             << " ";

    print_paper(height + 1, n, false);
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

    print_paper(1, 5, true);

    return 0;
}