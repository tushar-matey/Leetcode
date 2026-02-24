class Solution {
public:
    int r(int i,string s,vector<int>&dp){
        if(i<0){
            return 1;
        }
        int temp=0;
        if(s[i]!='0'){
            temp=r(i-1,s,dp);
        }
        
        if(i>0){
            string s1="";
            s1+=s[i-1];
            s1+=s[i];
            if(stoi(s1)<=26 && s[i-1]!='0'){
                temp+=r(i-2,s,dp);
            }
        }
        dp[i]=temp;
        return dp[i];
    }

    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        // r(s.size()-1,s,dp);
        dp[0]=1;
        for(int i=0;i<s.size();i++){
            int x=i+1;
            int temp=0;
            if(s[i]!='0'){
                temp=dp[x-1];
            }
            if(i>0){
                string s1="";
                s1+=s[i-1];
                s1+=s[i];
                if(stoi(s1)<=26 && s[i-1]!='0'){
                    temp+=dp[x-2];
                }
            }
            dp[x]=temp;
        }


        // for(int i:dp){
        //     cout<<i<<" ";
        // }
        return dp[s.size()];
    }
};