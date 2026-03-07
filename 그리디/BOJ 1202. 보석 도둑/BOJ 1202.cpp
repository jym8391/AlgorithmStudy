#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
#define P 1000000007ll
typedef long long ll;

using namespace std;

int N;//보석의 개수
pii J[300001]; //보석의 무게, 가치
int K; //가방의 개수
int C[300001];//담을 수 있는 무게 최대치
//보석 가격의 합의 최댓값, 가방에는 보석 하나만 담을 수 있음
//가장 적게 담을 수 있는 가방부터 시작(정렬), 이 가방에 넣을 수 있는 가장 큰 가치의 보석을 넣으면 되지 않을까?

void input() {
    cin >> N >> K;
    for(int i = 0; i<N;i++) {
        int m, v;
        cin >> m >> v;
        J[i] = {m, v};
    }
    for(int i = 0; i<K;i++) {
        int c;
        cin >> c;
        C[i] = c;
    }
    sort(J,J+N); //보석 무게 오름차순 정렬
    sort(C,C+K); //가방 무게 오름차순 정렬
}

void f() {
    ll res = 0;
    priority_queue<int, vector<int>, less<int>> pq; //가치 기준 내림차순
    int j = 0; // 넣었던 걸 다시 넣기를 방지
    for(int i = 0; i<K;i++) {
        while(j < N && C[i] >= J[j].first) { 
            pq.push(J[j].second); 
            j++;
        }
        if(!pq.empty()) {
            res += pq.top(); //무게가 작은데 가치가 제일 높지 않은 것들은 pq에 남아서 다음에 이용됨.
            pq.pop();
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    f();
    
    return 0;
}
