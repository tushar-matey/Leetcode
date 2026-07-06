class Solution {
public:
    
    
    bool canMakeSubsequence(string s, string t) {
        int i=0;
        int j=0;
        int n=s.size();
        bool flag=true;
        for(char c:t){
            if(s[i]==c){
                i++;
                if(i==n){
                    return true;
                }
            }
            if(s[j]==c){
                j++;
                if(j==n){
                    return true;
                }
            }
            else if(flag){
                flag=false;
                j++;
                if(j==n){
                    return true;
                }
            }
            if(i>=j){
                flag=true;
                j=i;
            }
        }
        return false;
    }
};