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
#define emp empty()
#define el endl;cout.flush()
#define be begin()
#define fi first
#define se second
#define br break
#define en end()
#define ro return 0
#define eb emplace_back
#define con continue
#define ms(x) memset(x , 0ll, so x)
#define all(x) (x).be , (x).en
#define acc(x) accumulate((x).be , (x).en , 0ll)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define vlll vector<ll,pair<ll,ll>>
#define vlvl vector<pair<ll,ll>,ll>>
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;

const ll maxx = 1e5 + 5 ;
vl v[maxx] ;

void dfs1(ll curr , ll par)
{
    for(auto &x : v[curr]){
        if(x == par) con ;
        cout <<"x is " << x << " curr is " << curr << el ;
        dfs1(x , curr) ;
    }
}


void dfs2(ll curr , ll par)
{
    for(auto &x : v[curr]){
        if(x == par) con ;
        dfs2(x , curr) ;
        cout << "x is " << x << " curr is " << curr << el ;
    }
}


void dfs3(ll curr , ll par)
{
    for(auto &x : v[curr]){
        if(x == par) con ;
        dfs3(x , curr) ;
    }
    for(auto &x : v[curr]){
        if(x == par) con ;
        cout << "x is " << x << " curr is " << curr  << el ;
    }
}

int main()
{
    ios;
     ll n ;
    cin >> n ;
    forn(i , 1 , n - 1 ) {
       ll x , y ;
       cin >> x >> y;
       v[x].pb(y) ;
       v[y].pb(x) ;
    }
    /*
    7
    1 2
    1 3
    2 4
    2 5
    3 6
    3 7
    */
    cout << "dfs1 " << el ;
    dfs1(1 , 0) ;
    cout << "dfs 2" << el ;
    dfs2(1 , 0 ) ;
    cout << "df3 " << el ;
    dfs3(1 , 0 ) ;
}





























