#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N, M, K;

vector<int> card; //민수가 가지고 있는 카드
vector<int> parent(4000001);

int find_root(int x) {
    if(parent[x]==x) return x;
    return parent[x] = find_root(parent[x]);
}

void union_root(int x,int y) {
    if(y>=M) return ;
    x = find_root(x);
    y = find_root(y);
    if(x!=y) parent[x] = y;
}

void input() {
    
    cin >> N >> M >> K;
    int n;
    for(int i=0;i<M;i++) {
        cin >> n;
        card.push_back(n); //어떤 카드를 뽑았는지
    }
    sort(card.begin(),card.end()); //정렬
    
    for(int i=0;i<M;i++) parent[i] = i; //초기화
    
    for(int i=1;i<=K;i++) { //철수가 i번째로 꺼낼 카드의 수
        cin >> n;
        int idx = upper_bound(card.begin(),card.end(),n) - card.begin(); //n보다 큰 값이 처음으로 나오는 index
        idx = find_root(idx);
        cout<<card[idx]<<"\n";
        union_root(idx,idx+1);
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    
    return 0;
}
