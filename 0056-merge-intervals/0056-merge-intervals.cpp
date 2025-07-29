class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>>ans;
        int i=0;
        int j=1;
        while(i<=j && j<in.size()){
            bool flag=false;
            int k=in[i][1];
            // while(j<in.size() && in[i][0]<=in[j][0] && in[i][1]>=in[j][0]){
            while(j<in.size() && in[i][0]<=in[j][0] && k>=in[j][0]){
                k=max(in[j][1],k);
                j++;
                flag=true;
            }
            if(flag){
                if(j==in.size()){
                    j--;
                    if(in[i][1]<k){
                        in[i][1]=k;
                    }
                    ans.push_back(in[i]);
                    return ans;
                }
                j--;
                if(in[i][1]<k){
                    in[i][1]=k;
                }
                ans.push_back(in[i]);
                j+=2;
                i=j-1;
            }
            else{
                ans.push_back(in[i]);
                i++;
                j++;
            }
        }
        ans.push_back(in[in.size()-1]);
        return ans;

    }
};