class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        int i,j;
        vector<vector<int>> dp(n+1);
        for(i=0;i<=n;i++){
            vector<int> t(sum+1,-1);
            dp[i] = t;
        }
        for(j=0;j<=sum;j++){
            dp[n][j] = 0; //base case else
        }
        dp[n][0] = 1; //base case if
       
        for(i=n-1;i>=0;i--){
            for(j=0;j<=sum;j++){
                if(arr[i]>j){
                    dp[i][j] = dp[i+1][j];
                }else{
                    dp[i][j] = dp[i+1][j-arr[i]] or dp[i+1][j];
                }
            }
        }
        return dp[0][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
        } 
        if(sum%2!=0){
            return false;
        }
        return isSubsetSum(nums, (sum/2));     
    }
};