class Solution {
public:

    // int r(map<int,int>::iterator it,map<int,int>&m,unordered_map<int,int>&dp){
    //     if(it==m.end()){
    //         return 0;
    //     }
    //     if(dp.find(it->first)!=dp.end()){
    //         return dp[it->first];
    //     }
    //     int val=it->second*it->first;
    //     int k=it->first;
    //     //notTake
    //     it++;
    //     int notTake=r(it,m,dp);
    //     //take
    //     int take=INT_MIN;
    //     if(it!=m.end()){
    //         if(k+1==it->first){
    //             it++;
    //         }
    //         take=r(it,m,dp)+val;
    //     }
    //     else{
    //         take=val;
    //     }
    //     dp[it->first]=max(take,notTake);
    //     return max(take,notTake);
    // }
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>m;
        unordered_map<int,int>dp;
        for(int i:nums){
            if(m.find(i)==m.end()){
                m[i]=1;
            }
            else{
                m[i]++;
            }
        }

        auto it=m.begin();
        dp[it->first]=it->second*it->first;
        auto prev1=it;
        it++;
        if(it==m.end()){
            return dp[prev1->first];
        }
        if(prev1->first+1==it->first){
            dp[it->first]=max(dp[prev1->first],it->second*it->first);
        }
        else{
            dp[it->first]=it->second*it->first+dp[prev1->first];
        }
        auto prev=it;
        it++;
        while(it!=m.end()){
            int val=it->second*it->first;
            //notTake
            int notTake=dp[prev->first];
            //take
            int take=INT_MIN;
            
            if(prev->first+1==it->first){
                take=dp[prev1->first]+val;
            }
            else{
                take=dp[prev->first]+val;
            }
            dp[it->first]=max(notTake,take);
            prev1=prev;
            prev=it;
            it++;

        }
        return dp[prev->first];
    }
};