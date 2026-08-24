class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = INT_MIN;
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int prevNoDelete = noDelete;
            int prevOneDelete = oneDelete;

            noDelete = max(arr[i], prevNoDelete + arr[i]);

            oneDelete = max(prevNoDelete,
                            prevOneDelete == INT_MIN
                                ? INT_MIN
                                : prevOneDelete + arr[i]);

            ans = max(ans, max(noDelete, oneDelete));
        }

        return ans;
    }
};