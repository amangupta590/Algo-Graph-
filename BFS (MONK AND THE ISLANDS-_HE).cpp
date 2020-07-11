#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define vv vector<int>
vv arr[10001];
int vis[10001];
int dist[10001];
void BFS(int src){
    queue<int>q;
    q.push(src);
    vis[src]=1;
    dist[src]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int child:arr[node]){
            if(vis[child]==0){
                q.push(child);
                dist[child]=dist[node]+1;
                vis[child]=1;
            }
        }
    }
}
int main() {
    int t;
    cin>>t;
    int n,m,a,b;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            arr[i].clear(),vis[i]=0;
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            arr[a].pb(b);
            arr[b].pb(a);
        }
        BFS(1);
        cout<<dist[n]<<endl;
    }

}
