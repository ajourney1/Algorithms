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
#define br break
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
ll n ;
ll grid[100][100] ;
bool safe(ll row , ll col)
{
    ll flag = 0 ;
    forn(i , 1 , row-1){
      if(grid[i][col] == 1) {
        flag = 1 ;
      return false ;
      }
    }
    ll i = row -1 ;
    ll j = col - 1 ;
    while(i >= 1 and j >= 1 ){
         if(grid[i][j] == 1){
            flag = 1 ;
            return false ;
         }
         --i ;
         --j;
    }
    i = row-1 ;
    j = col+1;
    while(i>=1 and j <=n){
        if(grid[i][j] == 1){
            flag = 1 ;
            return false ;
        }
        --i;
        ++j;
    }
    if(flag == 1 ) return false ;
    return true ;

}
bool solve(ll row , ll col)
{
    if(row == n+1 or col == n+1)  return true ;
    for(ll coll =1 ; coll <= n ; ++coll){
        if(safe(row , coll)){
            grid[row][coll] = 1 ;
            if(solve(row+1 , coll)){
                return true ;
            }
            else {
                grid[row][coll] = 0 ;
            }
        }
    }
    return false ;

}
int main()
{
    ios;
    ms(grid) ;
    cin >> n ;
    if(solve(1 , 1) == true){
        forn(i ,1 , n){
          forn(j , 1 , n){
            cout << grid[i][j] << " " ;
          }
          cout << el ;
        }
    }
    else {
        cout << "No solution possible\n" ;
        ro ;
    }
    ro ;

}

