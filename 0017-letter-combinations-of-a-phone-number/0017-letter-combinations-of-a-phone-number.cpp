class Solution {
public:
    void fun(string &digits, int n, int idx, string &diary, vector<string> &res){
        unordered_map<char, string> f;
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";
        if(idx==n){
            res.push_back(diary);
            return;
        }
        string choice = f[digits[idx]];
        for(int i=0;i<choice.size();i++){
            diary.push_back(choice[i]);
            fun(digits,n,idx+1,diary,res);
            diary.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        // unordered_map<char, string> f;
        // f['2'] = 'abc';
        // f['3'] = 'def';
        // f['4'] = 'ghi';
        // f['5'] = 'jkl';
        // f['6'] = 'mno';
        // f['7'] = 'pqrs';
        // f['8'] = 'tuv';
        // f['9'] = 'wxyz';
        int n = digits.size();
        int idx = 0;
        string diary = "";
        vector<string> res;
        fun(digits, n, idx, diary, res);
        return res;
    }
};