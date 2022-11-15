#include<iostream>
#include<bits/stdc++.h>
#include<time.h>

using namespace std;
using namespace std::chrono;

/*long long fib(long long n){
    if(n==1 || n==2) return 1;
    return fib(n-1)+fib(n-2);
}*/

int main(){

    long long n=1;
    vector<double> t={6};
    for(auto i:t){
        //clock_t start, end;
        //int ctu;
        //start=clock();
        auto start=high_resolution_clock::now();
        int a=0,b=1,temp;
        while(1){
            temp=a+b;
            a=b;
            b=temp;
            n=(n+1);
            //end=clock();
            auto end=high_resolution_clock::now();
            /*if((double)(end-start)/CLOCKS_PER_SEC >= i){
                cout<<n;
                break;
            }*/
            //auto duration=duration_cast<seconds>(end-start);
            if((duration_cast<seconds>(end-start)).count()>=i){
                cout<<n;
                break;
            }

        }
       /* while(1){
            start=clock();
            fib(n);
            end=clock();
            if((double)(end-start)/CLOCKS_PER_SEC >= i){
                cout<<n;
                break;
            }
            n++;
        }*/

    }

    return 0;

}