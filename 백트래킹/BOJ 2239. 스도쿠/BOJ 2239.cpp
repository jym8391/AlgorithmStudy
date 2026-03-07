#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
using namespace std;

int board[10][10];
vector<pii> set0;

bool check(int x,int y) {
    int k = board[x][y]; //현재 값
    int x_axis = x/3*3, y_axis = y/3*3;
    
    //3*3 중복 확인
    for(int i=x_axis;i<x_axis+3;i++) { 
        for(int j=y_axis;j<y_axis+3;j++) {
            if(x==i&&y==j) continue;
            if(board[i][j] == k) return false;
        }
    }
    
    //세로 중복 확인 
    for(int i=0;i<9;i++) {
        if(i==x) continue;
        if(board[i][y] == k) return false;
    }
    //가로 중복 확인 
    for(int i=0;i<9;i++) {
        if(i==y) continue;
        if(board[x][i] == k) return false;
    }
    
    return true;
}

void backtracking(int n) {
    int x = set0[n].first, y = set0[n].second;
    
    if(n > set0.size()) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                cout << board[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }
    
    for(int i=1;i<=9;i++) { //답이 여러 개 있다면 그 중 사전식으로 앞서는 것을 출력한다
        board[x][y] = i;
        if(check(x,y)) backtracking(n+1);
        board[x][y] = 0;
    }
    
}


void input() {
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            scanf("%01d", &board[i][j]);
            if(board[i][j] == 0) {
                set0.push_back({i,j});
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(true); cin.tie(0); cout.tie(0);
    
    input();

    backtracking(0);
    
    
    return 0;
}
