#include <bits/stdc++.h>

using namespace std;

int N,M;
int Maze[1001][1001];
int visited[1001][1001][2]; //0이면 벽을 부순 세계선, 1이면 벽을 부수지 않은 세계선
int dx[4] ={0,0,1,-1};
int dy[4] = {-1,1,0,0};


struct pos {
    int y;
    int x;
    int breakingWall;
};

void input() {
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++) {
            scanf("%1d",&Maze[i][j]);
        }
    }
}

int find(void) {
    queue<pos> Q;
    visited[1][1][0] = 1;
    Q.push({1,1,0});
 
    while(!Q.empty()) {
        pos cur = Q.front();
        Q.pop();
 
        if (cur.y == N && cur.x == M) return visited[cur.y][cur.x][cur.breakingWall];
 
        for (int i = 0; i < 4; i++) {
            pos next;
            next.y = cur.y + dy[i];
            next.x = cur.x + dx[i];
            next.breakingWall = cur.breakingWall;
 
            if (next.y < 1 || next.y > N || next.x < 1 || next.x > M) continue; //범위를 벗어난 경우
            if (visited[next.y][next.x][cur.breakingWall]) continue; //방문한 적 있는 곳인 경우
 
            if (Maze[next.y][next.x] == 0) { //벽이 아닌 경우 
                visited[next.y][next.x][next.breakingWall] = visited[cur.y][cur.x][cur.breakingWall] + 1;
                Q.push({next.y,next.x,cur.breakingWall});
            }
            if (Maze[next.y][next.x] == 1 && next.breakingWall == 0) { //벽인데 부술 수 있는 경우
                visited[next.y][next.x][1] = visited[cur.y][cur.x][cur.breakingWall] + 1;
                next.breakingWall = 1; //벽을 더이상 부술 수 없음
                Q.push(next);
            }
        }
    }
    return -1; //최단 경로가 없다면 -1 출력
    
}

int main() {
    ios::sync_with_stdio(true); cin.tie(0); cout.tie(0);
    
    input();
    
    cout << find() << "\n"; //bfs
    
    return 0;
}
