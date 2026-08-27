class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(),c.end(),greater<int>());
        int ans=1;
        while((ans-1)<c.size() && c[ans-1]>=ans){
            ans++;
        }
        return ans-1;
    }
};