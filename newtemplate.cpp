#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exp(ll x,ll y,ll modd) {if(y==0) return 1;ll t=exp(x,y/2,modd);t=t%modd;t=t*t;t=t%modd;if(y%2==1) return (x*t)%modd;return t%modd;}
ll exp(ll x,ll y){if(y==0) return 1;if(y%2==1) return x*exp(x,y/2)*exp(x,y/2);return exp(x,y/2)*exp(x,y/2);}
ll to_int(string &s) {stringstream geek(s);ll x=0;geek>>x;return x;}
ll to_int(char c) {ll x=c-'a';return x;}
#define pb push_back
#define vl vector<ll>
#define forn(i,a,b) for(ll i=a;i<=b;++i)
#define memset(x) memset(x,0ll,sizeof x)
#define all(x) (x).begin(),(x).end()
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main()
{
    ios;
}





























