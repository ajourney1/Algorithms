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
#define emp empty()
#define eps 1e-10
#define gcd(a,b) __gcd(a,b)
#define el endl;cout.flush()
#define be begin()
#define fi first
#define se second
#define br break
#define en end()
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

int main()
{
    ios;
    string text , pattern ;
    cin >> text >> pattern ;
    ll n = text.len ;
    ll m = pattern.len;
    ll lps[m];
    ms(lps);
    ll i = 1 , j = 0 ;
    /// forming LPS array
    while(i < m){
        if(pattern[i] == pattern[j]){
            lps[i] = ++j;
            ++i;
        }
        else if(pattern[i] != pattern[j]){
            if(j!=0){
                j = lps[j-1];
            }
            else if(j == 0){
                lps[i] = 0;
                ++i;
            }
        }
    }
    for(int i = 0 ; i < m ; ++i){
        cout << lps[i] << " " ;
    }
    cout << el;
    /// do KMP search
    i = 0 , j = 0 ;
    bool yes = false;
    while(i < n){
        if(text[i] == pattern[j]){
            ++i;
            ++j;
        }
        if(j == m){
            cout << "there is a pattern at index " << i-j << el ;
            j = lps[j-1] ;
            yes = true;
        }
        else if(text[i] != pattern[j] and i < n){
            if(j!=0){
                j = lps[j-1];
            }
            else {
                ++i;
            }
        }
    }
    if(yes == false){
        cout << "No matching found\n" ;
        ro;
    }
    ro;
}

