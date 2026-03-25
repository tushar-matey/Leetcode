class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1){
            return s.size();
        }
        int i=0;
        int j=0;
        unordered_map<char,int>m;
        int ans=1;
        while(j<s.size()){
            if(m.find(s[j])==m.end() || m[s[j]]<i){
                ans=max(ans,j-i+1);
                m[s[j]]=j;
                j++;
            }
            else{
                i=m[s[j]]+1;
                ans=max(ans,j-i+1);
                m[s[j]]=j;
                j++;
            }
        }
        return ans;

    }
};