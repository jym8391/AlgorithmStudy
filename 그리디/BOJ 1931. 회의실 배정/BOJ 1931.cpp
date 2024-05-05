#include <bits/stdc++.h>
using namespace std;

struct meet{
	int start;
	int end;
};

bool cmp (meet A, meet B){
	if(A.end==B.end) return A.start<B.start;
	return A.end<B.end;
}


int N;
meet arr[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;

	meet present;

	for(int i=0;i<N;i++) {
		cin>>arr[i].start>>arr[i].end;
	}
	
	sort(arr,arr+N,cmp);

	int cnt = 1;

	present.start = arr[0].start;
	present.end = arr[0].end;

	for(int i=1;i<N;i++) {
		if(arr[i].start<present.end) continue;
		else {
			present.start = arr[i].start;
			present.end = arr[i].end;
			cnt++;
		}
	}
	
	cout<<cnt<<"\n";

	return 0;
}
