#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vv vector<int>
#define pb push_back
vv adj[10001];
int vis[10001];
void dfs(int node){
    vis[node]=1;
    for(int child:adj[node]){
        if(vis[child]==0){
            dfs(child);
        }
    }
}
int main() {
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int cc_count=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
            cc_count++;
        }
    }
    if(cc_count==1 and m==n-1){
        cout<<"yes is it tree";
    }
    else{
        cout<<"No,is a no tree";
    }
    return 0;
}

