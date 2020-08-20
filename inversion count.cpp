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
#define br break
#define sz size()
#define en end()
#define ro return 0
#define br break
#define con continue;
#define um unordered_map<ll,ll>
#define all(x) (x).be , (x).en
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define forr(i,a,b) for(ll i=a;i<b;++i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define ms(x) memset(x , 0 , so x)
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
const ll maxx = 2e5+5;
ll n ;
ll arr[maxx];
ll fw[maxx];
ll cnt[maxx];
ll brr[maxx];
vl v;
ll query(ll ind)
{
    ind = ind;
    ll res = 0 ;
    while(ind >0){
        res = res + fw[ind];
        ind-=(ind)&(-ind);
    }
    return res ;
}
void update(ll index)
{
    index = index + 1 ;
    while(index <= n ){
        fw[index]+=1;
        index+=(index)&(-index);
    }
}
int main()
{
    ios;
    ms(arr);
    ms(fw);
    cin >> n ;
    forn(i , 0 , n-1){
       cin >> arr[i];
       brr[n-1-i] = arr[i];
       v.pb(arr[i]);
    }
    reverse(all(v));
    um mpp ;
    vl vv = v;
    sort(all(vv));
    ll j = 1;
    forn(i , 0 , n-1){
        if(mpp[vv[i]] == 0){
            mpp[vv[i]] =  j ;
            ++j ;
        }
    }
    forn(i , 0 , n-1){
       v[i] = mpp[v[i]] ;
       --v[i];
    }
    ll cnt = 0 ;
    forn(i , 0 , n-1){
       ll foo = query(v[i]);
       update(v[i]);
       cnt = cnt + foo ;
    }
    cout << cnt << el ;
    ro ;


}
