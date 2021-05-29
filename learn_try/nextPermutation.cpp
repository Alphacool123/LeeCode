#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums)
    {


        int flag = 0;
        int n = nums.size();
        for(int i=n-1;i>0;i--){
            for(int j=i-i;j>=0;j--)
            {
                if(nums[i]>nums[j])
                {
                    int a = nums[i];
                    nums[i] = nums[j];
                    nums[j] = a;
                    flag = 1;
                }


            }
            if (flag==1) break;
        }

        if (flag==0)
        {
            sort(nums.begin(),nums.end());
        }

        return nums;


    }
    
};