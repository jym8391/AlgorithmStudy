#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
#define P 1000000007ll
typedef long long ll;

using namespace std;

int V, E;
vector<pair<int,pii>> edges;
int parent[10001]; //union find

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
    cin >> V >> E;
    for (int i = 1; i <= V; i++) parent[i] = i;
    for(int i = 0; i< E;i++) {
        int s,e,t;
        cin >> s >> e >> t;
        edges.push_back({t,{s,e}});
    }
    sort(edges.begin(), edges.end());
}

void kruskal() {
    vector<pair<int,pii>> mst;
 
    for (int i = 0; i < edges.size(); i++) {
        
        pair<int,pii> cur_edge = edges[i];
 
        //현재 간선이 잇는 두 정점
        int f = cur_edge.second.first;
        int s = cur_edge.second.second;
 
        //Union-Find로 사이클이 발생하는지 확인
        if (find_root(f) == find_root(s)) continue;        //사이클이 발생한다면 선택하지 않음
 
        //사이클이 발생하지 않는다면 mst에 현재 간선을 추가
        mst.push_back(cur_edge);
        //Parent 관계 갱신
        union_root(f, s);
 
        //만약 정점 개수 v에 대해 v - 1개의 간선을 찾았다면 종료
        if (mst.size() == V - 1) {
            break;
        }
    }
    int ans = 0;
    for(int i = 0; i < mst.size();i++) {
       ans+=mst[i].first; 
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    kruskal();
    
    return 0;
}
