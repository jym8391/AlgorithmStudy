#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>

typedef long long ll;

using namespace std;

int N, E;
int v1, v2;//반드시 거쳐야하는 정점
int dist[1001];
vector<pii> v[1001];
priority_queue<pii,vector<pii>, greater<pii> > pq; 

void dijkstra(int start) {
    for(int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(cost > dist[cur]) {
            continue;
        }
        
        for(int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int ncost = v[cur][i].second;
            if(dist[next] > ncost + cost) {
                dist[next] = ncost + cost;
                pq.push({dist[next], next});
            }
        }
    }
}

void input() {
    cin >> N;
    cin >> E;
    int s,e,t;
    for(int i = 0; i < E; i++) {
        cin >> s >> e >> t;
        v[s].push_back({e,t});
        v[e].push_back({s,t});
    }
    cin >> v1 >> v2;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    //첫 번째 경로 : 1 -> v1 -> v2 -> N
    //두 번째 경로 : 1 -> v2 -> v1 -> N
    //v1을 시작점으로 잡을 경우, v1->1, v1->v2, v1->N 
    //v2를 시작점으로 잡을 경우, v2->1, v2->v1, v2->N 총 6가지가 나오는데 v1<->v2는 겹치기 때문에 5개만 구해줌
    
    ll v1_1, v1_v2, v1_N, v2_1, v2_N;
    ll res1 = 0, res2 = 0, res = 0;
    dijkstra(v1);
    
    v1_1 = dist[1];
    v1_v2 = dist[v2];
    v1_N = dist[N];

    dijkstra(v2);
    
    v2_1 = dist[1];
    v2_N = dist[N];
    
    res1 = v1_1 + v1_v2 + v2_N;
    res2 = v2_1 + v1_v2 + v1_N;
    res = min(res1,res2);

    if(res>=INF) cout << "-1\n";
    else cout << res << "\n";

    return 0;
}
