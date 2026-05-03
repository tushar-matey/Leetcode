
#define vvi vector<vector<long long>>
class Solution {
public:

const long long MOD = 1e9 + 7;


    vvi mul(vvi v, vvi u){
        int n=v.size();
        vvi result(n,vector<long long>(n,0));
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                for(int j=0;j<n;j++){
                    result[i][j] = (result[i][j] + (v[i][k] * u[k][j]) % MOD) % MOD;
                    
                }
            }
        }
        return result;
    }

    vvi power(vvi base, int exp){
        int n=base.size();
        vvi result(n,vector<long long>(n,0));
        for(int i=0;i<n;i++){
            result[i][i]=1;
        }
        while(exp>0){
            if(exp&1){
                result=mul(result,base);
            }
            base=mul(base,base);
            exp>>=1;
        }
        return result;
    }

    void print(vvi s){
        for(auto i:s){
            for(int j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    int numTilings(int n) {
        if(n==1){
            return 1;
        }

        vvi s={
            {1,1,2,0},
            {1,0,0,0},
            {0,1,1,0},
            {0,1,0,0}
        };
        // print(s);
        s=power(s,n-2);
        // print(s);



        return (s[0][0]*(long long)(2) + s[0][1] + s[0][2])%MOD ;
    }
};