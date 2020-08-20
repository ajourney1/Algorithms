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

const ll maxx = 30 ;
struct node
{
    node* arr[maxx] ;
    bool isend ;
};

node *getnode()
{
    node *pnode = new node();
    pnode->isend = false;
    forn(i , 0 , 25) {
       pnode->arr[i] = NULL;
    }
    return pnode;

}

void insert_(node *root, string key)
{
    node *curr = root ;
    forn(i , 0 , key.length() - 1){
        ll index = key[i] - 'a' ;
        if(curr->arr[index] == NULL){
            curr->arr[index] = getnode() ;
        }
        curr = curr->arr[index];
    }
    curr->isend = true;
}

bool search(node* root , string key)
{
    node* curr = root ;
    forn(i , 0 , key.length() - 1){
        ll index  =  key[i] - 'a' ;
        if(curr->arr[index] == NULL) return false;
        curr = curr->arr[index] ;
    }
    if(curr != NULL and curr->isend == true) return true;
    return false;
}

bool isempty(node* root)
{
    forn(i , 0 , 25 ){
       if(root->arr[i]) return false;
    }
    return true ;
}

node* remove(node* root, string key , ll depth)
{
    if(root == NULL) return NULL;
    ll index = key[depth] - 'a' ;
    if(depth == key.size()){
        if(root->isend == true){
            root->isend = false;
        }
        if(isempty(root)){
            delete(root);
            root = NULL;
        }
        return root;
    }
    root->arr[index] = remove(root->arr[index] , key , depth + 1) ;
    if(isempty(root) and root->isend == false){
        delete(root);
        root = NULL;
    }
    return root ;

}

int main()
{
    ios;
    string keys[] = { "the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero", "heroplane" };
    ll n = sizeof(keys)/sizeof(keys[0]);
    node* root = getnode();
    forn(i , 0 , n -1 ) {
       insert_(root , keys[i]) ;
    }
    bool f1 = search(root , "the") ;
    cout << "f1 " << f1 << el ;
    bool f2 = search(root , "hero");
    cout << "f2 " << f2 << el;
    remove(root , "hero" , 0) ;
    f2 = search(root , "hero");
    cout << "f2 " << f2 << el ;
    ro;
}
