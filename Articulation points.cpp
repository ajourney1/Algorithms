#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define cl clear() ;
#define vl vector<ll>
#define sz size()
#define len length()
#define el endl;cout.flush()
#define be begin()
#define fi first
#define se second
#define br break
#define en end()
#define ro return 0
#define br break
#define eb emplace_back
#define con continue
#define ms(x) memset(x , 0, so x)
#define all(x) (x).be , (x).en
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0ll)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll anstor<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace2(a,b) cerr <<"a is " << a << " b is " << b << el;
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;
vector<ll > v[100005] , ans;
ll visited[100005] , low[100005] , vtime[100005] , rootchild = 0 , timee = -1 ;
void dfs(ll curr , ll par)
{
    visited[curr] = 1 ;
   ++timee;
   low[curr] = timee ;
   vtime[curr] = timee ;
   for(auto &child : v[curr]){
      if(visited[child] == 1) con ;
      if(curr == 1){
        ++rootchild ;
        if(rootchild >=2){
            ans.pb(1) ;
        }
      }
      dfs(child , curr) ;
   }
   ll maxx = 0 ;
   for(auto &x : v[curr]){
      maxx = max(maxx , low[x]) ;
   }
   ll minn = 1e18 ;
   for(auto &x : v[curr]){
      if(x == par ) con ;
      minn = min(minn , low[x]);
   }
   minn = min(minn , low[curr]) ;
   low[curr] = minn ;
   if(vtime[curr] <= maxx){
    if(curr != 1) ans.pb(curr) ;
   }
}
int main()
{
    ios;
    ll n , e ;
    cin >> n >> e;
    forn(i, 1 , e){
       ll x , y ;
       cin >> x >> y ;
       v[x].pb(y) ;
       v[y].pb(x) ;
    }
    dfs(1 , -1);
    sort( ans.begin(), ans.end() );
    ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
    for(auto &x : ans ) cout << x << " " ;
    cout << el ;
}





















