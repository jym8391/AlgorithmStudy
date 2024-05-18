#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
#define P 1000000007ll
typedef long long ll;

using namespace std;

int N, S;
int arr[100003];
int s; //부분합
int cnt; //s >= S의 개수
int start=0, e=0;

void input() {
    cin >> N >> S;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
}

void f() {
    int mlen = INF;
    while(e<=N) {
        if(s >= S) {
            mlen = min(mlen,e-start);
            s -= arr[start++];

        }
        else {
            s += arr[e++];
        }
    }
    if(mlen == INF) cout << 0 << "\n";
    else cout << mlen << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    f();

    
    return 0;
}
