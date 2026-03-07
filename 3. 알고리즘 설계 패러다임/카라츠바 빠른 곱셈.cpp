#include <bits/stdc++.h>
using namespace std;

//미완성 코드입니다.

void addTo(vector<int> a, vector<int> b, int k){ // a+=b*(10^k);
	for(int i=0;i<b.size();i++) {
		a[i] += b[i] * pow(10,k);
	}
	for(int i=0;i<a.size();i++) {
		while(a[i]>=10) {
			a[i]-=10;
			a[i+1]++;
		}
	}

}
void subFrom(vector<int> a, vector<int> b) { // a-=b;
  for (int i = 0; i < a.size(); i++) {
    a[i] -= b[i];
    while(a[i] < 0) {
      a[i] += 10;
      a[i+1]--;
    }
  }
}
vector<int> karatsuba(vector<int> a, vector<int> b) {
	int an = a.size();
	int bn = b.size();
	if(an<bn) return karatsuba(b,a);
	if(!an||!bn) return vector<int> ();
	int half = an/2;
	//a,b를 두개로 분리
	vector<int> a0(a.begin(),a.begin()+half);
	vector<int> a1(a.begin()+half,a.end());
	vector<int> b0(b.begin(),b.begin()+min<int>(b.size(),half));
	vector<int> b1(b.begin()+min<int>(b.size(),half),b.end());

	vector<int> z2 = karatsuba(a1,b1); // z2 = a1 * b1
	vector<int> z0 = karatsuba(a0,b0); // z0 = a0* b0
	addTo(a0,a1,0);
	addTo(b0,b1,0);

	vector<int> z1 = karatsuba(a0,b0);
	subFrom(z1,z0);
	subFrom(z1,z2);

	vector<int> ret;
	addTo(ret,z0,0);
	addTo(ret,z1,half);
	addTo(ret,z2,half+half);
	return ret;
 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string A,B;
	vector<int> a,b;
	cin>>A>>B;
	a.resize(A.length());
	b.resize(B.length());
	for(int i=A.size()-1;i>=0;i--) {
		a[i] = A[i];
	}
	for(int i=B.size()-1;i>=0;i--) {
		b[i] = B[i];
	}
	vector<int> res = karatsuba(a,b);
	for(int i=0;i<res.size();i++) {
		cout<<res[i];
	}
	cout<<"\n";
	return 0;
}
