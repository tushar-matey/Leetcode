class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        int i=0;
        int j=n.size()-1;
        while(i<j){
            // cout<<i<<" "<<j<<" "<<n[i]<<" "<<n[j]<<endl;
            if(n[i]+n[j]<t){
                i++;
            }
            else if(n[i]+n[j]>t){
                j--;
            }
            else{
                return {i+1,j+1};
            }
        }
        return {i+1,j+1};
    }
};