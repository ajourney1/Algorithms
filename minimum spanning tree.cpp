#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define mp make_pair
const ll maxx = 1e7;
using pll = pair<ll,ll>;
#define cf cout.flush()
ll n , m;
vector<pair<pair<ll,ll>,ll>> v , ans;
ll parent[maxx] , Rank[maxx];
ll maxx_wt = 0;
bool op(pair<pair<ll,ll>,ll> &a , pair<pair<ll,ll>,ll> &b)
{
    return a.second < b.second ;
}
ll find(ll x)
{
    while(parent[x]!=x){
        x = parent[x];
    }
    return x;
}
void merge(ll x,ll y)
{
    ll xr = find(x);
    ll yr = find(y);
    if(Rank[xr]<Rank[yr]){
        parent[xr] = parent[yr];
        Rank[yr]++;
    }
    else if(Rank[xr]>Rank[yr]){
        parent[yr] = parent[xr];
        Rank[xr]++;
    }
    else {
        parent[yr] = parent[xr];
        ++Rank[xr];
    }
}
void kruskal()
{
    for(ll i=1;i<=n;++i){
        parent[i] = i;
        Rank[i] = 0;
    }
    for(auto &x:v){
        ll node1 = x.first.first;
        ll node2 = x.first.second;
        ll curr_wt = x.second;
        ll rep_node1 = find(node1);
        ll rep_node2 = find(node2);
        if(rep_node1 != rep_node2){
            merge(node1 , node2);
            maxx_wt+=curr_wt;
            ans.pb(mp(mp(node1 , node2) , curr_wt));
            if(ans.size()>=n-1) break;
        }
    }

}
int main()
{
   ios;
   cin >> n >> m  ;
   memset(parent , 0 , so parent);
   for(ll i = 1; i<=m;++i){
     ll x, y ,w;
     cin >> x>> y  >> w;
     v.pb(mp(mp(x,y) , w));
   }
   sort(v.begin(),v.end(),op);
   kruskal();
   cout << maxx_wt << endl ;cf ;
   cout <<"edges are \n";
   for(auto &x:ans){
    cout << x.first.first << "--> " << x.first.second << " of weight --> " <<x.second <<endl;cf;
   }
   return 0 ;

}



