#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int findsink(vector<vector<int>>& A){
    int s=0;
    for(int i=1;i<7;i++){
        if(A[s][i]==0){
            continue;
        }
        else{
            s=i;
            continue;
        }
    }

    return s+1;
}


int main(){
    vector<vector<int>> A(7,vector<int>(7));
    A[0]={0,0,0,1,0,0,0};
    A[1]={1,0,1,1,0,0,0};
    A[2]={1,0,0,1,0,0,1};
    A[3]={0,0,0,0,0,0,0};
    A[4]={0,0,0,1,0,0,1};
    A[5]={0,0,0,1,1,0,1};
    A[6]={0,0,0,1,0,1,0};

    cout<<findsink(A);
    return 0;

}