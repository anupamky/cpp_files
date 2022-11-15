#include <bits/stdc++.h>
using namespace std;
string sp=" ";
#define ar array
#define vc vector
#define int int64_t 
#define pb push_back
#define gh cout<<endl;
#define sz(A) ((int)(A.size()))
#define Fo(i,k,n) for(int i=k;i<=n;i++)

const int mxn = 1e5+5;

int n, m, k, x, ians = 0, timer = 0, ans = 0;

map<int,set<int>> G;
vector<int> visited(mxn, 0), tin(mxn, -1), low(mxn, -1);

vc<ar<int,2>> Bridges;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    set<int> adj = G[v];
    for (int to : adj) {
        if(to == p)continue;
        if(visited[to])low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){
                Bridges.pb({v, to});
            }
        }
    }
}

void find_bridges() {// Main function
    timer = 0;
    visited.assign(n+1, 0);
    for (int i = 1; i <= n; ++i){
        if (!visited[i])dfs(i);
    }
}

vc<int> vis(mxn, 0);
void dfs2(int u){
    ans += 1;
    for(int v: G[u]){
        if(vis[v]==0){
            vis[v] = 1;
            dfs2(v);
        }
    }
    return;
}

void solve(int TEST_CASE){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    
    find_bridges();

    for(ar<int,2> e: Bridges){
        G[e[0]].erase(e[1]);
        G[e[1]].erase(e[0]);
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==0 && sz(G[i])>0){
            ans = 0;
            vis[i] = 1;
            dfs2(i);
            ians += (ans * (ans - 1));
        }
    }

    cout << ians << endl;
}

// Check value of mod 
// you have changed int to int64_t : TLE 

int32_t main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(25);
    int Test=1;//cin >> Test;
    Fo(T,1,Test){//cout<<"Case #"<<T<<":"<<sp;
        solve(T);
    }
    //Time;
    return 0;
}