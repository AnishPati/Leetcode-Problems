class Solution {
public:
    int minSum(vector<int> &nums){
        int be = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            int v1 = nums[i];
            int v2 = be+nums[i];
            be = min(v1,v2);
            res = min(res,be);
        }
        return res;
    }
    int maxSum(vector<int> &nums){
        int be = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            int v1 = nums[i];
            int v2 = be+nums[i];
            be = max(v1,v2);
            res = max(res,be);
        }
        return res;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        
        int minS = abs(minSum(nums));
        int maxS = abs(maxSum(nums));
        int res = max(minS,maxS);
        return res;
    }
};