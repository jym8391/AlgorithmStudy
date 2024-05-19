#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
#define P 1000000007ll
typedef long long ll;

using namespace std;

int N;
ll arr[2001];
int cnt; 
int start, End;

void input() {
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr,arr+N);

}

void func() {
    for(int i=0;i<N;i++) {
        start = 0;
        End = N-1;
        while(start<End) {
            int subsum = arr[start]+arr[End];
            if(i==start) {
                start++;
                continue;
            }
            else if(i==End) {
                End--;
                continue;
            }
            if(subsum > arr[i]) { //큰 경우
                End--;
            }
            else if(subsum< arr[i]){ //작은 경우
                start++;
            }
            else { //일단 생각나는 문제점 ? : 자기 자신과 조우했을때, 0 0 0 0 과 같을때 고려
                cnt++;
                break;
            }    
            
        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    func();
    cout << cnt << "\n";
    return 0;
}

// 3
// 0 0 1
//ans : 0
