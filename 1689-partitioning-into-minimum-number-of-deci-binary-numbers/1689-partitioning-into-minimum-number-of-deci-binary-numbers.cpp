class Solution {
public:
    int minPartitions(string n) {
        int anss=0;
        for(char i :n){
            anss=max(anss,i-'0');
        }
        return anss;
    }
};