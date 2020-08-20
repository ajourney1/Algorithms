#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define mp make_pair
#define cf cout.flush()
ll dist[1001][1001] , ans[1001][1001];
ll n , e ;
void flloyd()
{
    for(ll k=1;k<=n;++k){
        for(ll i = 1;i<=n;++i){
            for(ll j=1;j<=n;++j){
                ans[i][j] = min(ans[i][j] , ans[i][k] + ans[k][j]);
            }
        }
    }
    for(ll i =1 ;i<=n;++i){
        for(ll j =1 ;j<=n;++j){
            cout << ans[i][j] << " " ;
        }
        cout << endl ;
    }
}
int main()
{
   ios;
   cin >> n >> e;
   for(ll i =1 ;i<=1000;++i){
    for(ll j =1;j<=1000;++j){
        if(i==j) {
                dist[i][j] = 0 ;
                dist[j][i] =0 ;
                ans[i][j] = 0;
                ans[j][i] = 0 ;
                con ;
        }
        dist[i][j] = 3e18;
        dist[j][i] = dist[i][j];
        ans[i][j] = dist[i][j];
        ans[j][i] = ans[i][j];
    }
   }
   for(ll i =1;i<=n;++i){
      ll x ,y , w ;
      cin >> x >> y >> w ;
      dist[x][y] = w ;
      dist[y][x] = w;
   }
   flloyd();

}
