#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
#define pdd pair<double,double>
#define P 1000000007ll
typedef long long ll;

using namespace std;

int N;
int dp[501][501]; //i->j 까지 행렬제곱 최소 연산 횟수

void input() {
    cin >> N;
    vector<int> r(N), c(N);
    for(int i=0;i<N;i++) {
        cin >> r[i] >> c[i];
    }
    for(int l=1;l<N;l++) {
        for(int i=0;i<N;i++) { //왼쪽
            int j = l+i; //오른쪽
            if(j>=N) break;
            int res = INF;
            for(int k=i;k<j;k++) {
                res = min(res, dp[i][k]+dp[k+1][j] + r[i]*c[k]*c[j]);
            }
            dp[i][j] = res;
        }
    }
    
    cout << dp[0][N-1] << "\n";
}



int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    input();

	return 0;
}
