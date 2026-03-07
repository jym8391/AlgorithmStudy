#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N;
int U, V;
vector<int> graph[1000005], tree[1000005];

int dp[1000005][2]; //i가 루트인 0은 i가 얼리어답터가 아닐 때, 최소 얼리어답터의 수, 1은 i가 얼리어답터일 때 최소 얼리어답터의 수
bool visited[1000005];

//양방향 그래프를 단방향성을 지닌 트리 형태로 변환해 줌.
void makeTree(int cur, int prev) {
    for(auto next : graph[cur]) {
        if(next!=prev) {
            tree[cur].push_back(next);
            makeTree(next,cur);
        }
    }
}

int Solve(int cur, int type) {
    int& ret = dp[cur][type];
    
    if(ret!=-1) return ret;
    
    if(tree[cur].empty()) { //리프 노드일 때
        return dp[cur][type] = type;
    }
    
    if(type == 0) {
        ret = 0;
        for(auto next : tree[cur]) {
            ret += Solve(next,1);
        }
    }
    else if(type == 1) {
        ret = 1;
        for(auto next : tree[cur]) {
            ret += min(Solve(next,0), Solve(next,1));
        }
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N ;
    
    memset(dp,-1,sizeof(dp));
    
    for(int i=0;i<N-1;i++) {
        cin >> U >> V;
        graph[U].push_back(V);
        graph[V].push_back(U); 
    }
    
    makeTree(1,0); //1번을 루트로 지니는 트리를 생성
    
    //1번 루트 노드를 얼리어답터로 했을 때, 하지않았을 때 중 더 작은 값을 출력
    cout << min(Solve(1,0), Solve(1,1) ) << "\n";

    return 0;
}
