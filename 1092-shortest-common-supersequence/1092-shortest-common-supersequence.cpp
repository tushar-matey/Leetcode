class Solution {
public:
    // void print(vector<vector<string>>dp){
    //     for(auto i:dp){
    //         for(string j:i){
    //             if(j==""){
    //                 cout<<"*"<<" ";
    //             }
    //             else{

    //             cout<<j<<" ";
    //             }
    //         }
    //         cout<<endl;
    //     }
    // }
    string shortestCommonSupersequence(string str1, string str2) {
        // vector<vector<string>>dp(str1.size(),vector<string>(str2.size(),""));
        vector<string>prev(str2.size(),"");
        vector<string>curr(str2.size(),"");
        for(int i=0;i<str1.size();i++){
            for(int j=0;j<str2.size();j++){
                if(str1[i]==str2[j]){
                    if(i>0 && j>0){
                        curr[j]=prev[j-1]+str1[i];
                    }
                    else{
                        curr[j]=str1[i];
                    }
                }
                else{
                    string s="";
                    if(i>0){
                        if(j>0){
                            if(prev[j].size()>curr[j-1].size()){
                                s=prev[j];
                            }
                            else{
                                s=curr[j-1];
                            }
                        }
                        else{
                            s=prev[j];
                        }
                    }
                    else if(j>0){
                        s=curr[j-1];
                    }
                    curr[j]=s;
                }
            }
            prev=curr;
        }
        string s=prev[str2.size()-1];
        int i=0;
        int j=0;
        int k=0;
        string ans="";
        while(i<str1.size() && j<str2.size() && k<s.size()){
            if(str1[i]==s[k] && str2[j]==s[k]){
                ans+=s[k];
                i++;
                j++;
                k++;
            }
            else if(str1[i]==s[k]){
                ans+=str2[j];
                j++;
            }
            else if(str2[j]==s[k]){
                ans+=str1[i];
                i++;
            }
            else{
                ans+=str1[i];
                ans+=str2[j];
                i++;
                j++;
            }
        }
        for(;i<str1.size();i++){
            ans+=str1[i];
        }
        for(;j<str2.size();j++){
            ans+=str2[j];
        }
        return ans;
    }
};