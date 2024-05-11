#include <bits/stdc++.h>
#define pii pair<int,int>
#define INF 1e9+7
using namespace std;

int N, M, cnt, day;
int board[101][101];
bool visited[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

queue<pii> cheese; //곧 녹을 치즈의 위치를 저장

void input() {
    cin >> N >> M;
    for(int i = 1; i<= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }
}

void findAir(int y,int x) { 
    if(board[y][x] == 0 ) {
        board[y][x] = -1; //외부 공기
    }
    else return ;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        if(nx>=1 && ny >=1 && ny<=N && nx<=M ) findAir(ny,nx); //외부 공기 찾기
    }
    return ;
}



int main() {
    ios::sync_with_stdio(true); cin.tie(0); cout.tie(0);
    
    input();
    
    while(1) {
		findAir(1,1); //외부공기 판별, 맨 가장 자리는 모두 공기

	    for(int i = 1; i<= N; i++) {
            for(int j = 1; j <= M; j++) {
                if(board[i][j] == 1) {
                    cnt = 0;
                    for(int k = 0; k < 4; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if(board[ny][nx] == -1) {
                            cnt++; // 외부와 접촉했다면
                        }
                    }
                    if(cnt >= 2) cheese.push({i,j}); //2변 이상이 공기라면 녹는 치즈
                }
            }
        }
		
		if(cheese.empty()) break; //녹을 치즈가 없다면 종료
		
		while(!cheese.empty()) { //현재녹일 수 있는치즈를 모두 녹일 때까지 반복
		    pii cur = cheese.front();
		    cheese.pop();
		    board[cur.first][cur.second] = -1; //녹여서 공기로 전환
	        for(int i = 0; i < 4; i++) {
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];
                if(board[ny][nx] == 0) findAir(ny,nx); //녹인 치즈 근방에 공기 찾기
            }
		}
		day++;
    }
    
    cout << day << "\n";

    return 0;
}
