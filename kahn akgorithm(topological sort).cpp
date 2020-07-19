#include<bits/stdc++.h>
using namespace std;
#define vv vector<int>
#define ll long long
vv arr[101];
vv res;
int in[100];
void kahns(int n){
    queue<int>q;
    for(int i=0;i<n;i++){
        if(in[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int curr=q.front();
        res.push(curr);
        for(int node:arr[curr]){
            in[node]--;
            if(in[node]==0)
                q.push(node);
        }
    }
    for(int xx:res){
        cout<<xx<<endl;
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        arr[x].push_back(y);
        in[y]++;
    }
    kahns(n);
}
