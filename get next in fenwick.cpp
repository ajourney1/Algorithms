#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
int main()
{
    ll x ;
    x = 1;
    ll getnext = -1;
    getnext = x +(x&(-x));
    cout << getnext << endl ;
}
