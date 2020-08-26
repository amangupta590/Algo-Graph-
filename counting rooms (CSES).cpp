#include<bits/stdc++.h>
using namespace std;
bool isvalid(vector<vector<char>>&arr,int i,int j,int n,int m){
    if(i<0 or i>=n or j<0 or j>=m)
        return false;
    if(arr[i][j]=='#')
        return false;
    return true;    
}
void dfs(vector<vector<char>>&arr,int i,int j,int n,int m){
    arr[i][j]='#';
    if(isvalid(arr,i+1,j,n,m))
        dfs(arr,i+1,j,n,m);
    if(isvalid(arr,i-1,j,n,m))
        dfs(arr,i-1,j,n,m);
    if(isvalid(arr,i,j+1,n,m))
        dfs(arr,i,j+1,n,m);
    if(isvalid(arr,i,j-1,n,m))
        dfs(arr,i,j-1,n,m);    
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j]; 
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.'){
                count++;
                dfs(arr,i,j,n,m);
            }
        }
    }
    cout<<count;
}
