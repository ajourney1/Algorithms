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
const ll inf = 3e18;
struct Query
{
    Query(){} ;
    ll l , r , x , idx ;
};
struct Array
{
    Array(){} ;
    ll val , idx ;
};
bool cmp1(Array a , Array b )
{
    return a.val > b.val ;
}
bool cmp2(Query q1 , Query q2)
{
    return q1.x > q2.x ;
}
void update(ll *bit , ll idx , ll val , ll n )
{
    while(idx <= n ){
        bit[idx]+=val ;
        idx+=idx & (-idx) ;
    }
}
ll queryy(ll *bit , ll idx ,ll n )
{
    ll res = 0 ;
    while(idx > 0 ){
        res+=bit[idx] ;
        idx-=(idx) & (-idx) ;
    }
    return res ;
}
int main()
{
    ios;
    ll n , q ;
    cin >> n >> q ;
    vl v ;
    forn(i , 1 , n ) {
       ll x;
       cin >> x;
       v.pb(x) ;
    }

    unordered_map<ll ,ll > mpp;
    ll next[n];
    forn(i , 0 , n-1) next[i] = -1;
    for(long long i = n-1 ; i>= 0 ; --i){
        ll curr = v[i] ;
        if(mpp[curr] == 0 ){
            next[i] = inf;
            mpp[curr] = i ;
        }
        else if(mpp[curr]){
            next[i] = mpp[curr];
            mpp[curr] = i ;
        }
    }
    Array arr[n];
    Query query[q];
    forn(i , 1 , n  ) {
       ll x;
       x = next[i-1] ;
       arr[i-1].val = x;
       arr[i-1].idx = i-1;
    }
    forn(i , 1 , q){
       ll ll , rr ;
       cin >> ll >> rr ;
       query[i-1].l = ll ;
       query[i-1].r = rr ;
       query[i-1].x = rr;
       query[i-1].idx = i-1 ;
    }
    sort(arr , arr + n , cmp1 ) ;
    sort(query , query + q , cmp2 );
    ll bit[n+1] ;
    ll curr = 0 ;
    ms(bit) ;
    ll ans[q] ;
    forn(i , 0 , q-1) {
       ans[i] = -1 ;
    }
    forn(i , 0 ,  q-1){
       while(arr[curr].val > query[i].x and curr < n ){
          update(bit , arr[curr].idx + 1 , 1 , n ) ;
          ++curr ;
       }
       ans[query[i].idx] = queryy(bit , query[i].r+1 , n )  - queryy(bit , query[i].l , n ) ;
    }
    forn(i , 0 , q-1){
    cout << ans[i] << el ;
    }
    ro;
}

