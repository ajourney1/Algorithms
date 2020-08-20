#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define vl vector<ll>
#define forn(i,a,b) for(ll i=1;i<=b;++i)
#define forr(i,a,b) for(ll i=0;i<b;++i)
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define cf cout.flush()
const ll maxx = 2e5+5;
ll st[4*maxx] , lazy[4*maxx] , arr[maxx] , n;
void build(ll node , ll l , ll r)
{
    if(l==r){
        st[node] = arr[l];
        return;
    }
    ll mid = (l+r)/2;
    build(2*node , l , mid);
    build(2*node+1,mid+1,r);
    st[node] = st[2*node] + st[2*node+1];
}
void update(ll node , ll l , ll r , ll i , ll j , ll val )
{
    if(lazy[node]){
        st[node]+=(r-l+1)*lazy[node];
        if(l!=r){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(i > r or j < l ) return ;
    if(i<=l and j>=r){
        st[node]+=(r-l+1)*val;
        if(l!=r){
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return ;
    }
    ll mid = (l+r)/2;
    update(2*node , l , mid , i , j , val);
    update(2*node+1 , mid+1, r , i , j , val);
    st[node] = st[2*node] + st[2*node + 1] ;
    return ;

}
ll query(ll node , ll l , ll r ,ll i , ll j)
{
    if(lazy[node]){
        st[node]+=(r-l+1)*lazy[node];
        if(l!=r){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(i > r or j < l) return 0 ;
    if(i<=l and j >=r) return st[node];
    ll mid = (l+r)/2;
    ll left = query(2*node , l , mid , i , j );
    ll right = query(2*node+1 , mid+1 , r , i , j ) ;
    return left + right;
}
int main()
{
   ios;
   cin >> n ;
   forn(i, 1, n){
      cin >> arr[i];
   }
   build(1,1,n);
   ll q;
   cin >> q;
   while(q--)
   {
       ll x;
       cin >> x;
       if(x==1)
       {
           ll st , en , val ;
           cin >> st >> en >> val;
           update(1,1,n,st,en,val);
       }
       else if(x==2)
       {
            ll st , en;
            cin >> st >> en ;
            ll foo = query(1, 1 , n ,st , en );
            cout << foo <<endl;cf;
       }
   }
}
