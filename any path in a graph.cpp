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
#define sz size()
#define en end()
#define ro return 0
#define con continue;
#define all(x) (x).be , (x).en
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define forr(i,a,b) for(ll i=a;i<b;++i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
ll n , m ;
vl v[100005];
ll sr , des;
ll visited[100005];
vl path;
bool dfs(ll curr)
{
    visited[curr] = 1;
    path.pb(curr);
    if(curr == des ) return true;
    for(auto &child : v[curr]){
        if(visited[child] == 0) {
            if(dfs(child) == true){
                return true;
            }
            else {
                path.pop_back();
                visited[child] = 1;
            }
        }
    }
    return false;
}
void print()
{
    for(auto &x : path){
        cout << x << " -- >  ";
    }
    cout << el ;
}
int main()
{
    ios;
    cin >> n >> m ;
    forn(i , 1 , m ){
       ll x , y ;
       cin >> x >> y;
       v[x].pb(y);
       v[y].pb(x);
    }
    cin >> sr >> des;
    if(dfs(sr) == true){
        print();
    }
    else cout << "no path exist \n";
    ro ;
}
