class Solution {
public:
    vector<vector<int>> mul(vector<vector<int>> v,vector<vector<int>>u){
        int n=v.size();
        vector<vector<int>>res1(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                for(int j=0;j<n;j++){
                    res1[i][j]+=v[i][k]*u[k][j];
                }
            }
        }
        return res1;
    }
    vector<vector<int>> power(vector<vector<int>>v,int exp){
        int n=v.size();
        vector<vector<int>>res(n,vector<int>(n,0));
        for(int i=0;i<n;i++)res[i][i]=1;
        while(exp>0){
            if(exp&1){
                res=mul(res,v);
            }
            v=mul(v,v);
            exp>>=1;
        }
        return res;
    }

    int fib(int n) {
        if(n<2){
            return n; 
        }
        vector<vector<int>>a={{1,1},{1,0}};
        a=power(a,n-1);
        
        return a[0][0];
    }
};