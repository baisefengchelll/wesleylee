/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p = 0 ;
        int q = nums.size()-1;
        while(p <= q){
            if(nums[q] == val){
                q--;
                continue;
            }
            if(nums[p] == val){
                nums[p] = nums[q];
                q--;
            }
            p++;
        }
        return p;
    }
};
// @lc code=end

