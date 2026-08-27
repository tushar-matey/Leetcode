class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tc=0;
        int tg=0;
        int s=0;
        int cg=0;
        for(int i=0;i<gas.size();i++){
            tc+=cost[i];
            tg+=gas[i];
            cg+=gas[i]-cost[i];
            if(cg<0){
                cg=0;
                s=i+1;
            }
        }
        return tg>=tc?s:-1;
    }
};