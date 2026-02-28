class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>>st;
        st.push({t[0],0});
        vector<int>ans(t.size());
        for(int i=1;i<t.size();i++){
            while(!st.empty() && t[i]>st.top().first){
                ans[st.top().second]=i-st.top().second;
                st.pop();
            }
            
            st.push({t[i],i});
        }
        return ans; 
    }
};