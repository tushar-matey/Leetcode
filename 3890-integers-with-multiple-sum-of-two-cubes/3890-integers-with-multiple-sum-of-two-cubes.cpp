class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int i=1;
        int j=1;
        unordered_map<int,bool>m;
        set<int>s;
        while(true){
            j=i;
            bool flag=false;
            while(true){
                int temp=pow(i,3)+pow(j,3);
                if(temp<=n){
                    if(m.find(temp)!=m.end()){
                        s.insert(temp);
                    }
                    m[temp]=true;
                }
                else if(temp>n){
                    flag=!flag;
                    break;
                }
                flag=true;
                j++;
            }
            if(flag){
                break;
            }
            i++;
        }
        vector<int>v(s.begin(),s.end());
        return v;
    }
};