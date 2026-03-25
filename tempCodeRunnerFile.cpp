#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M, K;

void input() {
    cin >> N >> M >> K;
}

int f() {
    int ans = K * M; // 도훈이가 직접 설치한 에디터의 수 
    int R = N-K; // 남은 컴퓨터의 수 
    ans += R/M;
    if(R % M) ans++;
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    cout << f();

    return 0;
}