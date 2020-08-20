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
#define acc(x) accumulate((x).be , (x).en , 0ll)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;
vl v[100005];
ll n;
ll deg[100005];
ll f[100005] , g[100005];
ll diameter = 0 ;
void dfs(ll curr , ll par)
{

    for(auto &child : v[curr]){
        if(child == par) con ;
        dfs(child , curr) ;
    }
    if(deg[curr] == 1 and curr!=1){
        f[curr] = 0 ;
        return ;
    }
    vl res;
    for(auto &child : v[curr]){
        if(child == par) con ;
        res.pb(f[child]) ;
    }
    sort(all(res)) ;
    ll great1 = res[res.sz-1] ;
    res.pop_back();
    ll great2 = res[res.sz-1] ;
    f[curr] = 1 + great1 ;
    g[curr] = 2 + great1 + great2 ;
    diameter= max(diameter,  max(f[curr] , g[curr]));
    return ;
}
int main()
{
    ios;
    cin >> n;
    forn(i , 1 , n -1 ) {
       ll x , y ;
       cin >> x >> y ;
       v[x].pb(y);
       v[y].pb(x);
       deg[x]++;
       deg[y]++;
    }
    dfs(1 , -1) ;
    cout << "diameter of the tree is " << diameter << el;
}
