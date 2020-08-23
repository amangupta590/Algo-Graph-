//if two one node is the subtree of another node,there in inner array arr[i]<arr[i+1] and outer array arr[i]>arr[i+1]

#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000];
int invisited[100]={0};
int out[100]={0};
int visited[100]={0};
int timer=1;
void dfs(int src){
    visited[src]=1; 
    invisited[src]=timer++;
    for(int node:adj[src]){                
        if(visited[node]==0){            
            dfs(node);
        }
    }
    out[src]=timer++;
    return ;
}
int main() {
    int m;
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);
}
