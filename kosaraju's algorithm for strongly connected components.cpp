#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>graph[],int i,bool *visited,vector<int>&stack){
    visited[i]=true;
    for(auto nbr:graph[i]){
        if(!visited[nbr]){
            dfs(graph,nbr,visited,stack);
        }
    }
    stack.push_back(i);
}
void dfs2(vector<int>rev_graph[],int src,bool *visited){
    visited[src]=true;
    cout<<src<<" ";
    for(auto ss:rev_graph[src]){
        if(!visited[ss]){
            dfs2(rev_graph,src,visited);
        }
    }
}
void solve(vector<int>graph[],vector<int>rev_graph[],int n){
    // 1. make the ordering of the component over the time sharing
    vector<int>stack;
    bool visited[n];
    memset(visited,0,n);
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(graph,i,visited,stack);        
    }
    // 2. reversing in done already
    //3 . by the given stack traversing again in the rev graph
    memset(visited,0,n);
    char component='A';
    for(int i=stack.size()-1;i>=0;i--){
        int node=stack[i];
        if(!visited[node]){
            cout<<" component "<<component<<"-->"<<" ";
            dfs2(rev_graph,node,visited);
            component++;
            cout<<endl;
        }
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<int>graph[n];
    vector<int>rev_graph[n];
    int x,y;
    while(m--){
        cin>>x>>y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }   
    solve(graph,rev_graph,n);
}
