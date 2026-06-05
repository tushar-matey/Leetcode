class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int>m;
        while(n>0){
            int temp=n%10;
            if(m.find(temp)!=m.end()){
                m[temp]++;
            }
            else{
                m[temp]=1;
            }
            n/=10;
        }
        int ans=0;
        for(auto i:m){
            ans+=i.first*i.second;
        }
        return ans;
    }
};