#include <bits/stdc++.h>
using namespace std;

long long N, B;
const long long p = 1000;
typedef vector< vector<long long>> matrix;


matrix setMat(int n) {
	matrix res;
	res.resize(N);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			res[i].push_back(0);
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>res[i][j];	
		}
	}
	return res;
}

matrix mulMat(matrix A,matrix B) {
	matrix res(N, vector<long long>(N, 0));
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			long long sum = 0;
			for(int k=0;k<N;k++) {
				sum += ((A[i][k]%p)*(B[k][j]%p))%p;
			}
            res[i][j] = sum%p;
		}
	}
	return res;
}

matrix powMat(matrix A,long long n) {
    matrix res(N, vector<long long>(N, 0));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(i==j) res[i][j]=1;
        }
    }

	while(n) {
		if(n&1) { //홀수
			res = mulMat(res,A);
		}
		A = mulMat(A,A);
		n>>=1;// n/=2
	}
	return res;
}

void printMat(matrix A) {
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>N>>B;
    matrix A;
	A = setMat(N);
	A = powMat(A,B);
	printMat(A);
	return 0;
}
