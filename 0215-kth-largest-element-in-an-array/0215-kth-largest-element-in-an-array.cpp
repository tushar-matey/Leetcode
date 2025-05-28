class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>a;
        for(int i:nums){
            a.push(i);
        }
        while(k!=1){
            a.pop();
            k--;
        }
        return a.top();
    }
};