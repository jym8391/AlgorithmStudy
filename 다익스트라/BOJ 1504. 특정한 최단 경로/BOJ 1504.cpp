#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>

using namespace std;

int N, M;
int S,E; //시작 도시, 도착 도시
int dist[1001];
int route[1001];
vector<pii> v[1001];
priority_queue<pii,vector<pii>, greater<pii> > pq; 
//기본적으로 최대힙을 사용하는데, 최소힙을 사용하기 위해 greater를 이용했음
vector<int> path; // 경로 기록 

void dijkstra(int start) {
    for(int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()) {
        int cost = pq.top().first;
        //만약 큐에 들어가는 값이 0보다 크다는것이 보장된다면 위처럼 복잡한 선언을 해주는대신 음수값을 넣어주는 방법도 있다.
        //why? 
        int cur = pq.top().second;
        pq.pop();
        
        if(cost > dist[cur]) {
            continue;
        }
        
        for(int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int ncost = v[cur][i].second;
            if(dist[next] > ncost + cost) {
                route[next] = cur; //이전 노드 위치 기록
                dist[next] = ncost + cost;
                pq.push({dist[next], next});
            }
        }
    }
    int T = E;
    while(T) { //경로 역추적, 시작 노드로 가게 되면 시작 노드의 이전노드는 없으므로 종료됨
        path.push_back(T);
        T = route[T]; 
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
    cout << path.size() << "\n";
    for(int i=path.size()-1;i>=0;i--) {
        cout << path[i] << " ";
    }
    cout << "\n";

    return 0;
}
