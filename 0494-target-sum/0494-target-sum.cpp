class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int i,j;
        vector<vector<int>> dp(n+1);
        for(i=0;i<=n;i++){
            vector<int> t(target+1,-1);
            dp[i] = t;
        }
        for(j=0;j<=target;j++){
            dp[n][j] = 0; //base case else
        }
        dp[n][0] = 1; //base case if

        for(i=n-1;i>=0;i--){
            for(j=0;j<=target;j++){
                if(arr[i]>j){
                    dp[i][j] = dp[i+1][j];
                }else{
                    dp[i][j] = dp[i+1][j-arr[i]] + dp[i+1][j];
                }
            }
        }
        return dp[0][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum+nums[i];
        }
        if(abs(target)>sum) return 0;
        if((sum+target)%2!=0) return 0;
        return perfectSum(nums,((sum+target)/2));
    }
};