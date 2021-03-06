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
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;

const ll maxx = 1e5 + 5 ;
ll arr[maxx] ;
ll n ;
vl v[maxx] ;
ll sum ;
ll dp[maxx][2] ;
void dfs(ll curr , ll par , ll pos)
{
    ll t=  (arr[curr] >> pos) & 1 ;
    dp[curr][t] = 1;
    dp[curr][t^1]  = 0 ;
    ll res = 0 ;
    for(auto &x : v[curr]){
        if(x == par) con ;
        dfs(x , curr , pos) ;
        res = res + dp[curr][0] * dp[x][1] + dp[curr][1] * dp[x][0] ;
        if(t == 0){
            dp[curr][0] = dp[curr][0] + dp[x][0];
            dp[curr][1] = dp[curr][1] + dp[x][1];
        }
        else if(t==1){
            dp[curr][0] = dp[curr][0] + dp[x][1];
            dp[curr][1] = dp[curr][1] + dp[x][0];
        }
    }
    sum = sum + (res << pos);
}

int main()
{
    ios;
    cin >> n ;
    ms(dp);
    forn(i ,  1 , n ) cin >> arr[i] ;
    forn(i , 1 , n - 1 ) {
       ll x , y;
       cin >> x >> y;
       v[x].pb(y);
       v[y].pb(x);
    }
    /// single pair sum
    forn(i , 1 , n ) sum = sum + arr[i] ;
    forn(i , 0 , 0){
       dfs(1 , 0 , i ) ;
    }
    cout << sum << el ;
    ro ;
}





























