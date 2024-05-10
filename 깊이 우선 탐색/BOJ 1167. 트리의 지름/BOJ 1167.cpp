#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>


using namespace std;

int V;
int ans;
int endP; //임의의 정점 x에서 가장 먼 정점인 y
int visited[100001];
vector<pii> v[100001];


/*1. DFS를 통해 임의의 정점(x)으로부터 가장 먼 정점(y)을 구한다.
2. DFS를 통해 구해진 (y)정점으로부터 가장 먼 정점(z)를 구한다.
3. (y) 정점과 (z) 정점을 잇는 경로가 트리의 지름이 된다.
*/

void dfs(int num, int len) {
    
    if(visited[num]) return ;
    
    visited[num] = 1;
    
    if(ans < len) {
        ans = len;
        endP = num;
    }
    
    for(int i = 0; i < v[num].size(); i++) {
        dfs(v[num][i].first, len + v[num][i].second);
    }
    
    return ;
    
}

void input() {
    cin >> V;
    for(int i=0;i<V;i++) {
        int parent, child, cost;
        cin >> parent;
        while(1) {
            cin >> child;
            if(child == -1) break;
            cin >> cost;
            v[parent].push_back({child,cost});
            v[child].push_back({parent,cost});
        }

    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    dfs(1,0); //루트노드 1번(임의의 점)부터 시작, x->y y를 구하는 과정

    ans = 0;
    
    memset(visited,0,sizeof(visited));
    
    dfs(endP,0); //y->z를 구하는 과정

    cout << ans << "\n";

    return 0;
}
