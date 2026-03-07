#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> declineNum; //감소하는 수들의 집합

void input() {
    cin >> N;
}

void solve(long long num, int lastDigit) {
    //num : 현재 만들어진 감소하는 수
    //lastDigit : 현재 만들어진 감소하는 수의 마지막 자릿수
    declineNum.push_back(num);

    //따로 종료조건을 넣지 않아도 최대로 감소하는 수는 9876543210이다. 그리고 경우의 수는 2^10-1 시행횟수 내로 끝난다.
    for(int i = 0; i < lastDigit; i++) {
        solve(num * 10 + i, i);
    }
}



int main() { 
    input();
    for(int i = 0; i <= 9; i++) {
        solve(i,i);
    }
    sort(declineNum.begin(), declineNum.end()); //오름차순 정렬
    if(N < declineNum.size()) {
        cout << declineNum[N];
    }
    else cout << -1;
    return 0;
}
