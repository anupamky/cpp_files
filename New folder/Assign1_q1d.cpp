#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
typedef long long ll;
ll mod=(ll)1e9+7;

using namespace std;

/*vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b){
    vector<vector<ll>> ans(2,vector<ll>(2));
    ans[0][0]=((a[0][0]*b[0][0])%mod+(a[0][1]*b[1][0])%mod)%mod;
    ans[0][1]=((a[0][0]*b[0][1])%mod+(a[0][1]*b[1][1])%mod)%mod;
    ans[1][0]=((a[1][0]*b[0][0])%mod+(a[1][1]*b[1][0])%mod)%mod;
    ans[1][1]=((a[1][0]*b[0][1])%mod+(a[1][1]*b[1][1])%mod)%mod;

    return ans;

}*/

vector<vector<ll>> matmul(vector<vector<ll>> X, ll n){
    if(n==1) return X;
    //if(n==2) return mul(X,X);

    if(n%2==0){
        vector<vector<ll>> a=matmul(X,n/2);
        vector<vector<ll>> b=a;
        vector<vector<ll>> ans(2,vector<ll>(2));
        ans[0][0]=((a[0][0]*b[0][0])%mod+(a[0][1]*b[1][0])%mod)%mod;
        ans[0][1]=((a[0][0]*b[0][1])%mod+(a[0][1]*b[1][1])%mod)%mod;
        ans[1][0]=((a[1][0]*b[0][0])%mod+(a[1][1]*b[1][0])%mod)%mod;
        ans[1][1]=((a[1][0]*b[0][1])%mod+(a[1][1]*b[1][1])%mod)%mod;

        return ans;
    }
    else{
        
        vector<vector<ll>> a=matmul(X,n/2);
        vector<vector<ll>> b=a;
        vector<vector<ll>> ans(2,vector<ll>(2));
        ans[0][0]=((a[0][0]*b[0][0])%mod+(a[0][1]*b[1][0])%mod)%mod;
        ans[0][1]=((a[0][0]*b[0][1])%mod+(a[0][1]*b[1][1])%mod)%mod;
        ans[1][0]=((a[1][0]*b[0][0])%mod+(a[1][1]*b[1][0])%mod)%mod;
        ans[1][1]=((a[1][0]*b[0][1])%mod+(a[1][1]*b[1][1])%mod)%mod;

        a=ans;
        b=X;

        ans[0][0]=((a[0][0]*b[0][0])%mod+(a[0][1]*b[1][0])%mod)%mod;
        ans[0][1]=((a[0][0]*b[0][1])%mod+(a[0][1]*b[1][1])%mod)%mod;
        ans[1][0]=((a[1][0]*b[0][0])%mod+(a[1][1]*b[1][0])%mod)%mod;
        ans[1][1]=((a[1][0]*b[0][1])%mod+(a[1][1]*b[1][1])%mod)%mod;


        return ans;
        //return mul(mul(matmul(X,n/2),matmul(X,n/2)),X);
    }
}

int main(){
    ll N;
    cin>>N;

    vector<vector<ll>> X={{1,2},{1,0}};        //multiplication matrix
    vector<ll> initials={0,1};                 //matrix of form (A[1],A[0])

    if(N==1) cout<<0;

    cout<<matmul(X,N-1)[0][1];    //((x1,x2),(x3,x4))*(0,1)^T =(x2,x4)^T gives a 2*1 matrix with A(N) as first element

    return 0;
}
