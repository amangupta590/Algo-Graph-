#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int maxn=10;
vector<int>adj[1001];
int level[1001],lac[1001][maxn+1];
void dfs(int node,int lvl,int par){
    level[node]=lvl;
    lac[node][0]=par;
    for(int child:adj[node]){
        if(child!=node){
            dfs(child,lvl+1,node);
        }
    }
}
void init(int n){
    dfs(1,0,-1);
    for(int j=1;j<=maxn;j++){
        for(int i=1;i<=n;i++){
            if(lac[i][j-1]!=-1){
                int par=lac[i][j-1];
                lac[i][j]=lac[par][j-1];
            }
        }
    }
}
int getlca(int a,int b){
    if(level[a]>level[b])
        swap(a,b);
    int d=level[b]-level[a];
    while(d>0){
        int i=log2(d);
        b=lac[b][i];
        d-=(1<<i);
    }
    if(a==b)
        return a;
    for(int i=maxn;i>=0;i--){
        if(lac[a][i]!=-1 and (lac[a][i]!=lac[b][i])){
            a=lac[a][i];
            b=lac[b][i];
        }
    }
    return lac[a][0];
}
// int getdist(int a,int b){
//     int lca=getlca(a,b);
//     return level[a]+level[b]-2*level[lca];
// }
int main() {
    int n,a,b,q;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=maxn;j++){
            lac[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    init(n);
    cout<<getlca(1,3);
    // cin>>q;
    // while(q--){
    //     cin>>a>>b;
    //     cout<<getdist(a,b)<<endl;
    // }
}
