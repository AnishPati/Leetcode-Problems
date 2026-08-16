class Solution {
public:
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size(), k);
    }

    int solve(string &s, int start, int end, int k) {
        if (end - start < k) return 0;

        int count[26] = {0};
        for (int i = start; i < end; i++) {
            count[s[i]-'a']++;
        }

        for (int i = start; i < end; i++) {
            if (count[s[i]-'a'] < k) {
                int mid = i;
                int left = solve(s, start, mid, k);
                while (mid < end && count[s[mid]-'a'] < k) mid++;
                int right = solve(s, mid, end, k);
                return max(left, right);
            }
        }
        return end - start;  // whole range is valid
    }
};