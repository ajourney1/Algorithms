#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define mp make_pair
const ll maxx = 1e6;
#define cf cout.flush()
ll n , m ;
vector<ll> v[maxx];
ll height[maxx] , dp[maxx][22];
void dfsxx(ll curr , ll par){
     height[curr] = 1+height[par];
     dp[curr][0] = par;
     for(auto child : v[curr]){
        if(child == par) continue;
        dfsxx(child , curr);
     }
}
ll lca(ll u , ll v)
{
    if(height[u]<height[v]) swap(u,v);
    ll diff = abs(height[u]-height[v]);
    for(ll i=20;i>=0;--i){
        ll foo = diff;
        if(diff==0) break;
        ll jump = (1<<i);
        if(jump<=diff){
            diff = diff-jump;
            u = dp[u][i];
        }
    }
    if(u==v) return u;
    for(ll i=20;i>=0;--i){
        if(dp[u][i]!=dp[v][i] and dp[u][i]!=0 and dp[v][i]!=0 and dp[u][i]!=-1 and dp[v][i]!=-1){
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];

}

int main()
{
   ios;
   cin >> n >> m;
   for(ll i =1 ; i<=m;++i){
    ll x , y ;
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
   }
   height[0] = -1;
   for(ll i=1;i<=n;++i){
       for(ll j=1;j<=20;++j){
        dp[i][j] = -1;
       }
   }
   dfsxx(1,0);
   for(ll j=1;j<=20;++j){
       for(ll i=1;i<=n;++i){
         if(dp[i][j]==-1){
            dp[i][j] = dp[dp[i][j-1]][j-1];
         }
       }
   }
   ll queries ;
   cin >> queries ;
   while(queries--){
      ll u , v ;
      cin >> u >> v ;
      ll foo = lca(u , v);
      cout << foo <<endl ;cf;
   }
   return 0 ;
}

