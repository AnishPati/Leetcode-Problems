class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> neg;
        vector<int> pos;

        for (int i=0;i<size;i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }else{
                pos.push_back(nums[i]);
            }
        }
        if (neg.size()==0){ //no -ve
            for(int i=0;i<pos.size();i++){
                pos[i] = pos[i]*pos[i];
            }
            return pos;
        }
        if (pos.size()==0){ //no +ve
            for(int i=0;i<neg.size();i++){
                neg[i] = neg[i]*neg[i];
            }
            reverse(neg.begin(),neg.end());   // moved OUTSIDE the loop
            return neg;
        }

        int i = 0;
        int j = 0;
        int id = 0;
        int n = neg.size();
        int m = pos.size();
        vector<int> res(n+m);

        for (int k=0;k<n;k++){                // separate loop variable
            neg[k] = neg[k]*neg[k];
        }
        reverse(neg.begin(),neg.end());

        for(int k=0;k<m;k++){                 // separate loop variable
            pos[k] = pos[k]*pos[k];
        }

        while(i<n and j<m){
            if(neg[i]<=pos[j]){
                res[id]=neg[i];
                id++;
                i++;
            }else{
                res[id]=pos[j];
                id++;
                j++;
            }
        }
        while(i<n){
            res[id] = neg[i];
            id++;
            i++;
        }
        while(j<m){
            res[id]=pos[j];
            id++;
            j++;
        }

        return res;
    }
};