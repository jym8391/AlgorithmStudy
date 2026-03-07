#include <bits/stdc++.h>
using namespace std;

string P; //원문 패턴
int N; //문자열 개수
string S; //문자열 ,최대 100자, 알파벳 소문자와 .으로 이루어짐

int cache[101][101];
//-1은 아직 계산안됨, 0은 입력이 대응되지 않음, 1은 대응됨

void cache_clear() {
    for(int i=0;i<=100;i++) {
        for(int j=0;j<=100;j++) {
            cache[i][j]=-1;
        }
    }
}

bool boolMatch(int w,int s) {
    int& ret = cache[w][s];
    if(ret!=-1) return ret;//메모제이션
    while(s<S.length() && w<P.length() && (P[w]==S[s])) {
        w++;
        s++;
    }

    if(w==P.length()) return ret = (s == S.length());

    if(P[w]=='*') {
        for(int skip=0;skip+s<=S.length();skip++) {
            if(boolMatch(w+1,s+skip)) 
                return ret =1;
        }
    }
    return ret = 0;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>P;

    cin>>N;

    for(int i=0;i<N;i++) {
        cache_clear();
        cin>>S;
        if(boolMatch(0,0)) cout<<S<<"\n";
    }

    return 0;
}