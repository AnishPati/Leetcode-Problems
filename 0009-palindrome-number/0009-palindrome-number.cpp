class Solution {
public:
    bool isPalindrome(int x) {
      if(x==0){
        return true;
      }
      else if(x<0){
        return false;
      }
       long long y=x,a,s=0;
       while(x){
        a=x%10;
        s=10*s+a;
        x=x/10;
       } 
       cout<<s;
       if(s!=y){
        return false;
       }
       return true;
    }
};