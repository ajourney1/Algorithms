#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define fi first
#define mp make_pair
#define ro return 0
#define cf cout.flush()
ll n ;
vl v[200005];
ll st[4*200005];
ll arr[200005];
ll lazy[4*200005];
ll p[200005],t[200005];
vl order;
vl node[200005];
ll index = 1 ;
void dfs(ll curr , ll par)
{
    order.pb(curr);
    node[curr].pb(index);
    for(auto child:v[curr]){
        if(child == par) continue;
        index++;
        dfs(child , curr);
    }
    node[curr].pb(index);
}
void build(ll node , ll L , ll  R)
{
    if(L ==  R)
    {
        st[node] = arr[L];
        return ;
    }
    ll mid = (L + R) / 2 ;
    build(2*node , L , mid);
    build(2*node+1 , mid+1 , R);
    st[node] = st[2*node] + st[2*node + 1];
}
void propogate(ll node , ll L , ll R)
{
    if(L != R){
        lazy[2*node]+=1;
        lazy[2*node]%=2;
        lazy[2*node+1]+=1;
        lazy[2*node+1]%=2;
    }
    lazy[node] = 0;
    st[node] =(R-L+1) - st[node];
}
ll query(ll node , ll L , ll R  , ll i , ll j)
{
    if(lazy[node]){
        propogate(node , L  , R);
    }
    if(j<L or i>R) return 0;
    if(i<=L and j>=R) return st[node];
    ll mid = (L+R)/2;
    ll left = query(2*node , L , mid , i , j );
    ll right = query(2*node+1 ,mid+1, R , i , j);
    return left + right;
}
void update(ll node , ll L , ll R  , ll i , ll j)
{
    if(lazy[node]){
        propogate(node , L , R );
    }
    if(i>R  or j<L ) return;
    if(i<=L and j>=R){
        st[node] = (R-L+1)-st[node];
        if(L!=R){
            propogate(node , L , R);
        }
        return ;
    }
    ll mid = (L+R)/2;
    update(2*node , L , mid , i , j);
    update(2*node+1 , mid+1, R , i , j);
    st[node]= st[2*node]+st[2*node+1];
}
int main()
{
   ios;
   cin >> n ;
   ll p[n+1];
   memset(p , 0 , so p);
   memset(st ,0 , so st);
   memset(lazy , 0 , so lazy);
   memset(t , 0 , so t);
   order.pb(-1);
   p[1] = 1;
   for(ll i=2;i<=n;++i) {
        cin >> p[i];
        ll ancestor = p[i] ;
        ll child = i;
        v[ancestor].pb(child);
        v[child].pb(ancestor);
   }
   dfs(1,-1);
   for(ll i=1;i<=n;++i){
     cin >> t[i];
   }
   memset(arr , 0 , so arr);
   for(ll i=1;i<=n;++i){
      ll val = order[i];
      if(t[val]==1) arr[i]=1;
   }
   ll q;
   build(1 , 1 , n);
   cin >> q;
   while(q--)
   {
       string s;
       ll x ;
       cin >> s ;
       cin >> x;
       if(s=="get"){
         ll st = node[x][0];
         ll en = node[x][1];
         ll foo = query(1 , 1 , n ,st , en);
         cout << foo <<endl ;cf ;continue;
       }
       else if(s=="pow")
       {
           ll st = node[x][0];
           ll en = node[x][1];
           update(1 , 1 , n , st ,en);
       }
   }
}








