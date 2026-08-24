class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int be = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            int v1 = be+nums[i];
            int v2 = nums[i];
            be = max(v1,v2);
            res = max(res,be);
        }
        return res;
    }
};