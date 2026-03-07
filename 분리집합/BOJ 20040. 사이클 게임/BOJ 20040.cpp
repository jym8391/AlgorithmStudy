#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;


int cycle; //사이클이 생기면 차례 번호를 저장함.

int N, M;
int c = true;

int parent[500005];

void init() {
    for(int i=0;i<N;i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void union_find(int x,int y) {
    x = find(x);
    y = find(y);
    if(x<y) parent[y] = x; 
    else if(x>y) parent[x] = y;
}

void input() {
    cin >> N >> M;
    init();
    for(int i=1;i<=M;i++) {
        int a, b;
        cin >> a >> b;
        if(find(a)==find(b)) { //사이클이 형성됨
            if(c) {
                cycle = i;
                c = false;
            }
            continue;
        }
        union_find(a,b);
    }
    cout << cycle << "\n";

}   


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    
    return 0;
}
