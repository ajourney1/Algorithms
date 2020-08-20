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
#define endl endl;cout.flush()
#define be begin()
#define sz size()
#define en end()
#define all(x) (x).be , (x).en
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define forr(i,a,b) for(ll i=a;i<b;++i)
#define rngx mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
ll n , m , c[12][12], visited[12][12] , ans = 0;
bool issafe(ll row , ll col)
{
    if(row >= 1 and row <=n and col >=1 and col<=m) return true;
    return false;
}
void dfs(ll row, ll col)
{
    visited[row][col] = 1;
    for(ll i=row-1;i<=row+1;++i){
        for(ll j=col-1;j<=col+1;++j){
            if(i == row and j == col) continue;
            if(issafe(i,j) == false or visited[i][j]==1) continue;
            if(c[i][j] == 1){
                ++ans;
                dfs(i,j);
            }
        }
    }
}
int main()
{
    ios;
    cin >> n >> m;
    forn(i , 1 , n ){
      forn(j , 1 , m){
         cin >> c[i][j];
      }
    }
    ll res = 0;
    forn(i , 1, n ){
       forn(j ,  1, m ){
          if(c[i][j]==1 and visited[i][j] == 0){
            ans = 1;
            dfs(i , j);
            res = max(res , ans);
            break;
          }
       }
    }
    cout << res << endl;
}













