#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
typedef long long ll;

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int N;
    cin>>N;
    ll a=0,b=2;
    if(N==1) cout<<0;
    if(N==2) cout<<2;

    ll temp=0;
    for(int i=2;i<N;i++){
        temp=b;
        b=(b+(2*a)%((ll)1e9+7))%((ll)1e9+7);
        a=temp;
    }

    cout<<b;

    return 0;
}
