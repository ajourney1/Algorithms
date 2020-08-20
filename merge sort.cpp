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
#define el endl;cout.flush()
#define be begin()
#define fi first
#define se second
#define sz size()
#define en end()
#define ro return 0
#define br break
#define con continue
#define um unordered_map<ll,ll>
#define ms(x) memset(x , 0, so x)
#define all(x) (x).be , (x).en
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0ll)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define forr(i,a,b) for(ll i=a;i<b;++i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace2(a,b) cerr <<"a is " << a << " b is " << b << el;
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;
vl v;
ll n;
const ll szz = 1e5;
ll ans[szz] ;
void merge(ll low , ll high)
{
    if(low == high) return ;
    ll mid = (low + high )  / 2 ;
    ll arr[szz] ;
    ms(arr) ;
    ll p1 = low;
    ll p2 = mid + 1;
    ll k = 0;
    while(1){
        if(p1 > mid or p2 > high) br ;
        if(v[p1] <= v[p2]){
            arr[k] = v[p1];
            ++k ;
            ++p1;
        }
        else if(v[p1] > v[p2]){
            arr[k] = v[p2] ;
            ++k ;
            ++p2 ;
        }
    }
    if(p1 == mid+1){
        forn(i , p2 , high){
          arr[k] = v[i];
          ++k;
        }
    }
    else if(p2 == high + 1 ){
        forn(i , p1 , mid){
          arr[k] = v[i] ;
          ++k ;
        }
    }
    ll x = 0 ;
    forn(i , low , high ){
       v[i] = arr[x] ;
       ++x ;
    }
    return ;

}
void solve(ll low , ll high)
{
    ll mid = (low + high) / 2  ;
    if(low == high ) return;
    solve(low , mid);
    solve(mid+1, high);
    merge(low , high);
}
int main()
{
    ios;
    cin >> n ;
    forn(i , 1 , n) {
       ll x;
       cin >> x;
       v.pb(x);
    }
    solve(0 , n-1);
    cout << "sorted array is " << el ;
    forn(i , 0 , n-1 ){
      cout << v[i] << " " ;
    }
    cout << el ;
}
