#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int T;
int N, K, W;

void Solve() {
    cin >> N >> K;
    
    vector<int> v(N+5); //i까지 걸리는시간
    vector<int> post[1005]; //뒤에 지어야될 건물
    vector<int> pre[1005]; //먼저 지어야될 건물
    vector<int> D(N+5); //시간
    
    for(int i = 1; i <= N; i++) {
        cin >> D[i];
    }
    for(int i = 0; i < K; i++) {
        int X, Y; //X->Y
        cin >> X >> Y;
        post[X].push_back(Y);
        pre[Y].push_back(X);
    }
    cin >> W;
    
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    
    for(int i = 1; i <= N; i++){
        if(pre[i].empty()) { //선행 조건이 없다면 
            v[i] = D[i];
            pq.push({v[i], i}); //{처리시간, 현재 노드}
        }
    }
    
    //처리시간이 짧은 것들부터 계산
    while(!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        
        int cur = top.second; //현재 노드
        
        for(auto p : post[cur]) { //p :  현재 노드 뒤에 있는 노드들
            for(int i=0;i<pre[p].size();i++) {
                if(pre[p][i] == cur){ //현재 노드는 완료되었으니, 선행조건에서 지워줌
                    pre[p].erase(pre[p].begin() + i);
                    break;
                }
            }
            if(pre[p].empty()){ //선행 조건이 없어졌다면, 큐에 삽입
                v[p] = v[cur] + D[p];
                pq.push({v[p], p});
            }
        }
    }
    
    cout << v[W] << "\n";
    
}   


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> T;
    while(T--) {
        Solve();
    }
    return 0;
}
