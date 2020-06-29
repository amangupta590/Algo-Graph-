#include <bits/stdc++.h>
using namespace std;
#define ll long long
class graph{
    public:
        map<int,list<int> >l;
        //bool visited[];
        void addedge(int x,int y){
            l[x].push_back(y);
            
        }
        int bfs(int src,int dest){
            queue<int>q;
            map<int,int>dist;            
            for(auto node_pair:l){
                int node=node_pair.first;
                dist[node]=INT_MAX;
            }
            q.push(src);
            dist[src]=0;
            
            while(!q.empty()){
                 int node=q.front();
                 //cout<<node<<" ";
                 q.pop();
                 for(int nbr:l[node]){
                     if(dist[nbr]==INT_MAX){
                         q.push(nbr);
                         dist[nbr]=dist[node]+1;
                     }                     
                 }
            }
            for(auto node_pair:l){
                cout<<node_pair.first<<" and dist"<<dist[node_pair.first]<<endl;
            }
           return dist[dest];
        }
};
int main() {
    //input
    int board[50]={0};
    //snakes //ladders
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;    
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;

    //add edges to th graph;
    graph g;
    for(int i=0;i<=36;i++){
        for(int dice=1;dice<=6;dice++){
            int j=i+dice;
            j+=board[j];
            if(j<=36){
                g.addedge(i,j);
            }
        }
    }
    g.addedge(36,36);
    cout<<g.bfs(0,36);
}
