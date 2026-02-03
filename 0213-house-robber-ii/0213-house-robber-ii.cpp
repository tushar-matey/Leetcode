class Solution {
public:
    int rob(vector<int>& n) {
        if(n.size()==1){
            return n[0];
        }
        int ans=INT_MIN;

        int p1=n[0];
        int p2=max(n[1],p1);
        for(int i=2;i<n.size()-1;i++){
            int temp=max(n[i]+p1,p2);
            p1=p2;
            p2=temp;
        }

        ans=p2;
        if(n.size()<3){
            return ans;
        }
        p1=n[1];
        p2=max(n[2],p1);

        for(int i=3;i<n.size();i++){
            int temp=max(n[i]+p1,p2);
            p1=p2;
            p2=temp;
        }
        


        
        return max(ans,p2);
    }
};