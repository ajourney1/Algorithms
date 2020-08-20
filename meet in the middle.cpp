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
const ll maxx = 2e5;
vl sumleft , sumright ;
int main()
{
    ios;
    ll n ;
    ll s ;
    cin >> n ;
    cin >> s ;
    vl v ;
    forn(i , 1 ,  n ) {
       ll x ;
       cin >> x;
       v.pb(x) ;
    }
    sort(all(v));
    /// { 2 , 4 , 5 } , { 12 , 34 , 45 }
    /// 0 0 0
    ll szleft = v.size() / 2;
    ll szright = n - szleft ;
    vl left , right ;
    forn(i , 0 , szleft-1){
       left.pb(v[i]) ;
    }
    forn(i , szleft , n-1){
       right.pb(v[i]) ;
    }
    forn(mask , 0 , (1<<szleft)-1){
       ll res = 0 ;
       forn(i , 0 , szleft-1){
          if(mask & (1<<i)){
            ll val = left[szleft-i-1];
            res = res + val ;
          }
       }
       sumleft.pb(res);
    }
    forn(mask , 0 , (1<<szright)-1){
       ll res = 0 ;
       forn(i , 0 , szright-1){
          if(mask&(1<<i)){
            ll val = right[szright - i - 1];
            res = res + val ;
          }
       }
       sumright.pb(res);
    }
    ll maxx = 0 ;
    sort(all(sumleft));
    sort(all(sumright));
    forn(i , 0 , sumleft.size()-1){
       ll res = sumleft[i] ;
       ll low = 0 , high = sumright.size()-1;
       while(low <= high){
          ll mid = (low + high) / 2 ;
          ll val = sumright[mid] ;
          ll tot = res + val ;
          if(tot <= s){
            maxx = max(maxx , tot) ;
            low = mid + 1 ;
          }
          else if(tot > s){
            high = mid - 1 ;
          }
       }
    }
    cout << maxx << el ;
}
