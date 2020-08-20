#include<bits/stdc++.h>
using namespace std;
const long long bsz = 316;
long long res = 0 ;
struct query {
  long long l, r, q_idx, block_idx;

  query() {}
  query(long long _l, long long _r, long long _q_idx) {
    l = _l, r = _r, q_idx = _q_idx, block_idx = _l / bsz;
  }
  bool operator <(const query &y) const {
    if (block_idx != y.block_idx)
      return block_idx < y.block_idx;
    return r < y.r;
  }
};
query queries[1000005];
unordered_map<long long,long long> cnt;
long long n , q, k ;
long long xorr[1000005];
/// add function to add element while traversing
void add(long long u)
{
    long long y = xorr[u] ^ k ;
    res = res + cnt[y] ;
    cnt[xorr[u]]++ ;
}
/// delete function to delete element while traversing
void del(long long u)
{
    cnt[xorr[u]]--;
    long long y = xorr[u] ^ k ;
    res = res - cnt[y] ;
}
void input()
{
    vector<long long> v;
    /// 1 1 1 0 2 3
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(3);
    xorr[1] = v[1];
    for(long long i=2;i<=n;++i){
       xorr[i] = xorr[i-1] ^ v[i] ;
    }
    queries[1] = query(1 , 6 , 1 );
    queries[2] = query(2 , 4 , 2 );
    queries[3] = query(2 , 6 , 3 );
}
void Mo()
{
    sort(queries+1 , queries + q+1 );
    vector<long long> ans(q+1);
    long long l = 1, r = 0;
    res  = 0 ;
    cnt[0] = 1 ;
    for(long long i=1;i<=q;++i){
        while(r < queries[i].r){
           ++r ;
           add(r);
       }
       while(l > queries[i].l){
           l--;
           add(l-1);
       }
       while(l < queries[i].l){
           del(l-1);
           ++l;
       }
       while(r > queries[i].r){
          del(r);
          --r;
       }
       ans[queries[i].q_idx] = res ;
    }
    for(long long i=1;i<=q;++i) {
       cout << ans[i] << endl;
    }
}
int main()
{
    n = 6 , q = 3 , k = 3 ;
    input();
    Mo();
    return 0;

}

