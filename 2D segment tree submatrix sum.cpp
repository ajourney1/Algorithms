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
const ll maxx = 1005;
ll ini_seg[maxx][4*maxx] ;
ll fin_seg[maxx][4*maxx] ;
ll grid[maxx][maxx] ;
ll n , m ;
void inibuild(ll low , ll high , ll ind , ll strip)
{
    if(low == high){
        ini_seg[strip][ind] = grid[strip][low];
        return ;
    }
    ll mid = (low + high) / 2 ;
    inibuild(low , mid , 2*ind , strip);
    inibuild(mid+1 , high , 2*ind +1 , strip) ;
    ini_seg[strip][ind] = ini_seg[strip][2*ind] + ini_seg[strip][2*ind+1];
    return ;
}
void finbuild(ll low , ll high , ll ind)
{
    if(low == high){
        forn(i , 1 , 2*m-1){
           fin_seg[ind][i] = ini_seg[low][i] ;
        }
        return ;
    }
    else {
        ll mid = (low + high ) / 2 ;
        finbuild(low , mid, 2*ind) ;
        finbuild(mid +1 , high , 2*ind+1 ) ;
        forn(i , 1 ,  2*m -1 ){
           fin_seg[ind][i] = fin_seg[2*ind][i] + fin_seg[2*ind+1][i];
        }
    }
    return ;
}
ll finalquery(ll low , ll high , ll ind , ll x1 , ll x2 , ll node)
{
    if(x2 < low or x1 > high) return 0 ;
    if(x1 <= low and x2 >= high){
        return fin_seg[node][ind];
    }
    ll mid = (low + high ) / 2;
    ll left = finalquery(low , mid , 2*ind , x1 , x2 , node) ;
    ll right= finalquery(mid+1 , high , 2*ind+1 , x1 , x2 , node);
    return left + right ;
}
ll query(ll low , ll high , ll ind , ll y1 , ll y2 , ll x1 , ll x2)
{
    if(y2 < low or y1 > high) return 0 ;
    if(y1 <= low and y2 >= high){
        return finalquery(1, m , 1 ,x1 , x2 , ind) ;
    }
    ll mid = (low + high ) / 2 ;
    ll left = query(low , mid , 2*ind , y1 , y2 , x1 , x2) ;
    ll right = query(mid + 1 , high , 2*ind + 1, y1 , y2 , x1 , x2);
    return left + right;
}
void finalupdate(ll low , ll high , ll ind , ll x , ll val , ll node)
{
    if(x > high or x < low ) return ;
    if(low == high){
        fin_seg[node][ind] = val ;
        return ;
    }
    ll mid = (low + high ) / 2 ;
    finalupdate(low , mid , 2*ind , x , val , node)  ;
    finalupdate(mid + 1, high , 2*ind + 1, x , val , node) ;
    fin_seg[node][ind] = fin_seg[node][2*ind] + fin_seg[node][2*ind+1] ;
    return ;
}
void update(ll low , ll high , ll ind , ll x , ll y , ll val )
{
    if(y > high or y < low ) return ;
    if(low == high){
        finalupdate(1 , m , 1 , x , val , ind) ;
        return ;
    }
    ll mid = (low + high) / 2;
    update(low , mid ,2*ind , x , y , val) ;
    update(mid +1 , high , 2*ind +1 , x , y , val ) ;
    forn(i ,1 , 2*m-1){
       fin_seg[ind][i] = fin_seg[2*ind][i] + fin_seg[2*ind+1][i] ;
    }
}
int main()
{
    ios;
    cin >> n >> m ;
    forn(i , 1 , n ){
      forn(j , 1 , m ){
        cin >> grid[i][j] ;
      }
    }
    forn(i , 1 , n ){
       inibuild(1 , m,1 , i);
    }
    finbuild(1 , n , 1);
    ll q ;
    ll x1 , x2 , y1 , y2 ;
    cin >> y1 >> y2 >> x1 >> x2 ;
    cout << query(1 ,n , 1 , y1 , y2 , x1 , x2) << el ;
    ll x , y , val ;
    cin >> x >> y >> val ;
    update(1 , n ,1 ,  x , y , val) ;
    cout << query(1 , n , 1 , y1 , y2 , x1 , x2 ) << el ;
    return 0 ;
}
