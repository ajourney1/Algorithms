#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define pb push_back
#define mp make_pair
vector< pair<ll , ll > > v[123456];
ll n , e ;
void dijkartas(ll src)
{
    priority_queue< pair<ll,ll> , vector<pair<ll,ll> > , greater<pair<ll,ll> > > pq;
    vector<ll> dist(n+1 , 3e18);
    pq.push(mp(0,src));
    dist[src] = 0 ;
    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();
        for(auto neighbours:v[u]){
              ll v = neighbours.first;
              ll weight= neighbours.second;
              if(dist[v] > dist[u]+weight){
                dist[v] = dist[u]+weight;
                pq.push(mp(dist[v],v));
              }
        }
    }
    for(ll i = 1 ; i <= n ; ++i){
        cout << dist[i] << endl ;
    }

}
int main()
{
    cin >> n >> e;
    for(ll i =1 ; i <= e ; ++i){
        ll x , y , w;
        cin >> x>> y >> w ;
        v[x].pb(mp(y,w));
        v[y].pb(mp(x,w));
    }
    dijkartas(1);
}
