#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll exp(ll x,ll y){if(y==0) return 1;if(y%2 == 1) return x*exp(x,y/2)*exp(x,y/2);return exp(x,y/2) * exp(x,y/2);}
ll exp(ll x,ll y,ll modd) {if(y==0) return 1;ll t=exp(x,y/2,modd);t = t%modd;t=t*t;t=t%modd;if(y % 2 == 1) return (x*t)%modd ;return t%modd;}
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target ("sse4")
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
#define revn(i,a,b) for(ll i=a;i>=b;--i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vs vector<string>
#define vsi vector<pair<string,int>>
#define vll vector<pair<ll,ll> >
#define vlll vector<pair<ll,pair<ll,ll>>>
#define vlvl vector<pair<pair<ll,ll>,ll>>>
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;

const ll maxx = 1e6 ;
vl v[maxx] ;

ll discover[maxx] , beginn[maxx] , endd[maxx] ;
vl dfsorder;
ll timee ;
void dfs(ll curr  , ll par)
{
    discover[curr] = 1;
    beginn[curr] = ++timee;
    dfsorder.pb(curr) ;
    for(auto &x : v[curr]){
        if(discover[x]) con ;
        dfs(x , curr) ;
    }
    endd[curr] = timee ;

}

int main()
{
    ios;
    timee = 0 ;
    ll n ;
    cin >> n ;
    forn(i , 1 , n - 1 ) {
       ll x , y;
        cin >> x >> y;
        v[x].pb(y) ;
        v[y].pb(x) ;
    }
    dfs(1 , -1) ;
    for(auto x : dfsorder){
        cout << x << " " ;
    }
    cout << el;
    forn(i , 1 , n){
       cout << beginn[i] << " " ;
    }
    cout << el ;
    forn(i , 1 ,n ){
       cout << endd[i] << " " ;
    }
    cout << el;
    ll q;
    cin >> q;
    cout << " nodes in subtree of " << q << el ;
    ll from = beginn[q] ;
    ll to   = endd[q] ;
    forn(i , from , to ) {
       cout << dfsorder[i-1] << " " ;
    }
    cout << el ;
    ro ;
}
