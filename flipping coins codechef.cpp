#include <iostream>
#include <cmath>
//#include "graph.cpp"
#define ll long long
#define SZ(x) (int)(x).size()
#define loop(i,n) for(int i=0 ; i<int(n) ; ++i)
#define rep(i,x,n) for(int i=x ; i<=int(n) ; ++i)
#define repeat(i,st,en) for(int i=st ; i<=en ; i++)
#define iteloop(name,it) for(auto it=name.begin() ;it!=name.end() ; ++it)

using namespace std;
int lazy[2000005];
int st[2000005];
int n,q,l,r,t;
int query(int ss ,int se , int qs , int qe , int si){
    if(lazy[si]&1){
        st[si]=(se-ss+1)-st[si];
        if(ss != se){
            lazy[si*2+1] ^= 1;
            lazy[si*2+2] ^= 1;
        }
        lazy[si]=0;
    }
    if (ss>se || ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return st[si];
    int mid=(ss+se)/2;
    return query(ss,mid,qs,qe,2*si+1)+
    query(mid+1,se,qs,qe,2*si+2);
}
void update(int ss ,int se , int qs , int qe , int si){
    if(lazy[si]&1){
        st[si]=(se-ss+1)-st[si];
        if(ss != se){
            lazy[si*2+1] ^= 1;
            lazy[si*2+2] ^= 1;
        }
        lazy[si]=0;
    }
    if(qs<=ss && qe>=se){
        st[si]=(se-ss+1)-st[si];
        if(ss!=se){
            lazy[si*2+1] ^= 1;
            lazy[si*2+2] ^= 1;
        }
        return;
    }
    if(ss>se || ss>qe || se<qs){
        return;
    }
    int mid=(ss+se)/2;
    update(ss,mid,qs,qe,2*si+1);
    update(mid+1,se,qs,qe,2*si+2);
    st[si]=st[si*2+1] + st[si*2+2];
}

int main(){
    cin.sync_with_stdio(false), cin.tie(0);
    cin>>n>>q;
    loop(i,q){
        cin>>t>>l>>r;
        if(t==0){
            update(0,n-1,l,r,0);
        }else{
            cout<<query(0,n-1,l,r,0)<<endl;
        }
    }
}
