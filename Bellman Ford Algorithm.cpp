#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,wt;
    node(int first,int second,int third){
        a=first;
        b=second;
        wt=third;
    }
};
int main() {
    int m,n;
    vector<node>arr[100001];
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        arr.push_back((u,v,w));
    }
    vector<int>dis(n+1,INT_MAX);
    int src;
    cin>>src;
    dis[src]=0;
    for(int i=1;i<=n;i++){
        for(auto ss:arr){
            if(dist[ss.a]+ss.wt<dist[ss.b]){
                dist[ss.b]=ss+dist[ss.a];
            }
        }
    }
    //for negative weight cycle
    int fl=0;
    for(auto ss:arr){
        if(dist[ss.a]+ss.wt<dist[ss.b]){
                fl=1;
                cout<<"Negative weight cycle";
                dist[ss.b]=ss+dist[ss.a];
            }
    }
    if(!fl){
        for(int i=1;i<=n;i++){
            cout<<i<<" "<<dist[i]<<endl;
        }
    }

}
