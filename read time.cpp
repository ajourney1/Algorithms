#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define vl vector<ll>
#define endl endl;cf
#define be begin()
#define sz size()
#define en end()
#define all(x) (x).be , (x).en
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0)
#define forn(i,a,b) for(ll i=1;i<=b;++i)
#define forr(i,a,b) for(ll i=0;i<b;++i)
#define rngx mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define cf cout.flush()
const int_least64_t maxx = 2e5+5;
int_least64_t h[maxx] , p[maxx];
int_least64_t n , m ;
bool okk(int_least64_t time)
{
    int_least64_t curr = 1;
    int_least64_t dis = 0;
    int_least64_t visited[m+1];
    memset(visited , 0 , sizeof visited);
    for(int_least64_t i = 1 ; i<=n;++i){
        if(p[curr] >=h[i]){ /// curr = first unmarked position , /// h[i] = current pointer position
            dis = time;
        }
        else if(p[curr] < h[i]){
            int_least64_t move_right_then_left = (time - (h[i]-p[curr]))/2;int_least64_t move_left_then_right = (time - 2*(h[i]-p[curr]));dis = max(move_right_then_left , move_left_then_right);}
          if(dis < 0 ) return false;
          if(dis == 0 ) {
            int_least64_t tim = time ;int_least64_t diff = h[i] - p[curr];if(diff > time) return false;
          }
          int_least64_t nowcurr = -1;
          for(int_least64_t j = curr ; j <= m ;++j){int_least64_t diff = p[j] - h[i];
            if(p[j] <= h[i]) {
                    visited[j] = 1;
                    continue;
            }
            else if(p[j] > h[i]){
                if(diff <= dis) {
                        visited[j] = 1;
                        continue;
                }
                else if(diff > dis){
                    nowcurr = j;
                    break;
                }
             }
          }
          if(nowcurr == -1) return true;
          curr = nowcurr;
    }
    int_least64_t total = 0  ;
    for(int_least64_t i =1 ; i <= m ; ++i){
        if(visited[i] == 1){
            ++total ;
        }
    }
    if ( total == m ) return true;
    else return false;
    return false;
}
int main()
{
    ios;
    cin >> n >> m ;
    for(int_least64_t i=1;i<=n;++i){
        cin >> h[i];
    }
    for(int_least64_t i=1;i<=m;++i){
        cin >> p[i];
    }
    int_least64_t low = 0 , high = 2e17;
    int_least64_t finalanswer = 3e18;
    while(low <= high){
        int_least64_t mid = (low + high) / 2 ;
        if(okk(mid) == true){
            high = mid - 1 ;
            finalanswer = min(finalanswer , mid);
        }
        else if(okk(mid) == false){
            low = mid + 1;
        }
    }
    cout << finalanswer <<endl ;
    return 0 ;
}


