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
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace2(a,b) cerr <<"a is " << a << " b is " << b << el;
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;
ll n , m ;
vl v[100005];
ll visited[100005] , low[100005] , disc[100005] , Time = -1;
vector<pll> ans;
void dfs(ll curr , ll par)
{
    visited[curr] = 1 ;
    low[curr] = disc[curr] = ++Time;
    for(auto &to : v[curr]){
        if(to == par) con ;
        if(visited[to]){
            low[curr] = min(low[curr] , disc[to]) ;
        }
        else{
            dfs(to , curr);
            low[curr] = min(low[curr] , low[to]) ;
            if(disc[curr] < low[to]){
                ans.pb({curr ,to});
            }
        }
    }
}
int main()
{
    ios;
    cin >> n >> m ;
    forn( i ,1 , m ) {
       ll x , y;
       cin >>x >> y ;
       v[x].pb(y) ;
       v[y].pb(x) ;
    }
    memset(visited , 0 , so visited) ;
    forn(i , 1 , n){
       if(visited[i] == 0){
        dfs(i , -1);
       }
    }
    cout << ans.sz << el ;
    ro ;
}





























