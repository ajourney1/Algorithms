
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
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0ll)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
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
ll grid[1005][1005];
ll visited[1005][1005];
ll minn = 1e18 ;
ll n , m ;
ll r , c ;
ll moves= 0 ;
void solve(ll row , ll col , ll moves )
{
    if(row == r and col == c){
        minn = min(minn , moves ) ;
        return ;
    }
    bool canmove = false ;
    bool right = false ;
    bool left = false ;
    bool up = false ;
    bool down = false ;
    if(col + 1 <= m and visited[row][col+1 ] == 0 and grid[row][col+1] == 0 ) {
        right = true ;
    }
    if(col - 1 >= 1 and visited[row][col-1] == 0 and grid[row][col-1] == 0) {
        left = true ;
    }
    if(row +1 <= n and visited[row+1][col] == 0 and grid[row+1][col] == 0 ){
        down = true ;
    }
    if(row - 1 >= 1  and visited[row-1][col] == 0  and grid[row-1][col] == 0 ){
        up = true ;
    }
    if(right == true or left == true or down == true or up == true ){
        canmove = true ;
    }
    if(canmove == false) return ;
    if(right == true ){
        visited[row][col] = 1;
        solve(row , col +1 , moves + 1 ) ;
        visited[row][col] = 0;
    }
    if(left == true ){
        visited[row][col] = 1;
        solve(row , col -1 , moves + 1 ) ;
        visited[row][col] = 0;
    }
    if(up == true){
        visited[row][col] = 1;
        solve(row-1 , col , moves + 1 ) ;
        visited[row][col] = 0;
    }
    if(down == true){
        visited[row][col] = 1;
        solve(row + 1 , col , moves + 1 ) ;
        visited[row][col] = 0 ;
     }

}
int main()
{
    ios;
    cin >> n >> m ;
    forn(i , 1 , n ) {
       forn(j , 1 , m ) {
         ll x;
         cin >> x;
         grid[i][j] = x;
       }
    }
    cin >> r >> c;
    solve(1 , 1 , 0 );
    cout << minn << el ;
    ro ;
}



