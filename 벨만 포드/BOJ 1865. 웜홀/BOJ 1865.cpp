#include <bits/stdc++.h>
#define pii pair<int,int>
#define INF 1e9+7
using namespace std;

int TC; //테스트 케이스의 수
int N, M, W, S, E, T;; //정점, 도로, 웜홀 수, 출발, 도착, 시간
int dist[501]; //1->to까지의 거리
void input() {

    cin >> TC;
    
    for(int t=0;t<TC;t++) {
        cin >> N >> M >> W;
        vector<pii> v[505]; //i->j(first), cost(second)
        for(int j = 0; j < M; j++) { //도로 입력
            cin >> S >> E >> T;
			v[S].push_back({E,T});
			v[E].push_back({S,T});
        }
        for(int j = 0; j < W; j++) { //웜홀 입력
            cin >> S >> E >> T;
			v[S].push_back({E,-T});
        }
        //1번을 출발지점으로 삼을거니까 1->1은 거리가 0이라고 설정하고 시작
        for (int i = 2; i <= N; i++) dist[i] = INF;
        dist[1] = 0;
        
        bool cycle = false; //1->1으로 오는 사이클 판단 변수
        
        for(int i = 1; i <= N; i++) { //N-1번 반복, N번째에는 사이클 판단, 계속 반복하면 음수 사이클때문에 무한 반복되기 때문
            for(int from = 1; from <= N; from++) {
                for(int k = 0 ; k < v[from].size(); k++) {
                    int to = v[from][k].first;
                    int cost = v[from][k].second;
                    
                    if(dist[to] > dist[from] + cost) {
                        dist[to] =  dist[from] + cost;
                        if(i==N) cycle = true;
                    }
                }
            }
        }
        
        if(cycle) cout << "YES\n";
        else cout << "NO\n";
        
    }
    
}


int main() {
    ios::sync_with_stdio(true); cin.tie(0); cout.tie(0);
    
    input();
    

    return 0;
}
