#include <bits/stdc++.h>
#define INF 1e9+7
#define pii pair<int,int>
#define P 1000000007ll
typedef long long ll;

using namespace std;


//정점
struct Point{
    ll x,y; 
};
//선분
struct Line{
    Point point1;
    Point point2;
};
Line line[3001];

int cnt[3001]; 


double dis(Point A,Point B) {
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

ll CCW(Point p,Point q,Point r) {
	long long res = (p.x*q.y+q.x*r.y+r.x*p.y)-(p.y*q.x+q.y*r.x+r.y*p.x);
	if(res>0) return 1;
	else if(res<0) return -1;
	else return 0;
}

bool Crosschk(Line A, Line B) {
        int a = CCW(A.point1,A.point2,B.point1);
        int b = CCW(A.point1,A.point2,B.point2);
        int c = CCW(B.point1,B.point2,A.point1);
        int d = CCW(B.point1,B.point2,A.point2);
        double ab = dis(A.point1,A.point2);
        double ac = dis(A.point1,B.point1);
        double ad = dis(A.point1,B.point2);
    	double bc = dis(A.point2,B.point1);
    	double bd = dis(A.point2,B.point2);
    	double cd = dis(B.point1,B.point2);
        if((a*b<=0&&c*d<=0)){
        		if(a*b<0&&c*d<0) {
        		    return true;
        		}
        		else if((ac+bc-ab<0.00000001)||(ad+bd-ab<0.00000001)||(ac+ad-cd<0.00000001)||(bc+bd-cd<0.00000001)) {
        		    return true;
        		}
        		else {
        		    return false;
        		}
        }
    	else {
    	    return false;
    	}
}


int N;
int parent[3001];

int find_root(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x]); //경로 압축
}
 
void union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if (x != y) parent[y] = x;
}

void input() {
    cin >> N;
    
    for(int i=1;i<=N;i++) { //초기화
        parent[i] = i;
    }
    
    for(int i=1;i<=N;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        line[i].point1 = {a,b};
        line[i].point2 = {c,d};
    }
    
    for(int i=1;i<=N;i++) { //N,1,2,3,4...N까지 비교
        for(int j=1;j<i;j++) {
            bool flag = Crosschk(line[i],line[j]); //교차 여부
            if(flag) { //교차한다면 하나의 집합으로 넣기
                union_root(i,j);
            }
        }
    }
    
    for(int i=1;i<=N;i++) {
        //cout << i << "번째 선분의 부모는 " << find_root(i) << "\n";
        cnt[find_root(i)]++;
    }
    int group_cnt = 0 ;
    int ans;
    for(int i=1;i<=N;i++) {
        if(cnt[i]) {
            group_cnt++;
            ans = max(ans, cnt[i]);
        }
    }
    cout << group_cnt << "\n";
    cout << ans << "\n";
    
}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    
    return 0;
}
