#include <bits/stdc++.h>
#define INF 2e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N;
vector<ll> v; //전봇대의 x좌표를 입력받음

void input() {
    cin >> N;
    for(int i=0;i<N;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

void ternarySearch() { //삼분 탐색
    //전봇대 사이의 거리를 x, f(x) : 전봇대들의 총 이동거리 , 아래로 볼록한 그래프가 형성됨 -> 삼분탐색 활용가능
    ll l = 0, r = v[N-1];

    while(r-l>=3) { //정수 구간이기 때문에 구간 거리가 3개 이상으로 쪼개질때만 탐색함
        ll aab = (2*l + r)/3; //왼쪽 구간
        ll abb = (l + 2*r)/3; //오른쪽 구간
        
        ll sum1 = 0, sum2 = 0; //왼쪽, 오른쪽 구간
        for(int i=0;i<N;i++) {
            sum1 += abs(aab*i-v[i]); 
            sum2 += abs(abb*i-v[i]);
        }
        
        if(sum1<sum2) r = abb; //오른쪽 1/3 날림
        else if(sum1>sum2) l = aab; //왼쪽 1/3 날림
    }
    
    //남은 범위에서 하나씩 탐색하며 최솟값 출력
    ll ans = LLONG_MAX; //거리의 합이 정수 범위를 넘을 수 있기 때문에 long long 가져옴
    for(ll i=l;i<=r;i++) {
        ll S = 0;
        for(int j=0;j<N;j++) {
            S += abs(i*j-v[j]);
        }
        ans = min(ans,S);
    }
    
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    
    ternarySearch(); 
    
    return 0;
}
