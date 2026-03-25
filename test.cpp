#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M, K;

void input() {
    cin >> N >> M >> K;
}

int f() {
    if(N==K) return K*M; //모두 직접 설치한경우
    return M*(K+1);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    cout << f();

    return 0;
}