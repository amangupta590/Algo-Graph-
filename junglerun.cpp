#include<bits/stdc++.h>
using namespace std;
char ar[31][31];
bool vis[31][31];
int dist[31][31];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int n;
bool isvalid(int i,int j){
    if(i<1 or j<1 or i>n or j>n)
        return false;
    if(vis[i][j] or ar[i][j]=='T')
        return false;
    return true;
}
void bfs(int srcx,int srcy){
    queue<pair<int,int>>q;
    q.push({srcx,srcy});
    dist[srcx][srcy]=0;
    vis[srcx][srcy]=1;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        int d=dist[x][y];
        q.pop();
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(isvalid(newx,newy)){
                dist[newx][newy]=1+d;
                vis[newx][newy]=1;
                q.push({newx,newy});
            }
        }
    }
}
int main() {
    int srcx,srcy,endx,endy;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ar[i][j];
            if(ar[i][j]=='S')
                srcx=i,srcy=j;
            if(ar[i][j]=='E')
                endx=i,endy=j;
        }
    }
    bfs(srcx,srcy);
    cout<<dist[endx][endy]<<endl;
}
