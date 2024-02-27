#include <bits/stdc++.h>    
using namespace std;
 
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
 
/*struct UnionFind{
    vector<int> par,rank,siz;
    UnionFind(int no):par(no,-1),rank(no,0),siz(no,1){  }
 
    int root(int x){
        if(par[x]==-1)return x;
        else return par[x]=root(par[x]);
    }
    bool issame(int x,int y){
        return root(x)==root(y);
    }
    bool unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry)return false;
        if(rank[rx]<rank[ry])swap(rx,ry);
        par[ry]=rx;
        if(rank[rx]==rank[ry])++rank[rx];
        siz[rx]+=siz[ry];
        return true;
    }
    int size(int x){
        return siz[root(x)];
    }
};*/
 
struct 光線{
    光線(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout<<fixed<<setprecision(15);
    }
}光線;
 
signed main(){
    int n,mx;cin>>n>>mx;
    vector<int> a(n),b(n);
    for(int&x:a)cin>>x;
    for(int&x:b)cin>>x;
    vector<vector<int>> dp(n+1,vector<int>(mx+1,0));
    for(int i=0;i<n;++i){
        for(int w=0;w<=mx;++w){
            if(w-a[i]>=0){
                chmax(dp[i+1][w],dp[i][w-a[i]]+b[i]);
            }
            chmax(dp[i+1][w],dp[i][w]);
        }
    }
    cout<<dp[n][mx]<<'\n';
}
