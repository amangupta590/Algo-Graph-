#include<bits/stdc++.h>
using namespace std;
struct node{
    int a;
    int b;
    int w;
};
node arr[100000];
int par[10001];
bool comp(node a,node b){
    if(a.w<b.w)
        return true;
    return false;
}
int find(int a){
    if(par[a]==-1)
        return a;
    return par[a]=find(par[a]);
}
void merge(int a,int b){
    par[a]=b;
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        par[i]=-1;
    for(int i=0;i<m;i++){
        cin>>arr[i].a>>arr[i].b>>arr[i].w;
    }
    sort(arr,arr+m,comp);
    int sum=0;
    for(int i=0;i<m;i++){
        int a=find(arr[i].a);
        int b=find(arr[i].b);
        if(a!=b){
            sum+=(arr[i].w);
            merge(a,b);
        }
    }
    cout<<sum<<endl;
}
