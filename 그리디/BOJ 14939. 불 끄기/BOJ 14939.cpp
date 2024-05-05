#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

/*전구를 전부 끔에 있어서 선택 순서가 결과에 영향을 주진 않음.
위에서부터 전구를 끄도록 순서를 강제할 수 있고, i번째행에서 i+1번째 행으로 넘어가면
i번째 스위치는 더이상 누를 수 없기 때문에 i+1번째행에서 i번째를 꺼야한다.
그러므로 전구를 선택함에 있어서 i+1 행의 수는 i번째 행에 의해 결정됨.
하지만 1번째 행은 이전 행이 없기 때문에 브루트포스를 이용해서 2^10 = 1024개의 경우의 수만 찾아주어
계산을 진행한다면 시간내에 쉽게 해결할 수 있을 것 같다.
*/

bool bulb[10][10];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int ans = INF;


//초기 입력
void input() {
    for(int i=0;i<10;i++) {
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++) {
            if(s[j]=='#') {
                bulb[i][j] = 0;
            }
            else if(s[j]=='O') {
                bulb[i][j] = 1;
            }
        }
    }
}

//브루트포스를 이용하기 위한 임시 배열을 만드는 함수
void arrSet(int arr[10][10]) { 
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            arr[i][j] = bulb[i][j];
        }
    }
}

//전구가 남아있는지 확인 남아있으면 true
bool islight(int arr[10][10]) { 
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            if(arr[i][j]) return true;
        }
    }
    return false;
}

//디버깅용 출력문
void printbulb(int arr[10][10]) { 
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
    cout <<"-------------\n\n";
}

//전구 클릭
void press(int arr[10][10],int x,int y) { 

    for(int l=0;l<4;l++) {
        int nx = x + dx[l];
        int ny = y + dy[l];
        if(nx<0||ny<0||nx>9||ny>9) continue; //범위를 벗어난경우
        arr[nx][ny] = !arr[nx][ny]; //상하좌우 반전
    }

    arr[x][y] = !arr[x][y]; //클릭한 곳도 반전
}

void bruteforce() {
    
    int tmp[10][10] = {};
    int cnt;
    
    for(int step=0;step<(1<<10);step++) { //첫번째 행을 결정하는 부분
        arrSet(tmp); //임시 배열 만들기
        cnt = 0;
        for(int bit=0;bit<10;bit++) { //ex) step이 1111011111 이렇게 들어올때 bit번째를 클릭할 수 있는지
            if(step&(1<<bit)) {
                cnt++; //클릭
                press(tmp,0,bit);
            }
        }
        
        //첫줄인 0번째 행은 이미 정하고 왔음으로 1번째행부터 탐색 시작 
        for(int i=1;i<10;i++) {
            for(int j=0;j<10;j++) {
                if(tmp[i-1][j]) { //i-1번째 전구가 켜져있다면
                    cnt++; //클릭
                    press(tmp,i,j);
                }
            }
        }
        
        if(!islight(tmp)) {
            ans = min(ans,cnt);
        }
        //printbulb(tmp);
    }
    if(ans==INF) cout << -1 << "\n";
    else cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(true); cin.tie(0); cout.tie(0);
    
    input();
    
    bruteforce();
    
    return 0;
}
