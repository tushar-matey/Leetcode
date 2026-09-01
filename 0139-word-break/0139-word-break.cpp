class Solution {
public:
    int n;
    bool r(int i,string &s,unordered_set<string>se,vector<int>&dp){
        if(i>=s.size()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        string temp="";
        bool ans=false;
        for(int j=i;j<=(i+n) && j<s.size();j++){
            temp+=s[j];
            if(se.count(temp)){
                ans=ans||r(j+1,s,se,dp);
            }
        }
        dp[i]=ans;
        return ans;
    }

    bool wordBreak(string s, vector<string>& w) {
        int c=0;
        unordered_set<string>se;
        for(string i:w){
            int c1=i.size();
            c=max(c,c1);
            se.insert(i);
        }
        n=c;
        vector<int>dp(s.size()+1,-1);
        int ans= r(0,s,se,dp);
        return ans;
    }
};