#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
vector<int>adj[300001];
int vis[300001];
int maxd,maxnode;
void dfs(int node,int d){
	vis[node]=1;
	if(d>maxd)
		maxd=d,maxnode=node;
	for(int child:adj[node]){
		if(vis[child]==0){
			dfs(child,d+1);
		}
	}
}
int main(){
	int n,a,b;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	maxd=-1;
	dfs(1,0);
	for(int i=0;i<=n;i++){
		vis[i]=0;
	}
	maxd=-1;
	dfs(maxnode,0);
	cout<<maxd<<endl;
	return 0;
}

