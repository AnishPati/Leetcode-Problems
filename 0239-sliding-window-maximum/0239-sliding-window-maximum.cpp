class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> dq;  // stores indices, values kept in decreasing order

        for (int i = 0; i < n; i++) {
            // step 1: drop index from front if it's outside the current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // step 2: drop smaller values from back — they can never win while nums[i] is in the window
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // step 3: once window is full size, front of deque = window max
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};