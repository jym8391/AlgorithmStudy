#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;


int N, R, C;
int parent[2250002]; //1500 * 1500 +2
int Lake[1501][1501];
bool visited[1501][1501];
vector<pii> swans; //백조 위치


int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int find_root(int x) {
    if (parent[x] == x ) return x;
    return parent[x] = find_root(parent[x]); //경로 압축

} 
 
void union_root(int x,int y) { 
    x = find_root(x);
    y = find_root(y);
    if(x<y) parent[y] = x; //index가 더 작은 쪽으로 합치기
    else if(x>y) parent[x] = y;
}

void print_Lake() {
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cout << Lake[i][j];
        }
        cout << "\n";
    }
}

void boardset() {
    string s;
    for(int i=0;i<R;i++) {
        cin >> s;
        for(int j=0;j<C;j++) {
            if(s[j]=='.') { //물
                Lake[i][j] = 0;
            }
            else if(s[j]=='X') { //빙판
                Lake[i][j] = 1;
            }
            else { //백조
                Lake[i][j] = 2;
                
            }
        }
    }
}

int idx(int x,int y) {
    return x*C+y;
}

void input() {
    cin >> R >> C;
    queue<pii> q; // 물의 위치
    
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) { //부모 초기화
            parent[idx(i,j)] = idx(i,j);
        }
    }
    
    boardset();
    
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(Lake[i][j]!=1) { //빙판이 아닌 경우, 물과 백조의 위치
                q.push({i,j});
                visited[i][j] = true;
                if(Lake[i][j]==2) {
                    swans.push_back({i,j}); //백조의 위치, 따로 저장해서 쓰고 물로 바꿔버리자
                    Lake[i][j] = 0;
                }
            }
        }
    }
    
    int days = 0;
    while(!q.empty()) {
        queue<pii> temp; //임시 큐
        while(!q.empty()) {
            pii cur = q.front();
            q.pop();
            int cur_x = cur.first;
            int cur_y = cur.second;
            //cout << idx(cur_x,cur_y) << "\n";
            //인접한 위치의 물인 공간과 union
            for(int i=0;i<4;i++) {
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                if(nx<0||ny<0||nx>=R||ny>=C) continue; //범위를 벗어나면 continue
                if(visited[nx][ny]) {
                    union_root(idx(cur_x,cur_y),idx(nx,ny));
                }
            }
            temp.push(cur);
        }
        
        //백조의 영역이 union되었는지->백조가 만날 수 있는지
        if (find_root(idx(swans[0].first,swans[0].second)) == find_root(idx(swans[1].first,swans[1].second))){
            cout << days << "\n"; 
            break;
        }
        
        days++;
        
        while(!temp.empty()) {
            pii cur = temp.front();
            temp.pop();
            int cur_x = cur.first;
            int cur_y = cur.second;
            //녹이기
            for(int i=0;i<4;i++) {
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                if(nx<0||ny<0||nx>=R||ny>=C) continue; //범위를 벗어나면 continue
                if(!visited[nx][ny]) { //방문한적 없는 곳, 빙판인 곳
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

}



int main() {
    ios::sync_with_stdio(true); cin.tie(0); cout.tie(0);
    
    input();
    
    return 0;
}
