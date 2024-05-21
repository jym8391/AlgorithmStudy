#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
#define P 1000000007ll
typedef long long ll;

using namespace std;

int N, M;
int parent[1000001]; //union find

int find_root(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x]); //경로 압축
}
 
void union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if (x != y) parent[y] = x;
}

void input() {
    cin >> N >> M;
    
    for(int i=0;i<=N;i++) { //초기화
        parent[i] = i;
    }
    
    for(int i=0;i<M;i++) {
        int oper,a,b;
        cin >> oper >> a >> b;
        if(oper==0) {
            union_root(a,b);
        }
        else if(oper==1) {
            if(find_root(a) == find_root(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    return 0;
}
