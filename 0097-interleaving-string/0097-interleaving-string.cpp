class Solution {
public:

    // bool r(int i,int j,string a,string b,string c,vector<vector<int>>&dp){
    //     if ((i+j)>=c.size()){
    //         return true;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     bool temp=false;
    //     if(i<a.size() && c[i+j]==a[i]){
    //         temp=r(i+1,j,a,b,c,dp);
    //     }
    //     if(j<b.size() && c[i+j]==b[j]){
    //         temp=temp|r(i,j+1,a,b,c,dp);
    //     }
    //     dp[i][j]=temp;
    //     return temp;
    // }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        // vector<vector<int>>dp1(s1.size()+1,vector<int>(s2.size()+1,-1));
        // return r(0,0,s1,s2,s3,dp1);
         
        if(s1.size()==0 || s2.size()==0){
            if(s1.size()==0){
                if(s2==s3){
                    return true;
                }
            }
            else if(s1==s3){
                return true;
            }
            return false;
        }

        vector<vector<bool>>dp(s1.size()+1,vector<bool>(s2.size()+1));
        dp[s1.size()][s2.size()]=true;
        for(int i=s1.size();i>=0;i--){
            for(int j=s2.size();j>=0;j--){
                if(i<s1.size() && s1[i]==s3[i+j]){
                    dp[i][j]=dp[i][j]|dp[i+1][j];
                }
                if(j<s2.size() && s2[j]==s3[i+j]){
                    dp[i][j]=dp[i][j]|dp[i][j+1];
                }
            }
        }
        // for(auto i:dp){
        //     for(bool j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // for(auto i:dp1){
        //     for(bool j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][0];
        
    }
};