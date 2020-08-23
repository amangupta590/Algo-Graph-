#include<bits/stdc++.h>
using namespace std;
int visited[10001]={0};
vector<int>adj[1000];
bool dfs(int src,int *col,int c){
    visited[src]=1;
    col[src]=c;
    for(int child:adj[src]){
        if(visited[child]==0){
            if(dfs(child,col,c^1)==0)
                return false;
        }
        else{
            if(col[child]==col[src])
                return false;
        }
    }
    return true;
}
int main() {
    int t;
    cin>>t;
    int k=0;
    while(t--){
        k++;
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            adj[i].clear();
            visited[i]=0;
        }
        while(m--){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int col[10001]={0};
        int j=0;
        for(int i=1;i<=n;i++){
            if(visited[i]==0){
                if(dfs(i,col,1)==0){
                    j=1;
                    break;
                }
            }
        }
        if(j==1){
            cout<<"Scenario #"<<k<<":"<<endl;
            cout<<"Suspicious bugs found!"<<endl;
        }
        else{
            cout<<"Scenario #"<<k<<":"<<endl;
            cout<<"No suspicious bugs found!"<<endl;
        }
    }
}
