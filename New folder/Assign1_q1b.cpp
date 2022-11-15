#include <vector>
#include <iostream>
using namespace std;

void enqueue(vector<vector<int>>& Q, vector<int> a){
    Q.push_back(a);
}

void dequeue(vector<vector<int>>& Q){
    Q.erase(Q.begin());
}

void bfs(vector<vector<int>>& A, vector<vector<int>>& Q,vector<int>& cs){
    
}

int main() {
    int n,m,s,k,q;
    
    
    cin>>n>>m>>s;
    
    vector<vector<int>> A(n,vector<int>(m,INT_MAX));
    int si, sj;
    for(int i=0;i<s;i++){
        cin>>si>>sj;
        cin>>A[si][sj];
    }
    
    cin>>k;
    vector<vector<int>> K(k,vector<int>(2));
    for(int i=0;i<k;i++){
        for(int j=0;j<2;j++){
            cin>>K[i][j];
        }
    }
    
    cin>>q;
    vector<int> t(q);
    for(int i=0;i<q;i++){
        cin>>t[i];
    }
    
    //for(auto i:t) cout<<i<<"__";cout<<endl;
    
    vector<vector<int>> Q(0);
    for(auto i:K) enqueue(Q,i);
    
    vector<vector<bool>> visited(n,vector<bool> (m,false));
    
    vector<int> cost_step(n+m,INT_MAX);
    
    bfs(A,Q,cost_step);
    
    return 0;
}

