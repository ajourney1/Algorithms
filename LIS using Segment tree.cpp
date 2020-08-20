#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define cl clear() ;
#define vl vector<ll>
#define sz size()
#define len length()
#define emp empty()
#define el endl;cout.flush()
#define be begin()
#define fi first
#define se second
#define br break
#define ro return 0
#define eb emplace_back
#define con continue
#define ms(x) memset(x , 0ll, so x)
#define all(x) (x).be , (x).en
#define acc(x) accumulate((x).be , (x).en , 0ll)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;

const ll maxx = 1e5 ;
ll tree[4*maxx];
vector<pair<ll,ll>> v;

struct op
{
    bool operator()(const pair<ll,ll> &a  , const pair<ll,ll> &b)
    {
        if(a.fi == b.fi) return a.se > b.se ;
        return a.fi < b.fi;
    }
};

void update(ll low , ll high , ll node , ll index , ll val)
{
    if(low > index or high < index) return ;
    if(low == high){
        tree[node] = val;
        return ;
    }
    ll mid = (low + high) / 2;
    update(low , mid , 2*node + 1 , index , val) ;
    update(mid + 1 , high , 2*node + 2 , index , val ) ;
    tree[node] = max(tree[2*node+1] , tree[2*node+2]) ;
}

ll query(ll low , ll high , ll node , ll st , ll endd)
{
    if(low > high) return 0 ;
    if(st > high or endd < low ) return 0 ;
    if(st <= low and endd >= high){
        return tree[node] ;
    }
    ll mid = (low + high) / 2 ;
    ll left = query(low , mid , 2*node + 1 , st , endd) ;
    ll right = query(mid + 1 , high , 2 * node + 2 , st , endd) ;
    return max(left , right) ;

}

int main()
{
    ios;
    ll n ;
    cin >> n ;
    forn(i , 0 , n - 1 ){
        ll x;
        cin >> x;
        v.pb({x , i});
    }
    sort(v.begin() , v.end() , op()) ;
    forn(i , 0 , n - 1 ){
        ll maxxtillnow =  1 + query(0 , n -1 , 0 , 0 , v[i].second - 1) ;
        update(0 , n -1 , 0 , v[i].second , maxxtillnow) ;
    }
    ll lis = tree[0] ;
    cout << lis << el ;
    ro ;
}
