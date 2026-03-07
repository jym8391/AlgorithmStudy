#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N, M;
int ans;
string board[1005];
bool visited[1005][1005];
int parent[1000005];

int idx(int x,int y) {
    return x*M + y;
}

int _find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = _find(parent[x]);
}

void _union(int x,int y) {
    x = _find(x);
    y = _find(y);
    if(x<y) parent[y] = x;
    else if(x>y) parent[x] = y;
}

void dfs(int x,int y) {
    if(visited[x][y]) return ;
    
    visited[x][y] = true;
    char ch = board[x][y];
    if(ch=='U') {
        _union(idx(x,y),idx(x-1,y));
        dfs(x-1,y);
    }
    else if(ch=='D') {
        _union(idx(x,y),idx(x+1,y));
        dfs(x+1,y);
    }
    else if(ch=='L') {
        _union(idx(x,y),idx(x,y-1));
        dfs(x,y-1);
    }
    else if(ch=='R') {
        _union(idx(x,y),idx(x,y+1));
        dfs(x,y+1);
    }
}

void Solve() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            dfs(i,j);
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(idx(i,j)==parent[idx(i,j)]) { //자신이 루트가 되는 번호
                ans++;
                //cout << i << " " << j << "\n";
            }
        }
    }
    cout << ans << "\n";
}

void input() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> board[i];
    }
    for(int i=0;i<=N*M;i++) {
        parent[i] = i;
    }
}   


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    
    Solve();
    
    return 0;
}
