#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
#define P 1000000007ll
typedef long long ll;

using namespace std;


int T;
int parent[20001];
int dist[20001];

int find_root(int x) { //일반적인 경로 압축을 하면 안될듯
    if (parent[x] == x) return x;
    int k = find_root(parent[x]); //센터(루트)가 아닌 부모를 하나씩 거쳐감
    dist[x] += dist[parent[x]];
    return parent[x] = k;
} 
 
void union_root(int x, int y) { //x가 y에 합병됨
    dist[x] = abs(x-y) % 1000; //거리 계산
    parent[x] = y;
}


void input() {
    cin >> T;
    while(T--) {
        int N; //기업의 수
        cin >> N;
        for(int i=1;i<=N;i++) { //초기화
            parent[i] = i;
        }
        memset(dist,0,sizeof(dist));
        while(true) {
            char O;
            cin >> O;
            if(O=='O') break;
            if(O=='E') { //I와 현재 I의 센터(루트)까지 거리 출력
                int I;
                cin >> I;
                find_root(I);
                cout << dist[I] << "\n";
            }
            else if(O=='I') { //센터 I를 기업 J에 연결
                int I, J;
                cin >> I >> J;
                union_root(I,J);
            }
        }

    }
    
}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    
    return 0;
}
