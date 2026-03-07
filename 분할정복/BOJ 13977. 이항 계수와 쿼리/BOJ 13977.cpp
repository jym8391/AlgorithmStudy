#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int M;
long long N,K;
long long factorial[4000001] = {1};


long long expdiv(long long n,long long p) {
	if(p==0) return 1;
	else if(p==1) return n;
	else {
		long long val = 1;
		while(p>0) {
			if(p%2) val = (val*n) % mod;
			p/=2;
			n=(n*n) % mod;
		}
		return val;
	}
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin >> M;
	
	for(int i=1;i<=4000000;i++) {
	    factorial[i] = (factorial[i-1] * i) % mod;
	}
	
	while(M--) {
    	cin>>N>>K;
    
    	long long top = factorial[N]%mod;
    	long long bottom = expdiv(factorial[K]*factorial[N-K]%mod,mod-2); //페르마의 소정리에 의해 a^(p-1) = 1 (mod p)이므로, a^(p-2) = 1/a (mod p)이다. 역원을 구하는 부분
    
    	cout<<(top*bottom)%mod<<"\n"; 
	}

	return 0;
}
