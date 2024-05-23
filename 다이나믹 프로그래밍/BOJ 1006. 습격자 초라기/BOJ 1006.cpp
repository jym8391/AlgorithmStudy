#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int T;
int N, W;
int enemy[10005][2]; // 0은 아래, 1은 위
int dp[10005][3]; //i까지 아래만 다 채우기, i까지 위만 다채우기, i-1까지만 채우기 

void Solve(int start) {
    for(int i=start;i<=N;i++) {
        
        dp[i+1][2] = min(dp[i][0] + 1, dp[i][1] + 1); //1개의 소대만 추가하면됨
        
        if(enemy[i][0] + enemy[i][1] <= W) {
            dp[i+1][2] = min(dp[i+1][2], dp[i][2] + 1); //i-1까지 채우고, |로 1소대 채우기
        }
        
        if(i > 0 && enemy[i-1][0] + enemy[i][0] <= W && enemy[i-1][1] + enemy[i][1] <= W) {
            dp[i+1][2] = min(dp[i+1][2], dp[i-1][2] + 2); // i-2까지 채우고 =로 2소대 채우기 
        }
        
        if(i==N) continue;
        
        dp[i+1][0] = dp[i+1][2] + 1;
        dp[i+1][1] = dp[i+1][2] + 1;
        
        if(enemy[i][0] + enemy[i+1][0] <= W) { //1행만 채워져 있는 경우
            dp[i+1][0] = min(dp[i+1][0],dp[i][1]+1); //0행의 i-1에서 -로 1소대 채우기
        }
        if(enemy[i][1] + enemy[i+1][1] <= W) { //0행만 채워져 있는 경우
            dp[i+1][1] = min(dp[i+1][1],dp[i][0]+1); //1행의 i-1행에서 -로 1소대 채우기 
        }
    }
}

void input() {

    int ans = INF;
    cin >> N >> W;
    memset(dp, 0, sizeof(dp)); //초기화
    memset(enemy, 0, sizeof(enemy)); //초기화
    for(int i=1;i<=N;i++) cin >> enemy[i][0];
    for(int i=1;i<=N;i++) cin >> enemy[i][1];
    
    dp[1][2] = 0;   dp[1][0] = 1;  dp[1][1] = 1; //초깃값 설정
    
    Solve(1); //단순 1~N까지 선형 모양만 탐색한 경우
    ans = dp[N+1][2];
    
    if(N>2) { //환형 모양을 선형으로 바꾸었으니 연결시켜줘야함
        if (enemy[1][1] + enemy[N][1] <= W) { //0행이 걸침
            dp[2][2] = 1;
            dp[2][1] = 2;
            dp[2][0] = enemy[1][0] + enemy[2][0] <= W ? 1 : 2;
            Solve(2);
            ans = min(ans, dp[N][0] + 1);
        }
        if (enemy[1][0] + enemy[N][0] <= W) { //1행이 걸침
            dp[2][2] = 1;
            dp[2][0] = 2;
            dp[2][1] = enemy[1][1] + enemy[2][1] <= W ? 1 : 2;
            Solve(2);
            ans = min(ans, dp[N][1] + 1);
        }
        if (enemy[1][0] + enemy[N][0] <= W && enemy[1][1] + enemy[N][1] <= W) { //0행, 1행을 각각 두 열씩 합침
            dp[2][2] = 0;
            dp[2][0] = 1;
            dp[2][1] = 1;
            Solve(2);
            ans = min(ans, dp[N][2] + 2);
        }
    }
    
    cout << ans << "\n";
}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> T;
    while(T--) {
        input();
    }
/*
1
3 5
3 2 2
1 4 2
ans = 3, my ans = 4;
*/
    
    return 0;
}
