class Solution {
public:
    int maxSum1(vector<int> &nums){
        int be = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            int v1 = nums[i];
            int v2 = be+nums[i];
            be = max(v1,v2);
            res = max(be,res);
        }
        return res;
    }
    int maxSum2(vector<int> &nums){
        int be = nums[0];
        int res = nums[0];
        int total = nums[0];
        for(int i=1;i<nums.size();i++){
            int v1 = nums[i];
            int v2 = be+nums[i];
            be = min(v1,v2);
            res = min(be,res);
            total+=nums[i];
        }
        // for(int j=0;j<nums.size();j++){
        //     total += nums[j];
        // }
        return (total-res);
    }
    int maxSubarraySumCircular(vector<int>& nums) {
       int max1 = maxSum1(nums);
       if(max1<0) return max1;
       int max2 = maxSum2(nums);
       int res = max(max1,max2);
       return res;
    }
};