class Solution {
public:
    int candy(vector<int>& r) {
        
        int i=1;
        int total=1;
        while(i<r.size()){
            if(r[i]==r[i-1]){
                total+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<r.size() && r[i]>r[i-1]){
                peak++;
                total+=peak;
                i++;
            }
            int down=1;
            while(i<r.size() && r[i]<r[i-1]){
                total+=down;
                down++;
                i++;
            }
            if(down>peak){
                total+=down-peak;
            }
            

        }
        return total;
    }
};