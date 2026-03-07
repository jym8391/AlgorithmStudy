#include <bits/stdc++.h>
#define pii pair<int,int>
#define INF 1e9+7
using namespace std;

struct st{
    int y;
    int x;
    int dist;
};

struct cmp{
    bool operator()(st &A, st &B){
        if(A.dist!=B.dist) {
            return A.dist > B.dist;
        }
        else if(A.y!=B.y){
            return A.y > B.y;
        }
        else return A.x > B.x;
    }
};

int N; 
int board[21][21];
bool visited[21][21];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

st shark; //상어 위치

//큰 물고기는 못지나감, 같은 물고기는 지나갈 수 있음, 작은 물고기는 먹을 수 있음
//자신의 크기만큼 물고기를 먹으면 크기 1증가
//초기 크기는 2

void input() {
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> board[i][j];
            if(board[i][j] == 9) {
                shark = {i,j,0}; //초기 상어 위치
                board[i][j] = 0;
            }
        }
    }
}

void find() {
    priority_queue<st, vector<st>, cmp> pq; //우선순위 큐로 거리, 세로, 가로 순으로 정렬
    
    int shark_size = 2; //상어 크기
    int shark_prey = 0; //먹은 물고기의 수
    int res = 0; //엄마에게 도움을 요청하는 시간
    
    pq.push(shark);
    
    while(!pq.empty()) {
        
        st cur = pq.top();
        
        pq.pop();
        
        visited[cur.y][cur.x] = true;
        
        if(board[cur.y][cur.x] < shark_size && board[cur.y][cur.x] > 0) { //물고기를 먹을 수 있는 경우
            board[cur.y][cur.x] = 0;
            res = cur.dist;
            shark_prey++;
            if(shark_prey == shark_size) { //크기만큼 먹은 경우 크기 1 증가
                shark_size++;
                shark_prey = 0;
            }
            while(!pq.empty()) { //먹은 위치에서 처음부터 다시 탐색
                pq.pop();
            }
            memset(visited,false,sizeof(visited)); //방문 배열 초기화
            pq.push({cur.y,cur.x,cur.dist});
            
        }
        
        
        for(int i=0;i<4;i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if(nx<0||ny<0||ny>=N||nx>=N) continue; //범위 밖
            if(visited[ny][nx]) continue; //방문했다면
            if(board[ny][nx] <= shark_size) { //이동 가능하다면
                visited[ny][nx] = true;
                pq.push({ny,nx,cur.dist+1});
            }
            
        }
    }
    
    cout << res <<"\n"; //더이상 먹을 수 있는 물고기가 없음.
}

int main() {
    ios::sync_with_stdio(true); cin.tie(0); cout.tie(0);
    
    input();
    
    find();
    
    return 0;
}
