#include <vector>
#include <iostream>
#include<climits>

using namespace std;

bool isvalid(vector<int> v, int n, int m){
    return v[0]>=0 && v[0]<n && v[1]>=0 && v[1]<m;
}

int main() {
    int n,m,s,k,q;  
    cin>>n>>m>>s;
  
    vector<vector<int>> A(n,vector<int>(m,INT_MAX));
    vector<vector<int>> distance(n,vector<int> (m,-1));

    int si, sj,ci;
    for(int i=0;i<s;i++){
        cin>>si>>sj>>ci;
        A[si-1][sj-1]=min(ci,A[si-1][sj-1]);
    }
    
    vector<vector<int>> Q;
    
    int mn=INT_MAX;
    
    cin>>k;
    vector<vector<int>> K(k,vector<int>(2));
    for(int i=0;i<k;i++){
        for(int j=0;j<2;j++){
            cin>>K[i][j];
            K[i][j]--;
        }
        distance[K[i][0]][K[i][1]]=0;
        //enqueue(Q,K[i]);
        Q.push_back(K[i]);
        mn=min(mn,A[K[i][0]][K[i][1]]);
    }
    
    //for(auto i:K) for(auto j:i) cout<<j<<"__";cout<<endl;
    
    
    cin>>q;
    vector<int> T(q);
    for(int i=0;i<q;i++){
        
        cin>>T[i];
        //cout<<T[i]<<endl;
       // cout<<A[0].size()<<"yy"<<A.size();
    }
    
    
    //for(auto i:T) cout<<i<<"__";cout<<endl;
    
    
    
  
    
  
    
    vector<int> cost_step(n+m+1,INT_MAX);
    
    //for(auto i:cost_step) cout<<i<<"__";

    cost_step[0]=mn;
    
    
    
    vector<int> v;
    
    vector<int> del_x={0,0,1,-1};
    vector<int> del_y={1,-1,0,0};

    int front=0;

    while(front<Q.size()){
        //cout<<Q.size()<<"     ";
        v=Q[front];
        //dequeue(Q);
        //Q.erase(Q.begin());
        front++;
        //cout<<Q.size()<<"  ";
        vector<int> neighb(2);       
        
        
        for(int i=0;i<4;i++){
            neighb[0]=v[0]+del_x[i];
            neighb[1]=v[1]+del_y[i];
            mn=min(mn,cost_step[distance[v[0]][v[1]]]);
            if(!isvalid(neighb,n,m) || distance[neighb[0]][neighb[1]]!=-1) continue;
            distance[neighb[0]][neighb[1]]=distance[v[0]][v[1]]+1;
            mn=min(mn,A[neighb[0]][neighb[1]]);
            cost_step[distance[neighb[0]][neighb[1]]]=mn;
            
            /*cout<<dx[i]<<"--"<<dy[i]<<" * ";
            cout<<neighb[0]<<" "<<neighb[1]<<endl;*/
            //enqueue(Q,neighb);
            Q.push_back(neighb);
            
        }
                
    }
    
    int x=INT_MAX;
    for(int i=0;i<cost_step.size();i++){
        x=min(x,cost_step[i]);
        cost_step[i]=x;
    }
    
    //for(auto i:cost_step) cout<<i<<" ";cout<<endl;
    
    for(int i=0;i<q;i++){
        //if(T[i]>n+m) cout<<*cost_step.end()<<" ";
        if(cost_step[T[i]]==INT_MAX) cout<<-1<<" ";
        else cout<<cost_step[T[i]]<<" ";
    }
    
    return 0;
}

