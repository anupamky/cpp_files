#include <iostream>
#include<bits/stdc++.h>

using namespace std;
 
#define ll long long
#define m (ll)(1e9 + 7)

#include<numeric>

int func(vector<int> A){
	int sec=0,sec10=0,min=0;
	int drop=0;
	for(int i=0;i<A.size();i++){
		if(A[i]!=A[sec]){
			while(A[i]!=A[sec]) sec++;
		}
		if(A[i]-A[sec10]>20){
			while(A[i]-A[sec10]>20) sec10++;
		}
		if(A[i]-A[min]>60){
			while(A[i]-A[min]>60) min++;
		}
		if(i-sec>3){
			drop++;
		}
		else if(i-sec10>20){
			drop++;
		}
		else if(i-min>60){
			drop++;
		}
	}
	return drop;
}

int main() {
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++) cin>>A[i];
		cout<<func(A);

 	return 0;
}
