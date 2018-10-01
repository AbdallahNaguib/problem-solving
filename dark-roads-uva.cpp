#include <iostream>
#include <algorithm>
#include <vector>
//#include "graph.cpp"
#define ll long long
#define SZ(x) (int)(x).size()
#define loop(i,n) for(int i=0 ; i<int(n) ; ++i)
#define rep(i,x,n) for(int i=x ; i<=int(n) ; ++i)
#define repeat(i,st,en) for(int i=st ; i<=en ; i++)
#define iteloop(name,it) for(auto it=name.begin() ;it!=name.end() ; ++it)

using namespace std;

ll n,m,x,y,z;
pair<int ,pair<int,int>> arr[200005];
int id[200005];

void init(){
    for(int i=0 ; i<=n ; i++){
        id[i]=i;
    }
}
int root(int x){
    while(id[x] != x){
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}

void union1(int x,int y){
    x=root(x);
    y=root(y);
    id[x]=id[y];
}
ll kruskal(){
    ll res=0;
    sort(arr,arr+m);
    loop(i,m){
        int u=arr[i].second.first;
        int v=arr[i].second.second;
        if(root(u) != root(v)){
            res+=arr[i].first;
            union1(u , v);
        }
    }
    return res;
}

int main(){
    cin.sync_with_stdio(false), cin.tie(0);
    while(cin>>n>>m){
        if(n==0 && m==0){
            break;
        }
        init();
        ll sum=0;
        loop(i,m){
            cin>>x>>y>>z;
            sum+=z;
            arr[i].second.first=y;
            arr[i].second.second=x;
            arr[i].first=z;
        }
        cout<<sum-kruskal()<<endl;
    }
}
