#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;


int G, P;
int parent[100005];
int cnt;
bool c = true;
//1~g까지 선택할 수 있으므로 선택할 수 있는 숫자 중 최댓값을 선택하면 됨
void init() {
    for(int i=0;i<=G;i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void union_find(int x,int y) {
    x = find(x);
    y = find(y);
    if(x!=y) parent[x] = y;
}

void input() {
    cin >> G >> P;
    init();
    for(int i=1;i<=P;i++) {
        int g;
        cin >> g;
        g = find(g); //g보다 작거나 같은 번호 중 사용 가능한 최댓값
        if(g==0) {
            c = false;
            continue; //더 이상 착륙 불가능하다면 
        }
        if(c) {
            union_find(g,g-1); //g다음으로 사용가능한 최댓값, BOJ 16566와 비슷한 문제
            cnt++;
        }
    }
    
    cout << cnt << "\n";
}   



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    
    return 0;
}
