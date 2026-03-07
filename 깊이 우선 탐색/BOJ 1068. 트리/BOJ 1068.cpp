#include <bits/stdc++.h>
using namespace std;

int N;
int startNode; //시작 노드 번호
int delNode; //지울 노드 번호
vector<int> node[51];

void input() {
    cin >> N;
    for(int i=0;i<N;i++) {
        int p;
        cin >> p;
        if(p==-1) startNode = i;
        else node[p].push_back(i); //p의 자식은 i이다.
    }
    cin >> delNode; //지울 노드 번호
}

int f(int nodeNum) {
    if(nodeNum==delNode) return 0; //루트 노드를 지우는 경우
    int res = 0;
    int childCnt = 0;
    for(auto it = node[nodeNum].begin();it!=node[nodeNum].end();it++) { //nodeNum의 자식 노드 탐색
        if(*it==delNode) continue; //지워야할 노드라면 무시
        res += f(*it);
        childCnt++; //자식 노드 증가
    }
    if(childCnt == 0) return 1; //자식이 없다면 리프 노드임, 1 반환
    return res; //자식이 있었다면 자신 아래의 리프노드들의 합을 반환
}


int main() { 
    input();
    cout << f(startNode);
    return 0;
}