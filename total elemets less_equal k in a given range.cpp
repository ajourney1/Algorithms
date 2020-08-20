#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
struct Array
{
    ll val , idx;
    Array(){}
};
struct Query
{
    ll l , r , x , idx;
    Query(){}
};
ll bit[100005] , n  ,q ;Array arr[100005] ; Query query[100005];
bool op1(Array a , Array b)
{
    return a.val < b.val;
}
bool op2(Query a , Query b)
{
    return a.x < b.x;
}
void update(ll val , ll idx)
{
    idx = idx + 1;
    while(idx <= n ){
        bit[idx]+=val;
        idx+=idx &(-idx);
    }
}
ll queryy(ll idx)
{
    idx = idx +1;
    ll sum = 0 ;
    while(idx>0){
        sum = sum +bit[idx];
        idx-=idx&(-idx);
    }
    return sum;
}
int main()
{
    cin >> n >> q;
    for(ll i=0;i<n;++i){
        ll x;
        cin >> x;
        arr[i].val = x;
        arr[i].idx = i;
    }
    for(ll i = 0 ; i<q ;++i){
        ll ll , rr , xx ;
        cin >> ll >> rr >> xx;
        --ll;--rr;
        query[i].l = ll ;
        query[i].r = rr;
        query[i].x = xx;
        query[i].idx = i;
    }
    sort(arr , arr+n , op1);
    sort(query , query+q, op2);
    ll curr = 0;
    ll ans[q];
    memset(ans , 0 , sizeof ans );
    for(ll i=0;i<q;++i){
        while(arr[curr].val<=query[i].x and curr < n){
            ll idx = arr[curr].idx;
            update(1 , arr[curr].idx);
            curr++;
        }
        ll l = query[i].l;
        ll r = query[i].r;
        ll foo = queryy(r) - queryy(l-1);
        ans[query[i].idx] = foo;
    }
    for(ll i = 0;i<q;++i){
        cout << ans[i] << endl ;
    }
}
