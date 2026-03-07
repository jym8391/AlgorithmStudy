#include <bits/stdc++.h>
#define INF 2e9+7
#define pii pair<int,int>
typedef long long ll;

using namespace std;

int N;

struct M{ 
    double x, y, vx, vy;
};

vector<M> mouse;

void input() {
    cin >> N;
    //쥐 N마리의 위치와 속도 정보 입력
    for(int i=0;i<N;i++) {
        double x,y,vx,vy;
        cin >> x >> y >> vx >> vy;
        mouse.push_back({x,y,vx,vy});
    }
}

double MaxSide(double t) {
    //t초일때 모든 쥐들을 잡을 수 있는 정사각형의 최소 크기(실제론 걸치기 때문에 전부 못잡음)
    double xmin = INF;
    double ymin = INF;
    double xmax = -1*INF;
    double ymax = -1*INF;
    for(int i=0;i<mouse.size();i++) {
        xmin = min(xmin,mouse[i].x + mouse[i].vx * t);
        ymin = min(ymin,mouse[i].y + mouse[i].vy * t);
        xmax = max(xmax,mouse[i].x +  mouse[i].vx * t);
        ymax = max(ymax,mouse[i].y +  mouse[i].vy * t);
    }
    
    return max(xmax-xmin,ymax-ymin);
}

void ternarySearch() { //삼분 탐색

    //초기 쥐들의 위치의 범위의 최댓값이 -1000~1000이기 때문에, 속도가 0이 아닌 이상 정수이기 때문에
    //아무리 느려도 1의 속도를 가지고 2000범위를 통과하는 시간의 상한은 2000이다.
    
    double lo = 0, hi = 2000; 
    
    int cnt = 100;
    
    while(cnt--) {
        double m1 = (2*lo+hi)/3;
        double m2 = (lo+2*hi)/3;
        
        if(MaxSide(m1) > MaxSide(m2)) lo = m1;
        else hi = m2;
    }
    
    double m = (lo+hi)/2;
    double ans = MaxSide(m);
    
    cout << fixed;
    cout.precision(9);
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    
    ternarySearch(); 
    
    return 0;
}
