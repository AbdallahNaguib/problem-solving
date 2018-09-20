#include <bits/stdc++.h>
//#include "graph.cpp"
#define ll long long
#define SZ(x) (int)(x).size()
#define loop(i,n) for(int i=0 ; i<n ; ++i)
#define rep(i,x,n) for(int i=x ; i<=n ; ++i)
#define repeat(i,st,en) for(int i=st ; i<=en ; i++)
#define iteloop(type,data,name,it) for(type<data>::iterator it=name.begin() ;it!=name.end() ; ++it)
using namespace std;//a=97
const int N=20*(int)1e6;
bool prime[N+5];
void create_primes(){
    for(int i=2 ; i*i<=N ; i++){
        if(!(i&1) && i!=2){
            continue;
        }
        int st=i*i;
        while(st<=N){
            prime[st]=false;
            st+=i;
        }
    }
}
int main(){
    cin.sync_with_stdio(false), cin.tie(0);
    memset(prime,1,N);
    prime[0]=0;prime[1]=0;
    create_primes();
    vector<pair<int,int>> ans;
    rep(i,3,N){
        if(prime[i] && prime[i+2]){
            ans.push_back({i,i+2});
        }
    }
    int s;
    while(cin>>s){
        cout<<"("<<ans[s-1].first<<", "<<ans[s-1].second<<")"<<endl;
    }
}
