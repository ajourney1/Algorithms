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

const ll p = 31;
const ll mod = 1e9+7;
string s ;
const ll maxx = 1e6+5;
ll has[maxx];
const ll N = mod ;
ll expp(ll x , ll y)
{
    if(y == 0) return 1;
    if(y == 1) return x % mod;
    ll t = expp(x , y/2) ;
    t = t % mod ;
    if(y & 1) {
        return ((x%mod) * (((t % mod) * (t%mod))%mod))%mod;
    }
    else return ((t % mod) * (t % mod))%mod;
}
ll mmi[maxx];

ll findhash(ll i , ll j )
{
    if(i == 0 ) {
        ll foo = has[j] % mod ;
        return foo ;
    }
    else {
        ll foo = has[j] - has[i-1];
        foo = foo % mod;
        foo = foo * mmi[i];
        foo = foo % mod ;
        return foo ;
    }
}

int main()
{
    ios;
    cin >> s ;

    has[0] = s[0] - 'a' + 1 ;
    ll pow = p;
    forn(i , 1 , s.len - 1 ) {
        ll foo = s[i] - 'a' + 1;
        foo = foo * pow;
        foo = foo % mod ;
        pow = pow * p ;
        pow = pow % mod ;
        has[i] = has[i-1] + foo ;
    }
    /// hash[i..j] * p^i = hash[0...j] - hash[0.. i-1] % m ;
    /// hash[i..j] = (k * p^(-i)) % m ;
    /// hash[i..j] = k % m * p^(-i) % m;
    /// let a = p^i , so we have to find a^(-1) % m
    /// a ^ (-1) mod m = a ^ (m-2) % m ;
    ll n = s.len ;
    forn(i , 0 , n-1){
        ll a = expp(p , i) % mod;
        ll foo = expp(a , mod-2) % mod ;
        mmi[i] = foo ;
    }
    ll q;
    cin >> q;
    while(q--){
        ll i , j ;
        cin >> i >> j ;
        ll hashh = findhash(i , j);
        cout << hashh << el ;
    }
}
