#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N, M;


bool check[1005][1005];
vector<int> post[1005]; //나중에 나오는 가수
vector<int> pre[1005]; //먼저 나오는 가수
vector<int> answer;

void Solve() {
    
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int K;
        cin >> K;
        vector<int> v(K+1);
        for(int k = 0; k < K; k++) {
            cin >> v[k];
            if(k>0 && !check[v[k]][v[k-1]]) {
                check[v[k]][v[k-1]] = true; //중복 간선 제거
                pre[v[k]].push_back(v[k-1]); 
                post[v[k-1]].push_back(v[k]); 
            }
        }

    }
    
    queue<int> pq;
    //조건만 만족하면 순서는 상관없다고 했으니, 숫자가 작은것부터
    
    for(int i = 1; i <= N; i++){
        if(pre[i].empty()) { //선행 조건이 없다면
            pq.push(i); //현재 노드 삽입
        }
    }
    
    while(!pq.empty()) {
        int cur = pq.front();
        pq.pop();
        
        answer.push_back(cur);
        
        for(auto p : post[cur]) { //p :  현재 노드 뒤에 있는 노드들
            for(int i=0;i<pre[p].size();i++) {
                if(pre[p][i] == cur){ //현재 노드는 완료되었으니, 선행조건에서 지워줌
                    pre[p].erase(pre[p].begin() + i); //간선이 중복될수도 있으니 break는 없이
                }
            }
            if(pre[p].empty()){ //선행 조건이 없어졌다면, 큐에 삽입
                pq.push(p);
            }
        }
    }
    
    if(answer.size()!=N) {
        cout << 0 << "\n";
        return ;
    }
    else {
        for(int i=0;i<answer.size();i++) cout << answer[i] << "\n";
    }
    
}   


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    Solve();
    return 0;
}
/* 중복 간선이 문제가 되는 경우를 처리해야함.
2 3 
2 1 2
2 1 2
2 1 2
0
*/
