class Solution {
public:
    int minInsertions(string s) {
        string ss=string(s.rbegin(),s.rend());
        // vector<vector<int>>d(ss.size(),vector<int>(s.size()));
        vector<int>prev(s.size());
        vector<int>curr(s.size());
        for(int i=0;i<ss.size();i++){
            for(int j=0;j<s.size();j++){
                if(ss[i]==s[j]){
                    if(i==0 || j==0){
                        curr[j]=1;
                    }
                    else{
                        curr[j]=1+prev[j-1];
                    }
                }
                else{
                    if(i!=0){
                        curr[j]=prev[j];
                    }
                    if(j!=0){
                        curr[j]=max(curr[j],curr[j-1]);
                    }
                }
            }
            prev=curr;
        }
        return s.size()-curr[s.size()-1];
    }

};