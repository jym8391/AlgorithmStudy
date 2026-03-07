#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N, X, Y;
vector<double> GA, GB, W;

struct S{
    double v,a,b; //가치, A의 개수, B의 개수
};

void input() {
    cin >> N >> X >> Y;
    GA.resize(N);
    GB.resize(N);
    W.resize(N);
    
    for(int i=0;i<N;i++) cin >> GA[i];
    for(int i=0;i<N;i++) cin >> GB[i];
    for(int i=0;i<N;i++) cin >> W[i];
}

S f(double m) { 
    double M = LLONG_MAX;
    //m개만큼 A를 만들고 난 뒤,
    for(int i=0; i<N; i++)
        M = min(M, (W[i] - m * GA[i]) / GB[i]); //현재 만들 수 있는 최대 B의 수 

    return {m * X + M * Y, m, M};
}

void ternarySearch() {
    double lo = 0, hi = LLONG_MAX;
    int cnt = 1e2;
    
    for(int i=0; i<N; i++) hi = min(hi, W[i] / GA[i]); //현재 만들 수 있는 최대 A의 수
    
    while(cnt--) {
        double m1 = (2*lo+hi)/3;
        double m2 = (lo+2*hi)/3;
        if(f(m1).v < f(m2).v) lo = m1;
        else hi = m2;
    }
    double m = (lo+hi)/2;
    cout<<fixed;
    cout.precision(2);
    cout << f(m).v << "\n";
    cout << f(m).a << " " <<f(m).b << "\n";
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    
    
    ternarySearch();

    
    return 0;
}
