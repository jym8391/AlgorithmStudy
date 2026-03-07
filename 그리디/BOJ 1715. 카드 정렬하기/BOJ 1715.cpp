#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N;
priority_queue<int,vector<int>,greater<int>> pq;
int Sum;

void input() {
    cin >> N;
    for(int i=0;i<N;i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
}

void Solve() {
    int f,s;
    while(!pq.empty()) {
        f = pq.top(); pq.pop();
        if(pq.empty()) break;
        s = pq.top(); pq.pop();
        Sum += f+s;
        pq.push(f+s);
    }
    cout << Sum << "\n";
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    Solve();
    return 0;
}
