#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
#define P 1000000007ll
typedef long long ll;

using namespace std;

ll T;
int N,M;
ll A[1001];
ll B[1001];
vector<ll> DPA;
vector<ll> DPB;

void input() {
    
    cin >> T;
    
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    
    cin >> M;
    for(int i=0;i<M;i++) cin >> B[i];
    
    for(int i=0;i<N;i++) {
        ll sum = 0;
        for(int j=i;j<N;j++) {
            sum += A[j];
            DPA.push_back(sum); //부 배열의 합
        }
    }
    sort(DPA.begin(),DPA.end());
    
    for(int i=0;i<M;i++) {
        ll sum = 0;
        for(int j=i;j<M;j++) {
            sum += B[j];
            DPB.push_back(sum); //부 배열의 합
        }
    }
    sort(DPB.begin(),DPB.end());
    
}

ll f() {
    ll cnt = 0;
    for(int i=0;i<DPA.size();i++) {
        int high = upper_bound(DPB.begin(), DPB.end(), T - DPA[i]) - DPB.begin(); //해당 값을 처음으로 초과하는 위치
        int low = lower_bound(DPB.begin(), DPB.end(), T - DPA[i]) - DPB.begin(); //해당 값이 처음 등장하는 위치
        cnt += high-low;
    }
    return cnt;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    cout << f() << "\n";
    
    return 0;
}

