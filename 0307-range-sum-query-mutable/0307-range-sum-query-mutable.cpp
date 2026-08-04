class NumArray {
public:
    vector<int>n;
    int* a;
    int size;
    void Build(int node,int s,int e){
        if(e==s){
            a[node]=n[e];
            return;
        }
        int mid=(e+s)/2;
        Build(node*2+1,s,mid);
        Build(node*2+2,mid+1,e);
        a[node]=a[node*2+1]+a[node*2+2];
    }

    NumArray(vector<int>& nums) {
        n=nums;
        size=nums.size();
        int b=size*4;
        a=new int[b];
        Build(0,0,nums.size()-1);
    }

    void myUpdate(int node,int s,int e,int idx,int val){
        if(s==e){
            a[node]=val;
            return;
        }
        int mid=(e+s)/2;
        if(idx<=mid){
            myUpdate(node*2+1,s,mid,idx,val);
        }
        else{
            myUpdate(node*2+2,mid+1,e,idx,val);
        }
        a[node] = a[node*2+1] + a[node*2+2];
    }
    
    void update(int index, int val) {
        n[index]=val;
        myUpdate(0,0,size-1,index,val);
    }
    
    int mySum(int node,int s,int e,int l,int r){
        if(r<s || l>e){
            return 0;
        }
        else if(l<=s && e<=r){
            return a[node];
        }
        int mid=(e+s)/2;
        return mySum(node*2+1,s,mid,l,r)+mySum(node*2+2,mid+1,e,l,r);
    }
    int sumRange(int left, int right) {
        return mySum(0,0,size-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */