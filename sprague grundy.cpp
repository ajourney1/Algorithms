#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
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
#define el endl;cout.flush()
#define be begin()
#define fi first
#define se second
#define br break
#define en end()
#define ro return 0
#define br break
#define eb emplace_back
#define con continue
#define ms(x) memset(x , 0, so x)
#define all(x) (x).be , (x).en
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0ll)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define rng_58 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace2(a,b) cerr <<"a is " << a << " b is " << b << el;
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;
/*
he game starts with 3 piles having 3, 4 and 5 stones, and the player to move may take any positive number of stones upto 3 only from any of the piles
 [Provided that the pile has that much amount of stones]. The last player to move wins. Which player wins the game assuming that both players play optimally?
*/
int main()
{
    ios;
    ll a , b , c;
    cin >> a >> b >> c;
    ll n = max(a, max(b,c)) ;
    ll grundy[n+1] ;
    ms(grundy) ;
    grundy[0] = 0 ;
    grundy[1] = 1 ;
    grundy[2] = 2 ;
    grundy[3] = 3 ;
    forn(i , 4 , n){
       set<ll> mex ;
       mex.insert(grundy[i-1]);
       mex.insert(grundy[i-2]);
       mex.insert(grundy[i-3]);
       ll j = 0 ;
       ll ans =  0 ;
       while(mex.find(j)!=mex.end()){
          ++j;
       }
       ans = j ;
       grundy[i] = j;
    }
    ll ans = grundy[a] ^ grundy[b] ^ grundy[c] ;
    if(ans ){
        cout << "Player starting at first wins \n" ;
        ro ;
    }
    else {
        cout << "Player starting at 2nd wins \n" ;
        ro ;
    }
    ro ;
}





























