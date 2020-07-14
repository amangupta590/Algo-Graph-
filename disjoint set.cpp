#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vv vector<int>
#define pb push_back
class graph{
    public:
    vv par;
        void build(int n){
            par.resize(n);
            for(int i=0 i<n;i++){
                par[i]=i;
            }
        }
        int get_superparent(int x){
            if(par[x]==x)
                return x;
            else
                return par[x]=get_superparent(par[x]);
        }
        void union(int x,int y){
            int superparent_x=get_superparent(x);
            int superparent_y=get_superparent(y);
            if(superparent_x!=superparent_y){
                par[superparent_y]=superparent_x;
            }
        }
};