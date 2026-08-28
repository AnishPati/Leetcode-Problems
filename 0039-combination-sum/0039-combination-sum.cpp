class Solution {
public:
    void fun(vector<int> &a, int n, int idx, vector<int> &diary, vector<vector<int>> &res, int tar, int sum){
        if(idx==n){
            if(sum==tar){
                res.push_back(diary);
            }
            return;
        }
        fun(a,n,idx+1,diary,res,tar,sum);
        if(a[idx]+sum<=tar){
            diary.push_back(a[idx]);
            sum+=a[idx];
            fun(a,n,idx,diary,res,tar,sum);
            diary.pop_back();
            sum-=a[idx];
            return;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum=0, idx=0;
        vector<int> diary;
        vector<vector<int>> res;
        fun(candidates,n,idx,diary,res,target,sum);
        return res;
    }
};