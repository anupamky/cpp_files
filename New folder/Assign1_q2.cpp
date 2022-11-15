#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;

typedef long long ll;

int main(){

    int N;
    cin>>N;

    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    ll ans=INT_MIN, subsum=0;
    for(auto i:A){
        subsum=subsum + (ll)i;                  //sum of subarray till now
        
        if(subsum>ans){
            ans=subsum;                     //if sum greater than stored answer, update
        }

        if(subsum<0){
            subsum=0;                       //if sum is neg, discard the subarray
        }

        

        
    }

    cout<<ans;

    return 0;
    

}