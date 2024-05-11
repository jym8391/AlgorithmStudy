#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>

using namespace std;

int N,K;
int visited[100001];
int cnt, ans;
queue< pii > q; //위치, 시간

void input() {
    cin >> N >> K;
}

void bfs() {
    
    q.push({N,0});
    
    while(!q.empty()) {
        int cur = q.front().first;
        int t = q.front().second;
        q.pop();
        
        visited[cur] = true;
        
        if(cur == K) { //목적지 도달
            if(cnt == 0) { //최단 경로 첫 발견시
                ans = t; //최단 시간 기록
                cnt++; 
            }
            else if(cnt > 0 && ans == t) { //두번째 부터 최단 경로 발견
                cnt++;
            }
        }
        
        for(int next : {cur + 1, cur - 1, cur * 2}) {
            if(next < 0 || next > 100000 ) continue;
            if(!visited[next]) {
                q.push({next, t + 1});
            }
        }
        
    }
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    
    bfs();
    
    if (N == K) {
		cout << 0 << "\n" << 1 << "\n";
	}
	else {
	    bfs();
	    cout << ans << "\n" << cnt << "\n";
	}
    

    return 0;
}
