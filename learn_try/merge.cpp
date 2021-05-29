#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int p1 = 0, p2 = 0;
    vector<int> v1(m + n);
    int cur;
    while (p1 < m || p2 < n)
    {
        if (p1 == m)
        {
            cur = nums2[p2++];
        }
        else if (p2 == n)
        {
            cur = nums1[p1++];
        }
        else if (nums1[p1] < nums2[p2])
        {
            cur = nums1[p1++];
        }
        else
        {
            cur = nums2[p2++];
        }
        v1[p1 + p2 - 1] = cur;
    }
    for (int i = 0; i != m + n; ++i)
    {
        nums1[i] = v1[i];
    }
}

void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int p1 = m - 1, p2 = n - 1;
    int tail = m + n - 1;
    int cur;
    while (p1 >= 0 || p2 >= 0)
    {
        if (p1 == -1)
        {
            cur = nums2[p2--];
        }
        else if (p2 == -1)
        {
            cur = nums1[p1--];
        }
        else if (nums1[p1] > nums2[p2])
        {
            cur = nums1[p1--];
        }
        else
        {
            cur = nums2[p2--];
        }
        nums1[tail--] = cur;
    }
}

int main()
{
    vector<int> v1{1, 2, 3, 0, 0, 0};
    vector<int> v2{2, 5, 6};

    merge2(v1, 3, v2, 3);
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << endl;
    }
    return 0;
}