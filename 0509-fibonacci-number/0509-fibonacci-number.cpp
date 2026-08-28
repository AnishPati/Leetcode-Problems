class Solution {
public:
    int fib(int n) {
        if(n==0 or n==1)return n;
        //if(n==1)return 1;
        int ans1 = fib(n-1);
        int ans2 = fib(n-2);
        return ans1+ans2;
    }
};