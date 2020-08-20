#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define vl vector<ll>
#define forn(i,a,b) for(ll i=1;i<=b;++i)
#define forr(i,a,b) for(ll i=0;i<b;++i)
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define pllll pair<pair<ll,ll> ,ll>
#define cf cout.flush()
ll pref[100005];
unordered_map<ll,ll> mp;
int main()
{
    ios;

    long long  n , k ;
    cin >> n  >> k ;
    vector<long long > v ;
    v.pb(0);
    for(long long  i =1 ; i <= n ;++i){
        long long  x;
        cin >> x;
        v.pb(x);
    }
    for(long long  i =1 ; i <=n; ++i){
        if(i==1) pref[i] = v[i];
        else pref[i] = pref[i-1] + v[i];
    }
    mp[0]  = 1 ;
    /// 0  1  2  3  2
    long long  cnt = 0 ;
    for(long long  i=1;i<=n;++i){
        long long  curr = pref[i];
        long long  tosub= curr - k;
        cnt = cnt + mp[curr - k];
        mp[curr]++;
    }
    cout << cnt << endl ;
    cf;
    return 0 ;

}
















