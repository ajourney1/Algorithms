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
#define el endl;cout.flush()
#define be begin()
#define fi first
#define se second
#define br break
#define sz size()
#define en end()
#define ro return 0
#define br break
#define con continue
#define um unordered_map<ll,ll>
#define ms(x) memset(x , 0, so x)
#define all(x) (x).be , (x).en
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0ll)
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define forr(i,a,b) for(ll i=a;i<b;++i)
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
void seive(ll n)
{
    bool prime[n+2] ;
    memset(prime , true , so prime ) ;
    for(ll p=2;p*p<=n;++p){
        if(prime[p] == true){
            for(ll i=p*p;i<=n;i+=p){
                prime[i] = false;
            }
        }
    }
    forn(i , 2 , n ){
       if(prime[i] == true) {
        cout << i << " " ;
       }
    }
    cout << el ;
    return ;
}
int main()
{
    ios;
    /// Given a number n print all prime numbers smaller of equal to n
    ll n ;
    cin >> n ;
    seive(n) ;

}









