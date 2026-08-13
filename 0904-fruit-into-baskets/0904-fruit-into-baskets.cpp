class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int high = 0;
        int n = fruits.size();
        int res = 0;                     // INT_MIN also unsafe if window logic ever fails to update — 0 is the correct baseline here
        unordered_map<int,int> f;

        for(high=0;high<n;high++){
            f[fruits[high]]++;
            while(f.size()>2)
            {
                f[fruits[low]]--;
                if(f[fruits[low]]==0){
                    f.erase(fruits[low]);   // fixed: erase the actual key, not its (now-zero) value
                }
                low++;
            }
            int len = high-low+1;           // fixed: inclusive window length
            res = max(len,res);
        }
        return res;
    }
};