#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define mp make_pair
using pll = pair<ll,ll>;
using plll= pair<pll,ll>;
#define vl vector<ll>
#define vll vector<pll>
#define vlll vector<pll,ll>
#define cf cout.flush()
ll n ,  m ;
vector<ll> v[300005];
unordered_map<ll,ll> whiteset , greyset , blackset;
bool dfs(ll curr , ll par)
{
    --whiteset[curr];
    ++greyset[curr];
    for(auto child : v[curr]){
        if(blackset[child]) continue;
        if(greyset[child]) return true;
        if(dfs(child , curr)) return true;
    }
    --greyset[curr];
    --blackset[curr];
    return false;
}
int main()
{
   ios;
   cin >> n >> m ;
   for(ll i =1 ; i<=m;++i){
    ll x , y;
    cin >> x>> y ;
    whiteset[x]++;
    whiteset[y]++;
    v[x].pb(y);
   }
   ll flag = -1;
   for(ll i =1 ; i <= n ; ++i){
    if(whiteset[i]){
        bool foo = dfs(i,-1);
        if(foo == true){
            flag = 0;
        }
    }
   }
   if(flag == 0) {
    cout <<"yes \n";
    return 0 ;
   }
   else cout <<"No\n";
   return 0 ;

}






































