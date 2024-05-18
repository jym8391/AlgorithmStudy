#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
#define P 1000000007ll
typedef long long ll;

using namespace std;

int N;
ll arr[100001];
ll MinV = 9223372036854775807ll; //특성값 최소값
int f,s; //혼합 특성값이 0에 근접한 용액들의 특성값
int start, End;

void input() {
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr,arr+N);
    start = 0;
    End = N-1;
}

void func() {
    while(start<End) {
        if(abs(arr[start]+arr[End]) < abs(MinV)) {
            MinV = abs(arr[start]+arr[End]);
            f = arr[start];
            s = arr[End];
        }
        if(arr[start]+arr[End] > 0) {
            End--;
        }
        else{
            start++;
        }
        
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    func();
    if(f<s) cout << f << " " << s << "\n";
    else cout << s << " " << f << "\n";
    return 0;
}
