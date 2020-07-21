#include <iostream>
using namespace std;
bool cycle detect(int src){
    map<int,bool>vis;
    map<int,int>parent;
    queue<int>q;
    q.push(src);
    vis[src]=true;
    parent[src]=src;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto neighbour:adj[node]){
            if(vis[neighbour]==true and par[node]!=neighbour){
                return true;
            }
            else if(vis[neighbour]!=true){
                par[neighbour]=node;
                vis[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
    return false;
}
int main() {
    cout<<"Hello World!";
}
