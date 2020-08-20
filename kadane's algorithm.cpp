#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define vl vector<ll>
#define el endl;cout.flush()
#define be begin()
#define fi first
#define se second
#define br break
#define sz size()
#define en end()
#define ro return 0
#define br break
#define con continue;
#define all(x) (x).be , (x).en
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define forr(i,a,b) for(ll i=a;i<b;++i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
int main()
{
    ios;
    ll n;
    cin >> n ;
    vl v;
    v.pb(-3e18);
    forn(i , 1 , n){
       ll x;
       cin >> x;
       v.pb(x);
    }
    /// dp[i] = maximum subarray sum ending at index i
    ll dp[n+1];
    memset(dp , 0 , so dp);
    dp[1] = v[1] ;
    forn(i , 2 , n){
       ll curr = v[i];
       ll maxsofar = dp[i-1];
       ll maxx = max(maxsofar+v[i] , v[i]);
       dp[i] = maxx;
    }
    ll ans = -3e18-5;
    forn(i , 1 , n ){
       ans = max(ans , dp[i]);
    }
    cout << ans ;
    cout << el ;
}




























