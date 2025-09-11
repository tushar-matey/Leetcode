class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int>map;
        vector<vector<string>>ans;
        for(string i:strs){
            string temp=i;
            sort(temp.begin(),temp.end());
            if(map.find(temp)==map.end()){
                map[temp]=ans.size();
                ans.push_back({});
            }
            ans[map[temp]].push_back(i);
        }
        return ans;
    }
};