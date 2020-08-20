#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef int ll;
typedef long double ld;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll exp(ll x,ll y){if(y==0) return 1;if(y%2 == 1) return x*exp(x,y/2)*exp(x,y/2);return exp(x,y/2) * exp(x,y/2);}
ll exp(ll x,ll y,ll modd) {if(y==0) return 1;ll t=exp(x,y/2,modd);t = t%modd;t=t*t;t=t%modd;if(y % 2 == 1) return (x*t)%modd ;return t%modd;}
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
#define eb emplace_back
#define con continue
#define ms(x) memset(x , 0ll, so x)
#define all(x) (x).be , (x).en
#define acc(x) accumulate((x).be , (x).en , 0ll)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define revn(i,a,b) for(ll i=a;i>=b;--i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vs vector<string>
#define vsi vector<pair<string,int>>
#define vll vector<pair<ll,ll> >
#define vlll vector<pair<ll,pair<ll,ll>>>
#define vlvl vector<pair<pair<ll,ll>,ll>>>
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;

ll arr[205][205] , visited[205][205] , dp[205][205];
ll n , m ;
ll maxx ;
ll mvisited[205][205];
ll solve(ll i , ll j)
{
    if(i < 0 or i >= n or j < 0 or j >= m ) return 0;
    if(visited[i][j] != 0) return dp[i][j] ;
     if(mvisited[i][j] == 1) return dp[i][j] ;
    mvisited[i][j] = 1;
    bool canright = false , canleft = false , candown = false , canup = false;
    if(j + 1 <= m-1 and arr[i][j+1] > arr[i][j]) canright = true;
    if(j - 1 >= 0 and arr[i][j-1] > arr[i][j]) canleft  = true;
    if(i+ 1 <= n - 1 and arr[i+1][j] > arr[i][j] ) candown  = true;
    if(i - 1 >= 0 and arr[i-1][j] > arr[i][j]) canup    = true;

    if(canright == false and canleft == false and candown == false and canup == false){
        dp[i][j] = 1;
        maxx = max(maxx , dp[i][j] ) ;
        return 1;
    }
    if(canright == true){
        visited[i][j] = 1;
        if(visited[i][j+1] != 0) return dp[i][j+1] ;
        else{
            dp[i][j] = max(dp[i][j] , 1 + solve(i , j + 1)) ;
            maxx = max(maxx , dp[i][j]) ;
        }
        visited[i][j] = 0 ;
    }
    if(canup == true){
        visited[i][j] = 1;
        if(visited[i-1][j] != 0) return dp[i-1][j];
        else {

            dp[i][j] = max(dp[i][j] , 1 + solve(i- 1 , j)) ;
            maxx = max(maxx , dp[i][j]) ;
        }
        visited[i][j] = 0 ;
    }
    if(canleft == true){
        visited[i][j] = 1;
        if(visited[i][j-1] != 0) return dp[i][j-1] ;
        else {

            dp[i][j] = max(dp[i][j] , 1 + solve(i , j - 1)) ;
            maxx = max(maxx , dp[i][j]) ;

        }
        visited[i][j] = 0 ;
    }
    if(candown == true){
        visited[i][j] = 1;
        if(visited[i+1][j] != 0) return dp[i+1][j] ;
        else {

            dp[i][j] = max(dp[i][j] , 1 + solve(i + 1 , j)) ;
            maxx = max(maxx , dp[i][j]) ;
        }
        visited[i][j] = 0 ;
    }
    return dp[i][j] ;

}

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size() ;
        if(n == 0) return 0 ;
        ms(mvisited);
        m = matrix[0].size() ;
        maxx = 0 ;
        if(n == 0) return 0 ;
        ms(arr) ; ms(visited) ; ms(dp) ;
        forn(i , 0 , n - 1 ) forn(j , 0 , m - 1 ) arr[i][j] = matrix[i][j] ;
        forn(i , 0 , n -1 ) {
       forn(j , 0 , m - 1 ) {
           if(dp[i][j] != 0){
               maxx = max(maxx , dp[i][j]) ;
               continue ;
           }
          dp[i][j] = max(dp[i][j] , 1) ;
          solve(i , j) ;

       }
    }
        return maxx;
    }
};
