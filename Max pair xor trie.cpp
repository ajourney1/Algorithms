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
#define vlll vector<ll,pair<ll,ll>>
#define vlvl vector<pair<ll,ll>,ll>>
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define trace3(a,b,c) cerr <<"a is " << a << " b is " << b << " c is " << c << el;
#define trace4(a,b,c,d) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << el ;
#define trace5(a,b,c,d,e) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << el;
#define trace6(a,b,c,d,e,f) cerr <<"a is " << a << " b is " << b << " c is " << c <<" d is " << d << " e is " << e << " f is " << f << el ;

struct node
{
    node *left;
    node *right;
};

node* getnode()
{
    node* temp = new node();
    return temp ;
}

ll exp(ll x , ll y)
{
    if(y == 0) return 1;
    ll t = exp(x , y/2) ;
    t = t * t ;
    if(y & 1) return x * t;
    return t;
}

void insert_(node* root , ll val)
{
    node* curr = root ;
    for(ll i = 31 ; i>=0 ;--i){
        ll b = (val>>i) & 1 ;
        if(b == 0){
            if(curr->left == NULL){
                curr->left = getnode();
            }
            curr = curr->left;
        }
        else{
            if(curr->right == NULL){
                curr->right = getnode();
            }
            curr = curr->right;
        }
    }
}

ll findmax(node* root , ll *arr , ll n)
{
    ll maxxor = INT_MIN;
    forn(i , 0 , n - 1 ) {
       ll val = arr[i] ;
       node* curr = root ;
       ll currxor = 0 ;
       for(ll j = 31 ; j>=0 ; --j){
          ll b = (val >> j) & 1 ;
          if(b == 0){
            if(curr->right){
                curr = curr->right;
                currxor+=exp(2,j);
            }
            else curr = curr->left;
          }
          else {
            if(curr->left){
                curr = curr->left;
                currxor+=exp(2,j) ;
            }
            else curr = curr->right;
          }
       }
       maxxor = max(maxxor , currxor);
    }
    return maxxor;
}

int main()
{
    ios;
    ll n ;
    cin >> n ;
    ll arr[n] ;
    forn(i , 0 , n - 1 ) cin >> arr[i] ;
    node* root = getnode();
    forn(i , 0 , n - 1) {
       insert_(root , arr[i]) ;
    }
    ll foo = findmax(root , arr , n) ;
    cout << foo << el ;

}
