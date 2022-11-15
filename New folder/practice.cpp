#include<iostream>
#include<bits/stdc++.h>
//#include<vector>
//#include<fstream>

using namespace std;


int main(){
    
    // input file loaded

    //ifstream fin("input.txt");

    int n,r,m,t;

    cin>>t;
    for(;t>0;t--){
    cin>>n>>r>>m;

    vector<vector<int>> edge(r,vector<int>(2));
    vector<vector<int>> soldier(m,vector<int>(2));

    for(int i=0;i<r;i++){
        cin>>edge[i][0]>>edge[i][1];
    }

    vector<vector<int>> admatrix(n+1,vector<int>(0));
    //cout<<"running fine";
    for(int i=0;i<r;i++){
        admatrix[edge[i][0]].push_back(edge[i][1]);
        admatrix[edge[i][1]].push_back(edge[i][0]);
    }

    for(int i=0;i<m;i++){
        cin>>soldier[i][0]>>soldier[i][1];
    }

    

    //fin.close();

    // input file closed

    vector<bool> visited(n+1,false);

    queue<vector<int>> Q;

    for(int i=0;i<m;i++){
        Q.push(soldier[i]);
    }

    while(Q.size()){
        vector<int> temp=Q.front();
        Q.pop();
        //if(visited[temp[0]]==true) continue;
        visited[temp[0]]=true;
        if(temp[1]>0){
            for(int i=0;i<admatrix[temp[0]].size();i++){
                Q.push({admatrix[temp[0]][i],temp[1]-1});
            }
        }

    }

    

    string ans="Yes";
    for(int i=1;i<=n;i++){
        if(visited[i]==false) {
            ans="No";
            break;
            }

    }
    
    // output file loaded

    //ofstream fout("output.txt",ios::trunc);

    cout<<ans;
    //fout.close();

    // output file closed
    }
}