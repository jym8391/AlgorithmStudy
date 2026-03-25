#include <bits/stdc++.h>
using namespace std;

struct points{
    int first, second;
};

int N, M, K;
int f, s;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};
int graph[105][105];
int visited[105][105];
vector<int> Area;

bool inRange(int x,int y) {
    if(x<0||y<0||x>=N||y>=M) return false;
    else return true;
}

bool isBlank(int x,int y) { //비어있는 공간이라면
    if(!inRange(x,y)) return false;
    if(graph[y][x]==1) return false;
    return true; 
}


int bfs(int x, int y) {
    queue<points> q; // (x,y)형식

    int area = 0; //영역의 넓이

    q.push({x,y});
    visited[y][x] = 1;

    while(!q.empty()) {
        area ++;
        points cur = q.front();
        int cur_x = cur.first;
        int cur_y = cur.second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i]; 
            if(!inRange(nx, ny)) continue; //범위 바깥이라면 탐색 중지
            if(isBlank(nx, ny) && !visited[ny][nx]) { //공백이고, 방문한적없다면 탐색
                q.push({nx, ny});
                visited[ny][nx] = 1;
            }
        }
    }
    return area;
}


void input() {
    cin >> M >> N >> K;
    while(K--) {
        int sx, sy; //시작위치
        int ex, ey; //끝위치
        cin >> sx >> sy >> ex >> ey;
        for(int y = sy; y < ey; y++) {
            for(int x = sx; x < ex; x++) {
                graph[y][x] = 1;
            }
        }
    }
}


int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    for(int y = 0; y < M; y++) {
        for(int x = 0; x < N; x++) {
            if(graph[y][x] == 0 && visited[y][x] == 0) {
                int area = bfs(x,y);
                Area.push_back(area);
            }
        }
    }
    sort(Area.begin(), Area.end());
    cout << Area.size() << "\n";
    for(int i=0;i<Area.size();i++) {
        cout << Area[i] << " ";
    }
    cout << "\n";
    return 0;
}
