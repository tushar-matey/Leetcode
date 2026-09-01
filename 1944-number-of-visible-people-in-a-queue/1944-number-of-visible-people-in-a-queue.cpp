class Solution {
public:
    void print(stack<int>s){
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        
        cout<<endl;
    }
    vector<int> canSeePersonsCount(vector<int>& h) {
        stack<int>s;
        vector<int>ans(h.size());
        
        for(int i=h.size()-1;i>=0;i--){
            if(s.empty()){
                s.push(i);
                ans[i]=0;
            }
            else{
                int ans1=0;
                while(!s.empty() && h[s.top()]<h[i]){
                    s.pop();
                    ans1++;
                }
                if(!s.empty()){
                    ans1++;
                }
                s.push(i);
                ans[i]=ans1;
            }
            // print(s);
        }
        return ans;
    }
};