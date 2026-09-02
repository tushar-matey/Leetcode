class Solution {
public:
    int trailingZeroes(int n) {
        if(n<=0){
            return 0;
        }
        int ans=n/5;
        return ans+trailingZeroes(n/5);
    }
};