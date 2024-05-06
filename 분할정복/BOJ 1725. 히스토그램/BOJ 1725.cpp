#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N;
ll H[100005]; //히스토그램의 높이를 저장하는 배열 

void input() {
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> H[i];
    }
}

//가장 큰 사각형을 반환
ll Solve(int left, int right) { 
    if(left == right) return H[left]; //너비가 1일때
    int mid = (left+right) / 2;
    ll res = max(Solve(left,mid), Solve(mid+1,right)); //좌측, 우측 탐색
    
     //좌측과 우측을 포함하는 너비가 2인 사각형 고려
    int lo = mid, hi = mid+1;
    ll height = min(H[lo], H[hi]);
    
    res = max(res,height*2);
    
    //높이가 높은쪽으로 확장
    while(left < lo || hi < right) {
        
        //오른쪽 > 왼쪽 or 왼쪽으로 더 갈 수 없을 때
        if(hi < right && (lo == left || H[lo-1] < H[hi+1])) { 
            hi++;
            height = min(height, H[hi]);
        }
        else { 
            lo--;
            height = min(height, H[lo]);
        }
        res = max(res, height * (hi-lo+1));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    
    cout << Solve(0,N-1) << "\n";
    
    return 0;
}
