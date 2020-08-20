#include<bits/stdc++.h>
    using namespace std;
    int64_t n,b,r=1e18,i,x,p,d,a[179],c[179];
    int main(){
    	cin>>n>>b;
    	for(i=2;i*i<=b;i++){
    		for(;b%i==0;)c[d]++,a[d]=i,b/=i;
    		if(c[d])d++;
    	}
    	if(b>1)c[d]=1,a[d++]=b;
    	for(i=0;i<d;i++){
    		for(p=0,x=1;n/a[i]>=x;)x*=a[i],p+=n/x;
    		r=min(r,p/c[i]);
    	}
    	cout<<r;
    }
