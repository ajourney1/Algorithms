#include<bits/stdc++.h>
using namespace std;
long long mod = 1000000007 ;
typedef long long ll;
/// find the number of palindromic subsequences around each center.
int main()
{
    string s;
    cin >> s;
    ll n = s.length();
    ll dp[n][n];
    memset(dp,0,sizeof dp);
    for(ll len = n-1 ; len >=0 ; --len){
        for(ll i = 0 ; i+len<n ; ++i){
            ll j = i+len;
            if(i == 0 and j==n-1){
                if(s[i] == s[j]) dp[i][j]= 2 ;
                else dp[i][j] = 1 ;
            }
            else{
                /// if characters are equal
                if(s[i]==s[j]){
                    if(i-1>=0){
                        dp[i][j] += dp[i-1][j];
                        dp[i][j] = dp[i][j] % mod ;
                    }
                    if(j+1<=n-1){
                        dp[i][j] += dp[i][j+1];
                        dp[i][j] = dp[i][j] % mod ;
                    }
                    if(i-1 < 0 or j+1 >= n){
                        dp[i][j]+= 1;
                        dp[i][j] = dp[i][j] % mod ;
                    }
                }
            /// if not equal
                else if(s[i]!=s[j]){
                    ll sum = 0 ;
                    if(i -1 >=0){
                        sum = sum + dp[i-1][j];
                        sum = sum  % mod ;
                    }
                    if(j+1<=n-1){
                        sum = sum + dp[i][j+1] ;
                        sum = sum  % mod ;
                    }
                    if(i-1>=0 and j+1<=n-1){
                        sum = sum - dp[i-1][j+1];
                        sum = sum  % mod ;
                    }
                    dp[i][j] += sum  % mod  ;
                    dp[i][j] = dp[i][j] % mod;
                }
            }
        }
    }
    /// abaa
    for(ll i=0;i<=n-1;++i){
        if(i==0 or i == n-1) cout << 1 << " ";
        else {
            ll res = 0 ;
            if(dp[i-1][i+1] > 0 ){
                ll res = dp[i-1][i+1]  % mod ;
                cout << res << " " ;
            }
            else if(dp[i-1][i+1] <0 ){
                ll res = dp[i-1][i+1] + mod ;
                res = res  % mod ;
                cout << res << " " ;
            }
        }
    }
}
