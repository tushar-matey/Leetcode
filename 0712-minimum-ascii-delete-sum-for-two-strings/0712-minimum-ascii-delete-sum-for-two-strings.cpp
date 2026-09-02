class Solution {
public:

    int r(int i,int j,const string &a,const string &b,vector<vector<int>>dp){
        if(i>=a.size() || j>=b.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(a[i]==b[j]){
            return a[i]+b[j]+r(i+1,j+1,a,b,dp);
        }
        return dp[i][j]=max(r(i+1,j,a,b,dp),r(i,j+1,a,b,dp));
    }

    int minimumDeleteSum(string a, string b) {
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1));
        // vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
        // int ans= r(0,0,s1,s2,dp);
        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                if(a[i]==b[j]){
                    dp[i][j]=a[i]+b[j]+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        // for(auto i:dp){
        //     for(int j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        int a1=0;
        for(char i:a){
            a1+=i;
        }
        for(char i:b){
            a1+=i;
        }
        return a1-dp[0][0];
    }
};