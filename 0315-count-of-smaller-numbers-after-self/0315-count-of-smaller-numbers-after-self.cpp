class Solution {
public:

    void merge(vector<int>&ans ,vector<pair<int,int>>&v,int l,int m,int r){
        vector<pair<int,int>>temp(r-l+1);
        int i=l;
        int j=m+1;
        int k=0;

        while(i<=m && j<=r){
            if(v[i].first<=v[j].first){
                temp[k]=v[j];
                j++;
            }
            else{
                ans[v[i].second]+=r-j+1;
                temp[k]=v[i];
                i++;
            }
            k++;
        }
        while(i<=m){
            temp[k]=v[i];
            i++;
            k++;
        }
        while(j<=r){
            temp[k]=v[j];
            j++;
            k++;
        }
        for(int _=l;_<=r;_++){
            v[_]=temp[_-l];
        }
    }

    void mergeSort(vector<int>&ans ,vector<pair<int,int>>&v,int l,int r){
        if(l<r){
            int m=(l+r)/2;
            mergeSort(ans,v,l,m);
            mergeSort(ans,v,m+1,r);
            merge(ans,v,l,m,r);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        vector<int>ans(nums.size(),0);
        mergeSort(ans,v,0,nums.size()-1);
        return ans;
    }
};

