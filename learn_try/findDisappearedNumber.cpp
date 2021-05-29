#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> v1;
        sort(nums.begin(), nums.end());

        for (int i = 1; i <= nums.size(); i++)
        {
            v1.push_back(i);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
            }
        }
    }
};

int main()
{

    return 0;
}