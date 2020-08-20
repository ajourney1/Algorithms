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
const ll maxx = 1e6;
ll p[maxx];
void manacher(string &s)
{
    ll c = 0 , r = 0 ;
    forn(i , 1 , s.len - 1){
       ll mirr = 2*c - i;
       if(i < r){
        p[i] = min(p[mirr] , r - i);
       }
       while(s[i + (1 + p[i])] == s[i - (1+p[i])]){
         p[i]++;
       }
       if(i + p[i] > r){
        c = i ;
        r = i + p[i];
       }
    }
}
int main()
{
    ios;
    string s;
    cin >> s;
    string ss = "";
    ss = ss + "$";
    ll i = 0 ;
    ll n = s.len ;
    forn(i , 0 , n - 1 ){
       ss = ss + "#";
       ss = ss + s[i];
    }
    ss = ss + "#";
    ss = ss + "@";
    s = ss;
    n = s.len ;
    manacher(s);
    ll maxx = 0 ;
    ll ind = -1;
    forn(i , 0 , n ) {
       maxx = max(maxx , p[i]);
    }
    forn(i , 0 , n ){
       if(p[i] == maxx){
        ind = i ;
        br ;
       }
    }
    string ans = "";
    ll now = ind ;
        ll from = now - maxx ;
        ll to   = now + maxx ;
        forn(i , from , to){
          if(s[i] == '#') con ;
          ans = ans + s[i];
        }
    cout << ans << el ;


}





























