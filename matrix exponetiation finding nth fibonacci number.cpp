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
ll F[60][2][2];
const ll mod = 1e9 + 7 ;
ll expp(ll x , ll y)
{
    if(y == 0) return 1;
    else if(y & 1 ) return x * expp(x , y/2) * expp(x , y/2) ;
    else return expp(x , y/2) * expp(x , y/2) ;
}
void exp()
{
    ll cnt = 0;
    while(1){
        if(cnt == 60) br;
        if(cnt == 0){
            F[0][0][0] = 1 ; F[0][0][1] = 1; F[0][1][0] = 1 ; F[0][1][1] = 0;
            ++cnt;
            con ;
        }
        else{
            ll dummy[2][2] ;
            ll foo = cnt-1;
            dummy[0][0] = F[foo][0][0] % mod; dummy[0][1] = F[foo][0][1] % mod; dummy[1][0] = F[foo][1][0] % mod; dummy[1][1] = F[foo][1][1] % mod;
            ll fin[2][2] ;
            ms(fin);
            forn(i , 0 , 1 ) {
               forn(j , 0 , 1){
                  fin[i][j] = 0 ;
                  forn(k ,  0, 1){
                      fin[i][j]+= ((dummy[i][k] % mod) * (dummy[k][j] % mod)) % mod;
                      fin[i][j]%=mod;
                  }
               }
            }
            F[cnt][0][0] = fin[0][0] % mod; F[cnt][0][1] = fin[0][1] % mod; F[cnt][1][0] = fin[1][0] % mod; F[cnt][1][1] = fin[1][1] % mod;
            ++cnt;
        }
    }
}
ll ans[2][2];
void solve(ll n)
{
    ll curr = 60 ;
    ll nn = n - 1;
    vl v;
    while(1){
        if(curr < 0 ) br ;
        ll foo = expp(2 , curr) ;
        if(foo <= nn){
            v.pb(curr) ;
            --curr;
            nn = nn - foo ;

        }
        else {
            --curr;
        }
    }
   if(v.sz == 1) {
        ll ziz = v[0] ;
        ans[0][0] = F[ziz][0][0] ; ans[0][1] = F[ziz][0][1] ; ans[1][0] = F[ziz][1][0] ; ans[1][1] = F[ziz][1][1] ;
        cout << ans[0][0]  << el ;
    }
    else if(v.sz >= 2){
         ll identity[2][2] ;
         identity[0][0] = 1; identity[0][1] = 0 ; identity[1][0] = 0 ; identity[1][1] = 1;
         forn(o , 0 , v.sz - 1 ) {
            ll ziz = v[o];
            ll fin[2][2] ;
            ms(fin);
            ll dummy[2][2] ;
            dummy[0][0] =F[ziz][0][0] ; dummy[0][1] = F[ziz][0][1] ; dummy[1][0] = F[ziz][1][0] ; dummy[1][1] = F[ziz][1][1] ;
            forn(i , 0 , 1 ){
               forn(j , 0 , 1 ) {
                  fin[i][j] = 0 ;
                  forn(k , 0 , 1) {
                       fin[i][j]+= ((identity[i][k] % mod) * (dummy[k][j] % mod)) % mod;
                       fin[i][j]%=mod;
                  }
               }
            }
            identity[0][0] = fin[0][0] ;
            identity[0][1] = fin[0][1] ;
            identity[1][0] = fin[1][0] ;
            identity[1][1] = fin[1][1] ;
         }
        cout << identity[0][0] << el ;
    }
}
int main()
{
    ios;
    /*
    f[n]    = [ 1 1] ^ n-1 * [f[1]]
    f[n-1]    [ 1 0]         [f[0]]
    */
    ll n ;
    cin >> n;
    exp();
    solve(n);
}
