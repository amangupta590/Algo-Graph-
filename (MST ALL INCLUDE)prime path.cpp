#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10001];
int dist[10001],visit[10001];
vector<int>primes;
bool isprime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
bool isvalid(int a,int b){
    int count=0;
    while(a>0){
        if(a%10!=b%10){
            count++;
        }
        a/=10,b/=10;
    }
    if(count==1)
        return true;
    else
        return false;
}
void buildgraph(){
    for(int i=1000;i<=9999;i++){
        if(isprime(i)){
            primes.push_back(i);
        }
    }
    for(int i=0;i<primes.size();i++){
        for(int j=i+1;j<primes.size();j++){
            if(isvalid(primes[i],primes[j])){
                adj[primes[i]].push_back(primes[j]);
                adj[primes[j]].push_back(primes[i]);
            }
        }
        
    }
}
void bfs(int src){
    queue<int>q;
    q.push(src);
    visit[src]=1;
    dist[src]=0;
    while(!q.empty()){
        int curr=q.front();
        for(int child:adj[curr]){
            visit[child]=1;
            dist[child]=dist[src]+1;
            q.push(child);
        }
    }
}
int main() {
    int t,a,b;
    cin>>t;
    buildgraph();
    while(t--){
        cin>>a>>b;
        for(int i=1000;i<=9999;i++){
            dist[i]=-1;
            visit[i]=0;
        }
        bfs(a);
        if(dist[b]==-1){
            cout<<"Impossible"<<endl;
        }
        else{
            cout<<dist[b]<<endl;
        }
   }
}
