#include<bits/stdc++.h>
using namespace std;

int main(){
    cout << " HELLO WORLD !! " << endl;
}

// #include<iostream>
// #include<vector>


// using namespace std;

// void heapify(vector<int>& A, int n,int start){
//     int i=start;
//     int min;
//     while(i<=(n-2)/2){
//         min=i;
//         if(A[i]>A[2*i+1]) min=2*i+1;
//         if(2*i+2<n && A[min]>A[2*i+2]) min=2*i+2;
        
//         if(i==min) break;
//         swap(A[i],A[min]);
//         i=min;
//     }
// }

// void makeheap(vector<int>& A, int n){
//     for(int i=(n-2)/2;i>=0;i--){
//         heapify(A,n,i);
//     }
// }

// int extractmin(vector<int>& A){
//     int ans=A[0];
//     A.erase(A.begin());
//     heapify(A,A.size(),0);
//     return ans;
// }

// int main(){
//     int N;
//     cin>>N;
//     vector<int> A(N);
//     for(int i=0;i<N;i++){
//         cin>>A[i];
//     }

//     makeheap(A,N);

//     for(auto i:A) cout<<i<<" ";cout<<endl;

//     while(A.size()>0){
//         cout<<extractmin(A)<<" ";
//     }

//     return 0;
// }