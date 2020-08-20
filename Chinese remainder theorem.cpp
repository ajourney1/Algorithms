#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define mp make_pair
using pll = pair<ll,ll>;
using plll= pair<pll,ll>;
#define vl vector<ll>
#define vll vector<pll>
#define vll vector<pll,ll>
#define cf cout.flush()
ll exp(ll x , ll y,  ll mod)
{
    if(y==0) return 1;
    if(y&1) {ll foo =  (x*exp(y/2)*exp(y/2)) ; foo = foo % mod ; return foo ; }
    else {ll foo =  (exp(y/2)*exp(y/2)) ; foo = foo % mod ; return foo ; }
}
int main()
{
   ios;
   vl num , rem , pp;
   num.pb(-1) ; rem.pb(-1); pp.pb(-1);
   ll n;
   cin >> n ;
   ll t=n;
   while(t--){
    ll x;
    cin >> x;
    num.pb(x);
   }
   t = n ;
   while(t--){
    ll x;
    cin >> x;
    rem.pb(x);
   }
   ll prod = 1;
   for(auto &x:num){
    if(x==-1) continue;
    prod*=x;
   }
   for(auto x:num){
    if(x==-1) continue;
    pp.pb(prod/x);
   }
   vl inv ; inv.pb(-1);
   for(ll i =1 ; i<=n;++i){
       ll a = pp[i];
       ll p = num[i];
       ll foo = exp(a , p-2 , p);
       inv.pb(foo);
   }
    ll sum = 0 ;
    ll mod = prod ;
    for(ll i =1 ; i <= n ; ++i){
        sum = sum + rem[i]%mod * pp[i]%mod * inv[i]%mod;
        sum = sum % mod;
    }
    cout << sum <<endl ;
}






































