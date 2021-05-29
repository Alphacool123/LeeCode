#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int max_len(TreeNode *root)
{

    if (root != nullptr)
    {
        queue<TreeNode *> node_queue;
        map<TreeNode *, int> node_level;
        node_queue.push(root);
        int curlevel = 1;
        int curnodelevel = 0;
        int max_length = 0;
        int node_nums = 0;
        node_level.insert(pair<TreeNode *, int>(root, curlevel));
        while (!node_queue.empty())
        {
            root = node_queue.front();
            curnodelevel = node_level[root];
            node_queue.pop();
            if (root->left != nullptr)
            {
                node_level.insert(pair<TreeNode *, int>(root->left, curnodelevel + 1));
                node_queue.push(root->left);
            }
            if (root->right != nullptr)
            {
                node_level.insert(pair<TreeNode *, int>(root->right, curnodelevel + 1));
                node_queue.push(root->right);
            }

            if (curnodelevel == curlevel)
                node_nums++;
            else
            {
                max_length = max(node_nums, max_length);
                node_nums = 1;
                curlevel++;
            }
            max_length = max(node_nums, max_length);
        }

        return max_length;
    }
    return 0;
}

int main()
{
    // 初始化树
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

    cout << max_len(a1) << endl;

    return 0;
}