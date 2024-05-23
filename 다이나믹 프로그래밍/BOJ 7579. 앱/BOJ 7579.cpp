#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N, M;

//메모리를 축으로 삼고 싶지만, 100만이기 때문에 축으로 삼기에는 너무 크기에
//비용을 축으로 삼아 dp계산을 진행 

int Mem[105]; //i번째 메모리
int C[105]; //i번째 프로그램 재활성에 필요한 비용
int dp[10001]; //cost k일때 최대 메모리
int Csum=0;


void input() {
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        cin >> Mem[i];
    }
    for(int i=0;i<N;i++) {
        cin >> C[i];
        Csum+=C[i];
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    for(int i=0;i<N;i++) {
        for(int j=Csum;j>=C[i];j--) {
            dp[j] = max(dp[j], dp[j-C[i]] + Mem[i]);
        }
    }
    int i=0;
    for(i=0;dp[i]<M;i++) {}
    cout << i << "\n";
    
    return 0;
}
