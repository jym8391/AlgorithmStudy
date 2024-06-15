#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N;

int A[4005],B[4005],C[4005],D[4005];
vector<int> x,y;
ll cnt = 0;


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    //a+b = -(c+d)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            x.push_back(A[i] + B[j]);
            y.push_back(C[i] + D[j]);
        }
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    
    
    for(int i=0;i<N*N;i++) {
        cnt += upper_bound(y.begin(),y.end(),-x[i]) - lower_bound(y.begin(),y.end(),-x[i]) ;
    }
    
    cout << cnt << "\n";
   

    return 0;
}
