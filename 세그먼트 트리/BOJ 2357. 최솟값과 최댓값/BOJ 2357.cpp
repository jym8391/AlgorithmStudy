#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N, M;

int arr[100005];
int maxTree[400005];
int minTree[400005];
//계산의 편의를 위해 노드는 1번부터 사용


int maxInit(int start, int end, int node) {
    if(start==end) return maxTree[node] = arr[start];
    int mid = (start+end)/2;
    return maxTree[node] = max(maxInit(start, mid, node*2), maxInit(mid+1, end, node*2+1));
}

int minInit(int start, int end, int node) {
    if(start==end) return minTree[node] = arr[start];
    int mid = (start+end)/2;
    return minTree[node] = min(minInit(start, mid, node*2), minInit(mid+1, end, node*2+1));
}

int maxFind(int start, int end, int node, int left, int right){
    if(end < left || start > right) return -1;
    if(left <= start && end <= right) return maxTree[node];

    int mid = (start + end) / 2;

    return max(maxFind(start, mid, node*2, left, right), maxFind(mid+1, end, node*2+1, left, right));
}

int minFind(int start, int end, int node, int left, int right){
    if(end < left || start > right) return INF;
    if(left <= start && end <= right) return minTree[node];

    int mid = (start + end) / 2;

    return min(minFind(start, mid, node*2, left, right), minFind(mid+1, end, node*2+1, left, right));
}

void input() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    maxInit(0,N-1,1);
    minInit(0,N-1,1);
    
    while(M--) {
        int a,b;
        cin >> a >> b;
        cout << minFind(0,N-1,1,a-1,b-1) << " " << maxFind(0,N-1,1,a-1,b-1) << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    return 0;
}
