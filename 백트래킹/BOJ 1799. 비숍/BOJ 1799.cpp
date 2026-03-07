#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
#define STEP 5
using namespace std;

int N;
int cnt[2]; //흑, 백
int board[11][11];

void input() {
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> board[i][j];
        }
    }
}

bool chk(int x,int y) {

    for(int i = 0;i<x;i++) {
        for(int j=0;j<N;j++) {
            if (board[i][j]==2 && abs(x-i) == abs(y-j)) {//대각선에 위배된다면
                return false;
            }
        }
    }
    
    return true;

}

void Solve(int x,int y,int count,int color) { //대각선 확인하는 법은 y증가량 == x증가량 을 확인해보면됨
    if(y>=N) { //넘어가는 경우
        x++;
        if(y%2==0) y = 1;
        else y = 0;
    }
    if(x>=N) {
        cnt[color] = max(cnt[color],count);
        return ;
    }
    if(board[x][y]==1 && chk(x,y)) { //유효한 위치라면
        //cout << x << " " << y <<"\n";
        board[x][y] = 2;
        Solve(x, y+2, count + 1, color);
        board[x][y] = 1;
    }
    Solve(x, y+2, count, color);

}

int main() {
    ios::sync_with_stdio(true); cin.tie(0); cout.tie(0);
    
    input();

    Solve(0,0,0,0); //백 시작
    Solve(0,1,0,1); //흑 시작

    
    //cout << cnt[0] << "\n";
    //cout << cnt[1] << "\n";
    cout << cnt[0] + cnt[1] << "\n";
    
    return 0;
}
