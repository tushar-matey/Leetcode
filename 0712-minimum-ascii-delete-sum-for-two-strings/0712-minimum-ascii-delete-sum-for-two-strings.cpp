class Solution {
public:
    int minimumDeleteSum(string a, string b) {
        vector<int>curr(b.size()+1);
        vector<int>prev(b.size()+1);
        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                if(a[i]==b[j]){
                    curr[j]=a[i]+b[j]+prev[j+1];
                }
                else{
                    curr[j]=max(prev[j],curr[j+1]);
                }
            }
            prev=curr;
        }
        int a1=0;
        for(char i:a){
            a1+=i;
        }
        for(char i:b){
            a1+=i;
        }
        return a1-curr[0];
    }
};