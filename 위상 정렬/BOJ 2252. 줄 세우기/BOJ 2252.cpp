#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
#define pdd pair<double,double>
#define P 1000000007ll
typedef long long ll;

using namespace std;

int N, M;
vector<int> front[32001]; //앞에 있는 노드
int visited[32001]; //방문 여부

void DFS(int node) {
    
	visited[node] = true;
	
	for(auto n : front[node]) {
	    if(!visited[n]) DFS(n);
	}
	
	cout << node << " ";
}


void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		front[B].push_back(A);
	}
	for (int i = 1; i <= N; i++) {
		if(!visited[i]) DFS(i);
	}
	cout << "\n";
}




int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    input();

	return 0;
}
