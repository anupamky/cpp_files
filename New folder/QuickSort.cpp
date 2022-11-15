#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void partition(vector<int>& A, vector<int>& Sl, vector<int>& Sr, int n){
    for(int i=0;i<n-1;i++){
        if(A[i]>A[n-1]) Sr.push_back(A[i]);
        else Sl.push_back(A[i]);
    }
}

vector<int> concat(vector<int>& L, int x, vector<int>& R){
    L.push_back(x);
    for(int i=0;i<R.size();i++){
        L.push_back(R[i]);
    }
    return L;
}

void quicksort(vector<int>& A){
    int n=A.size();
    if(n>1){
        vector<int> Sl, Sr;
        partition(A,Sl,Sr, n);
        quicksort(Sl);
        quicksort(Sr);
        A=concat(Sl,A[n-1],Sr);
    }
}

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    quicksort(A);

    for(auto i:A) cout<<i<<" ";

    return 0;

}