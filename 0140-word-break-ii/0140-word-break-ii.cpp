class Solution {
public:

    vector<string>w1;

    string r1(int i,string s, unordered_set<string> w,vector<int>&dp){
        if(i==s.size()){
            return "";
        }
        // cout<<i<<" "<<endl;
        
        string t="";

        for(int k=i;k<s.size();k++){
            t+=s[k];
            cout<<t<<" "<<k<<" ";
            if(w.find(t)!=w.end()){
                string s1=t;
                s1+=" "+r1(k+1,s,w,dp);
                cout<<"s1:"<<s1<<" ";
                
                if(!s1.contains('$') && i==0){
                    s1.pop_back();
                    w1.push_back(s1);
                }
                else{
                    return s1;
                }
            }
        }
        return "$";

    }
    vector<string> r(int i,string s, unordered_set<string> w,vector<vector<string>>&dp,string ans){
        if(i==s.size()){
            string temp=ans.substr(1);
            vector<string>ans1={temp};
            return ans1;
        }
        vector<string>v;
        string t="";

        for(int k=i;k<s.size();k++){
            t+=s[k];
            if(w.find(t)!=w.end()){
                string s1=ans+" "+t;
                vector<string>temp=r(k+1,s,w,dp,s1);
                v.insert(v.end(),temp.begin(),temp.end());
            }
        }
        return v;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>w;
        vector<vector<string>>dp(s.size());
        
        for(int i=0;i<wordDict.size();i++){
            w.insert(wordDict[i]);
        }
        
        return r(0,s,w,dp,"");
    }
};