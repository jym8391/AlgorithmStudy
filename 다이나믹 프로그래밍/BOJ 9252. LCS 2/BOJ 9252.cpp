#include <bits/stdc++.h>
using namespace std;

int LCS[1001][1001];
vector <char> S;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string A = " ";
	string B = " ";
	string tmp;
	int res=-1;

	cin>>tmp;
	A+=tmp;
	cin>>tmp;
	B+=tmp;
	int A_len = A.length();
	int B_len = B.length();

	for(int i=1;i<A_len;i++) {
		for(int j=1;j<B_len;j++) {
			if(i==0||j==0) LCS[i][j] = 0;
			else if(A[i]!=B[j]) {	
				LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
			}
			else {
				LCS[i][j] = LCS[i-1][j-1]+1;
			}
			res = max(res,LCS[i][j]);
		}
	}
	cout<<res<<"\n";
	
    if(res) {
        int i = A_len - 1;
        int j = B_len - 1;
        while(LCS[i][j]!=0)  {
            if(LCS[i][j]==LCS[i-1][j]){
                i--;
            }
            else if(LCS[i][j] == LCS[i][j-1]) {
                j--;
            }
            else {
                S.push_back(A[i]);
                i--;
                j--;
            }
        }
        for(int l=S.size()-1;l>=0;l--) {
            cout <<S[l];
        }
        cout << "\n";
    }

	return 0;
}
