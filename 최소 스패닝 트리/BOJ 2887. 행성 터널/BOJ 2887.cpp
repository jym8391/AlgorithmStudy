#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
#define P 1000000007ll
typedef long long ll;

using namespace std;


int N;
vector<pii> p_x,p_y,p_z; //행성의 x,y,z와 인덱스를 저장하는 벡터
vector<pair<int,pii>> edges;
int parent[100001]; //union find

int find_root(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x]); //경로 압축
}
 
void union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
}

int dist(int a, int b) {
    return abs(a-b);
}

void input() {
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        p_x.push_back({x,i});
        p_y.push_back({y,i});
        p_z.push_back({z,i});
    }
    
    sort(p_x.begin(), p_x.end());
    sort(p_y.begin(), p_y.end());
    sort(p_z.begin(), p_z.end());
    
    for(int i=1;i<N;i++) { //x,y,z별로 N-1개의 간선이 생길것, 3*(N-1)개의 간선 정보 저장
        edges.push_back({dist(p_x[i].first,p_x[i-1].first),{p_x[i-1].second,p_x[i].second}}); // i-1 -> i
        edges.push_back({dist(p_y[i].first,p_y[i-1].first),{p_y[i-1].second,p_y[i].second}}); 
        edges.push_back({dist(p_z[i].first,p_z[i-1].first),{p_z[i-1].second,p_z[i].second}}); 
    }
    
    sort(edges.begin(), edges.end()); //x,y,z별 간선을 합친 것을 오름차순 정렬하면 제일 짧은 것들이 나옴

    for(int i = 0; i <= N; i++) parent[i] = i;

}

void kruskal() {
    vector<pair<int,pii>> mst;
    int ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        
        pair<int,pii> cur_edge = edges[i];

        int f = cur_edge.second.first;
        int s = cur_edge.second.second;
        if (find_root(f) == find_root(s)) continue;  
        union_root(f, s);
        ans += cur_edge.first;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    kruskal();
    
    return 0;
}
