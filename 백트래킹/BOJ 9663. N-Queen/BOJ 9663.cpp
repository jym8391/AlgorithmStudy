#include <bits/stdc++.h>
using namespace std;
	
int N;
int board[20]; //각 행별 퀸의 열 위치
int cnt;
bool promising(int i) { //공격 범위에 들어오는지 확인
	int k=1;
	while(k<i) {
		if(board[i]==board[k]||abs(board[i]-board[k])==abs(i-k)) {
			return 0;
		}
		k++;
	}
	return 1;
}

void queens(int i) { 
	if(promising(i)) {
		if(i==N) {
			cnt++;
			return ;
		}
		else {
			for(int j=1;j<=N;j++) {
				board[i+1]=j;
				queens(i+1);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin>>N;
	
	queens(0);

	cout<<cnt<<"\n";

	return 0;
}
