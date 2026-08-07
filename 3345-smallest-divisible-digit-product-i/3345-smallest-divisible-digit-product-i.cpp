class Solution {
public:

    bool r(int n,int t){
        int p=1;
        while(n>1){
            int temp=n%10;
            p*=temp;
            n/=10;
            if (p == 0) break;
        }
        return p%t==0;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(r(n,t)){
                return n;
            }
            n++;
        }
        return 0;
    }
};