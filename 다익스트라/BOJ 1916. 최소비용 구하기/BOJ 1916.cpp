#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>

using namespace std;

int N, M;
int S,E; //시작 도시, 도착 도시
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
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(cost > dist[cur]) continue;
        
        for(int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int ncost = v[cur][i].second;
            if(dist[next] > ncost + cost) {
                dist[next] = ncost + cost;
                pq.push({-dist[next], next});
            }
        }
    }
}

void input() {
    cin >> N;
    cin >> M;
    int s,e,t;
    for(int i = 0; i < M; i++) {
        cin >> s >> e >> t;
        v[s].push_back({e,t});
    }
    cin >> S >> E;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    
    dijkstra(S);

    cout << dist[E] << "\n";

    return 0;
}
