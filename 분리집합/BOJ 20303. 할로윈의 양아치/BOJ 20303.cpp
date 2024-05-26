#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;


int N, M ,K;

int candy[30005];
int parent[30005];
int person[30005];
int dp[30005]; //dp[i][k] = i집합까지 선택하고, k명을 선택했을 때 얻을 수 있는 사탕의 최댓값  

void init() {
    for(int i=0;i<=N;i++) {
        parent[i] = i;
        person[i] = 1;
    }
}

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void union_find(int x,int y) {
    x = find(x);
    y = find(y);
    if(x!=y) {
        person[x] += person[y];
        candy[x] += candy[y];
        parent[y] = x;
        
    }
}

void input() {
    cin >> N >> M >> K;
    init();
    for(int i=1;i<=N;i++) {
        cin >> candy[i];
    }
    for(int i=1;i<=M;i++) {
        int a, b;
        cin >> a >> b;
        if(b<a) swap(a,b);
        union_find(a,b);
    }
}   

void Solve() {
    for(int i=1;i<=N;i++) {
        if(parent[i] != i) continue; //집합의 루트가 아닌 부분은 제외한다.  
        for(int j=K-1;j-person[i]>=0;j--) {
            dp[j] = max(dp[j], dp[j-person[i]] + candy[i]);
        }
    }
    cout << dp[K-1] << "\n";
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    
    Solve();

    
    return 0;
}
