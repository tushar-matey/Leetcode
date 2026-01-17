class Solution {
public:
    bool partition1(string s){
        if(s.size()==0){
            return true;
        }
        int i=0;int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void print(vector<vector<string>>a){
        cout<<endl;
        cout<<"[";
        for(auto i:a){
            cout<<"[";
            for(string j:i){
                cout<<j<<",";
            }
            cout<<"],";
        }
        cout<<"]";
        cout<<endl;
    }

    vector<vector<string>> r(int i ,string s,vector<string>ans){
        // cout<<"i:"<<i<<", ";
        if(i==s.size()){
            vector<vector<string>>temp={ans};
            // print(temp);
            return temp;
        }
        vector<vector<string>>ans1;
        for(int k=1;(i+k-1)<s.size();k++){
            // cout<<s.substr(i,k)<<" "<<partition1(s.substr(i,k))<<" ";
            if(partition1(s.substr(i,k))){
                ans.push_back(s.substr(i,k));
                vector<vector<string>>temp=r(i+k,s,ans);
                // print(temp);
                ans.pop_back();
                ans1.insert(ans1.end(),temp.begin(),temp.end());
                // print(ans1);
            }
        }
        // cout<<endl;
        return ans1;
    }

    vector<vector<string>> partition(string s) {
        vector<string>ans;
        return r(0,s,ans);
            
    }
};