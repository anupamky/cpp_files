#include <vector>
#include <iostream>
using namespace std;

int upperbound(vector<int>& A, int c){
    int n=A.size();
    int l=0, r=n-1,mid=0;
    int ans=n;
    while(l<=r){
        mid=(l+r)/2;
        if(A[mid]<c){

            l=mid+1;
            continue;
        }
        else if(A[mid]>c){
            r=mid-1;
            ans=mid;
            continue;
        }
        else {
            ans=mid;
            break;
        }
    }
    
    return ans;
}

void insert(vector<int>& A, int c){
    int ind=upperbound(A,c);
    if(ind<A.size()) A.insert(A.begin()+ind,c);
    else A.push_back(c);
}

void removemax(vector<int>& A){
    if(A.size()==0) return;
    A.erase(A.end()-1);
   
    
}

int dif(vector<int>& A){
    if(A.size()==0) return -1;
    else return A[A.size()-1]-A[0];
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<int> A(0);
    int q;
    cin>>q;
    int qi=0, ci=0;
    for(int i=0;i<q;i++ ){
        cin>>qi;
        switch(qi){
            case 1: cin>>ci;
                    insert(A,ci);
                    
                    //for(auto j:A) cout<<j<<"__";cout<<endl;
                
                    break;
            case 2: removemax(A);
                break;
            case 3: cout<<dif(A)<<endl;
                break;
        }
        
    }
    return 0;
}

