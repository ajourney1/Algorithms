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
    ll val ;
    node* prev;
    node* next;
    node(){
       prev = NULL;
       next = NULL;
    };
};
int main()
{
    ios;
    ll capacity;
    cin >> capacity;
    ll cnt = 0 ;
    ll q ;
    unordered_map<ll , node*> mpp ;
    cin >> q ;
    node* head = NULL;
    node* last = NULL ;

    while(q--){
        string s;
        cin >> s;
        if(s == "get"){
            ll x ;
            cin >> x;
            if(mpp[x] == NULL){
                cout << "element doesn't exist\n" ;
                con ;
            }
            else {
                cout << "element exist \n" ;
            }
        }
        else if(s=="put"){
            ll x;
            cin >> x;
            if(cnt < capacity){
                if(cnt == 0){
                    node* temp = new node();
                    temp->next = NULL;
                    temp->prev = NULL;
                    temp->val = x;
                    ++cnt ;
                    head = temp ;
                    last = head ;
                    mpp[x] = temp ;
                }
                else {
                    node* temp = new node();
                    temp->prev = last;
                    last->next = temp ;
                    temp->next = NULL;
                    temp->val = x;
                    ++cnt ;
                    last = temp ;
                    mpp[x] = temp ;
                }
            }
            else if(cnt == capacity){
                if(mpp[x] != NULL){
                    node* where = mpp[x] ;
                    node* itsprev = where->prev;
                    node* itsnext = where->next;
          
                    if(itsprev != NULL) itsprev->next = itsnext;
                    if(itsnext != NULL) itsnext->prev = itsprev ;
                    if(itsprev == NULL) head= head->next ;
                    if(itsnext == NULL) last= last->prev ;
                    where->prev = NULL;
                    where->next = NULL;
                    node* temp = new node();
                    temp->val = x;
                    last->next = temp ;
                    temp->next = NULL;
                    temp->prev = last;
                    last = temp ;
                    mpp[x] = temp ;
                }
                else if(mpp[x] == NULL){
                    node* res = head ;
                    head = head->next;
                    mpp[res->val] = NULL;
                    head->prev = NULL;
                    res->next = NULL;
                    node* temp = new node() ;
                    temp->val = x;
                    last->next = temp ;
                    temp->next = NULL;
                    temp->prev = last ;
                    last = temp ;
                    mpp[x] = temp;
                }
            }
            cout << "linked list is " << el;
            node* foo = head;
            while(foo != NULL){
                cout << foo->val << " , " ;
                foo = foo->next;
            }
            cout << el ;
        }
    }
}





























