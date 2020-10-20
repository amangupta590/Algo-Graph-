#include<bits/stdc++.h>
using namespace std;
int arr[100005],seg[4*100005];
void build(int idx,int s,int e){
    if(s==e){
        seg[idx]=arr[s];
        return ;
    }
    int mid=(s+e)/2;
    build(2*idx+1,s,mid);
    build(2*idx+2,mid+1,e);
    seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
}
int query(int idx,int low,int high,int l,int r){
    if(low>=l and high<=r)
        return seg[idx];
    if(high<l or low>r)
        return INT_MIN;
    int mid=(low+high)/2;
    int left=query(2*idx+1,low,mid,l,r);
    int right=query(2*idx+2,mid+1,high,l,r);
    return max(left,right);
}
void update(int idx,int low,int high,int changidx){
    if(low==high){
        seg[idx]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    if(changidx<=mid)
        update(2*idx+1,low,mid,changidx);
    else
        update(2*idx+2,mid+1,high,changidx);
    seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(0,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<endl;
    }
}
