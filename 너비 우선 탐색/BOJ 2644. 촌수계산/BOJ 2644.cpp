#include <bits/stdc++.h>
using namespace std;


int n, m;
int f, s;
vector<int> graph[105];
int visited[105];
bool flag = false;

void input() {
    cin >> n;
    cin >> f >> s;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

void bfs(int start,int ended) {
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if(visited[next]) continue;
            if(next == ended) flag = true;
            q.push(next);
            visited[next] = visited[cur] + 1; //촌수 증가
        }
        if(flag) break;
    }
}


int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    bfs(f,s);
    if(flag) cout << visited[s];
    else cout << "-1";
    return 0;
}
