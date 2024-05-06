#include <iostream>
#include<vector>
#include<queue>
#define INF 1e9+7

using namespace std;

int N,M,X;
vector<pair<int,int>> graph[2][1001]; //정방향, 역방향 간선 모두 입력
vector<int> dist[2]; 


void input() {
    cin>>N>>M>>X;
    int u,v,t;
    for(int i=0;i<M;i++) {
        cin>>u>>v>>t;
        graph[0][u].push_back(make_pair(t,v)); 
        graph[1][v].push_back(make_pair(t,u)); 
    }
    dist[0].resize(N+1, INF); //무한대의 거리로 초기화
    dist[1].resize(N+1, INF); //무한대의 거리로 초기화
}

void Dijsktra(int k) {
    dist[k][X] = 0;
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>> > pq;
    pq.push({0,X});
    
    while(!pq.empty()) {
        int min_cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(min_cost>dist[k][cur]) continue;
        
        for(int i=0;i<graph[k][cur].size();i++) {
            int next_cost = min_cost + graph[k][cur][i].first ;
            int next = graph[k][cur][i].second;
            
            if(next_cost < dist[k][next]) {
                dist[k][next] = next_cost;
                pq.push(make_pair(next_cost,next));
            }
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    input();
    
    Dijsktra(0); //정점들 -> X까지의 최단 거리, 모든 노드들에 대해 계산해야 됨.
    
    Dijsktra(1); //X -> 정점들까지의 최단 거리, 이건 한번만 계산하면 됨
    
    int ans = 0;
    
    for(int i = 1; i <= N; i++){
        ans = max(ans, dist[0][i] + dist[1][i]); //양방향 가중치의 합
    }
    
    cout << ans;
    
    return 0;
}
