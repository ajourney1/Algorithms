#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define vl vector<ll>
#define pll pair<ll,ll>
#define vll vector<pair<ll,ll>>
ll st[4*100000] , lazy[4*100000] , arr[1000010];
void build(ll node, ll L, ll R)
{
	if(L==R)
	{
		st[node]=arr[L];
		return;
	}
	ll M=(L+R)/2;
	build(node*2, L, M);
	build(node*2+1, M+1, R);
	st[node]=min(st[node*2], st[node*2+1]);
}
void propagate(ll node, ll L, ll R)
{
    st[node]+=lazy[node];
	if(L!=R)
	{
		lazy[node*2]+=lazy[node];
		lazy[node*2+1]+=lazy[node];
	}
	lazy[node]=0;
}
void update(ll node, ll L, ll R, ll i, ll j, ll val)
{
	if(lazy[node])
		propagate(node, L, R);
	if(j<L || i>R)
		return;
	if(i<=L && R<=j)
	{
		lazy[node]+=val;
		propagate(node, L, R);
		return;
	}
	ll M=(L+R)/2;
	update(node*2, L, M, i, j, val);
	update(node*2 + 1, M+1, R, i, j, val);
	st[node]=min(st[node*2], st[node*2 + 1]);
}

ll query(ll node, ll L, ll R, ll i, ll j)
{
	if(lazy[node])
		propagate(node, L, R);
	if(j<L || i>R)
		return 1e9;
	if(i<=L && R<=j)
		return st[node];
	ll M=(L+R)/2;
	ll left=query(node*2, L, M, i, j);
	ll right=query(node*2 + 1, M+1, R, i, j);
	return min(left, right);
}
int main()
{
    //ios;
    ll n ;
    cin >> n ;
    for(ll i=1;i<=n;++i){
        cin >> arr[i];
    }
    build(1 , 1 , n);
    cout << "after build\n";
    ll q ;
    cin >> q;
    while(q--)
    {
        cout << "x\n";
        ll x;
        cin >> x;
        if(x==1){
            cout <<"enter updates\n";
            ll qs ,qe , val;
            cin >> qs>> qe >> val;
            update(1,1,n,qs , qe , val);
        }
        else if(x==2){
            cout << "enter queries\n";
            ll qs , qe ;
            cin >> qs >> qe;
            ll foo = query(1 , 1, n , qs , qe);
            cout << foo <<endl ;
        }
    }
}


