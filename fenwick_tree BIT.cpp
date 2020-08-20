#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
ll bit[400005] , n , arr[100005];
ll getsum(ll ind)
{
    ind = ind + 1;
    ll sum = 0 ;
    while(ind > 0){
        sum+=bit[ind];
        ind-=ind&(-ind);
    }
    return sum;
}
void update(ll index , ll val)
{
    index = index + 1;
    while(index <= n){
        bit[index]+=val;
        index += index&(-index);
    }
}
int main()
{

    cin >> n ;
    for(ll i=0;i<n;++i){
        cin >> arr[i];
    }
    for(ll i=0;i<n;++i){
        update(i , arr[i]);
    }
    ll q = 10 ;
    while(q--){
        ll type ;
        cin >> type;
        if(type == 1){
            ll ind , val ;
            cin >> ind >> val ;
            ll diff = val - arr[ind] ;
            update(ind , diff) ;
        }
        else {
            ll from , to ;
            cin >> from >> to ;
            ll sum = getsum(to) - getsum(from -1) ;
            cout << " sum " << sum << endl ;
        }
    }
    return 0;
}
