#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N;
int adj[1010][1010]; //인접 행렬, adg[i][j] : i와 j사이의 간선 수 
int edgesSum[1010]; //i에 연결된 간선의 수들의 합
int Next[1010]; 
vector<int> circuit; //정답 경로

void getEulerCircuit(int here) {
    for(int &there = Next[here];there<=N;there++) {
        while(adj[here][there]) {
            //양쪽 간선을 모두 지운다.
            adj[here][there]--;
            adj[there][here]--;
            getEulerCircuit(there);
        }
    }
    circuit.push_back(here);
}   

void input() {
    cin >> N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> adj[i][j];
            edgesSum[i] += adj[i][j];
        }
    }
    
    int start = 0;
    for(int i=1;i<=N;i++) {
        if(edgesSum[i]) { //간선이 연결되어 있다면, 시작점이 될 수 있음
            start = i;
        }
        if(edgesSum[i]%2) { 
            //간선이 짝수가 아니라면, 오일러 서킷이 존재할 수 없음
            //오일러 회로는 들어오는 간선과 나오는 간선의 횟수가 같아야하는데, 홀수점이라면 불가능하기 때문
            cout << "-1\n";
            return ;
        }
    }
    for (int i=1;i<=N;i++) Next[i] = 1;
    getEulerCircuit(start);

    for(int V : circuit) {
        cout << V << " ";
    }
    cout << "\n";
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    return 0;
}
