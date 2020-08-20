#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll exp(ll x,ll y){if(y==0) return 1;if(y%2==1) return x*exp(x,y/2)*exp(x,y/2);return exp(x,y/2)*exp(x,y/2);}
ll exp(ll x,ll y,ll modd) {if(y==0) return 1;ll t=exp(x,y/2,modd);t=t%modd;t=t*t;t=t%modd;if(y%2==1) return (x*t)%modd;return t%modd;}
ll add(ll a,ll b,ll modd) {ll c=a+b;while(c<0)c+=modd;while(c>=modd)c-=modd;c%=modd;return c;}
ll sub(ll a,ll b,ll modd) {ll c=a-b;while(c<0)c+=modd;while(c>=modd)c-=modd;c%=modd;return c;}
ll mul(ll a,ll b,ll modd) {ll c=a*b;while(c<0)c+=modd;while(c>=modd)c-=modd;c%=modd;return c;}
ll to_int(string &s) {stringstream geek(s);ll x=0;geek>>x;return x;}
ll to_int(char c) {ll x=c-'a';return x;}
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
#define con continue
#define ms(x) memset(x,0ll,so x)
#define all(x) (x).be,(x).en
#define acc(x) accumulate((x).be,(x).en,0ll)
#define forn(i,a,b) for(ll i=a;i<=b;++i)

int main()
{
    ios;
    ll n ;
    cin >> n ;
    vl v;
    /// non decreasing
    forn(i , 1 , n ) {
       ll x;
       cin >> x;
       v.pb(x) ;
    }
    ll dp[n];
    ms(dp) ;
    vl lis ;
    lis.pb(v[0]) ;
    forn(i , 1 , n - 1 ){
       ll curr = v[i] ;
       ll prev = lis[ll(lis.sz) - 1] ;
       if(curr >= prev){
        lis.pb(curr);
        con ;
       }
       else if(curr < prev){
          ll low = 0 , high = ll(lis.sz) - 1 ;
          ll justgreaterindex = -1;
          while(low <= high){
            ll mid = (low + high) / 2 ;
            if(lis[mid] <= curr){
                low = mid + 1 ;
                con ;
            }
            else if(lis[mid] > curr){
                justgreaterindex = mid ;
                high = mid - 1;
                con ;
            }
          }
          lis[justgreaterindex] = curr;
          con ;
       }
    }
    ll ans = ll(lis.sz) ;
    cout << ans << endl ;
    ro ;
}





























