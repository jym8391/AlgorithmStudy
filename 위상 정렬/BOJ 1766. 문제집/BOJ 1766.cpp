#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N, M;
vector<int> post[35000]; //나중에 풀 문제
vector<int> pre[35000]; //먼저 풀어야할 문제

void Solve() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int X, Y; //X->Y
        cin >> X >> Y;
        post[X].push_back(Y);
        pre[Y].push_back(X);
    }
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(int i = 1; i <= N; i++){
        if(pre[i].empty()) { //먼저 풀 문제가 없다면
            pq.push(i); //현재 노드
        }
    }
    
    //난이도가 낮은 문제부터 계산
    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        
        cout << cur << " ";
        
        
        for(auto p : post[cur]) { //p :  현재 노드 뒤에 있는 노드들
            for(int i=0;i<pre[p].size();i++) {
                if(pre[p][i] == cur){ //현재 노드는 완료되었으니, 선행조건에서 지워줌
                    pre[p].erase(pre[p].begin() + i);
                    break;
                }
            }
            if(pre[p].empty()){ //선행 조건이 없어졌다면, 큐에 삽입
                pq.push(p);
            }
        }
    }
    cout << "\n";
}   


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    Solve();
    return 0;
}
