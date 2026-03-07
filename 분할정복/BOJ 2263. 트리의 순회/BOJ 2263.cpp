#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N;
int inorder[100001];
int postorder[100001];
int idx[100001];


void input() {
    cin >> N;
    //후위 순회의 끝값은 루트노드이기 때문에, 해당 노드가 중위 순회의 어느 인덱스에 위치하는지 중위순회 값들을 저장한다.
    for(int i=0;i<N;i++) {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for(int i=0;i<N;i++) cin >> postorder[i];
}

void printPreOrder(int inStart, int inEnd, int postStart, int postEnd) {
    if(inStart > inEnd || postStart > postEnd) return ;// 더이상 분할할 수 없는 경우
    int rootidx = idx[postorder[postEnd]]; //루트노드의 위치
    int L = rootidx - inStart; //왼쪽 서브트리의 크기
    int R = inEnd - rootidx; //오른쪽 서브트리의 크기
    
    cout << inorder[rootidx] << " "; //루트 출력
    printPreOrder(inStart,rootidx-1,postStart,postStart+L-1); //왼쪽 서브트리
    printPreOrder(rootidx+1,inEnd,postEnd-R,postEnd-1); //오른쪽 서브트리
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();

    printPreOrder(0,N-1,0,N-1);

    
    return 0;
}
