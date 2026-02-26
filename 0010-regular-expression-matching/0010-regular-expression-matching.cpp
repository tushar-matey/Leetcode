class Solution {
public:

    bool r(int i,int j,string s,string p,vector<vector<int>>&dp){
        if(i==s.size() && j==p.size()){
            dp[i][j]=true;
            return true;
        }
        // if(i==s.size()){
        //     if(j<p.size()-1 && )
        //     return false;
        // }
        // cout<<i<<" "<<j<<endl;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool temp=false;
        if(j<p.size()-1 && p[j+1]=='*'){
            if((p[j]=='.' || p[j]==s[i]) && i!=s.size()){
                temp=temp|r(i+1,j+2,s,p,dp);//final take
                if(temp){
                    dp[i][j]=temp;
                    return temp;
                }
                temp=temp|r(i+1,j,s,p,dp);//take
                if(temp){
                    dp[i][j]=temp;
                    return temp;
                }
            }
            temp=temp|r(i,j+2,s,p,dp);//zero take
        }
        else if((p[j]=='.' || s[i]==p[j]) && i!=s.size()){
            temp=temp|r(i+1,j+1,s,p,dp);//final take
        }
        dp[i][j]=temp;
        return temp;
        
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        bool temp =r(0,0,s,p,dp);
        // for(auto i:dp){
        //     for(int j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        if(dp[s.size()][p.size()]==-1){
            return false;
        }
        return true;
    }
};