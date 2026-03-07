#include <bits/stdc++.h>
#define INF 1e9+7
#define EPSILON 1e-10
#define pii pair<int,int>
typedef long long ll;

using namespace std;

const double PI = 2.0 * acos(0.0);

struct vector2 {
    double x,y;
    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {} //실수 방지용 : 묵시적 형변환을 막음
  
    bool operator == (const vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    };

    bool operator < (const vector2& rhs) const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
    
    bool operator > (const vector2& rhs) const {
        return x != rhs.x ? x > rhs.x : y > rhs.y;
    }

    vector2 operator + (const vector2& rhs) const {
        return vector2(x + rhs.x, y + rhs.y);
    }
    
    vector2 operator - (const vector2& rhs) const {
        return vector2(x - rhs.x, y - rhs.y);
    }
    
    vector2 operator * (double rhs) const { //실수 곱셈
        return vector2(x * rhs, y * rhs);
    }
    
    double norm() const {return hypot(x,y);}

    vector2  normalize() const { 
        return vector2(x/norm(), y/norm());
    }
    
    //x축과의 반시계 각도
    double polar() const {return fmod(atan2(y,x) + 2*PI, 2*PI);}
    
    //내적
    double dot(const vector2& rhs) const{ 
        return x * rhs.x + y * rhs.y;
    }
    
    //외적
    double cross(const vector2& rhs) const{ 
        return x * rhs.y - rhs.x * y ;
    }  
    
    vector2 project(const vector2& rhs) const {
        vector2 r = rhs.normalize();
        return r * r.dot(*this);
    }
};

//두 방향 벡터에 대한 ccw
double ccw(vector2 a,vector2 b) { 
    return a.cross(b);
}
//점 p를 기준으로 벡터 b가 벡터a의 반시계방향이면 양수, 시계방향이면 음수, 평행이면 0 반환
//세 개의 점 벡터에 대한 ccw
double ccw(vector2 p, vector2 a, vector2 b) {
    return ccw(a-p,b-p);    
}

//두 선분이 겹칠때 한 점에서 겹치는지 
bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
    if(b<a) swap(a,b);
    if(d<c) swap(c,d);
    if(b==c) {
        x = b;
        return true;
    } 
    else if(a==d) {
        x = a;
        return true;
    }
    
    return false;
}

//(a,b) 직선과 (c,d) 직선의 교점을 x에 반환한다.
//평행이면 false, 아니면 true를 반환한다. 
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x) {
    double det = (b-a).cross(d-c);
    if(fabs(det) < EPSILON ) {
        if(parallelSegments(a,b,c,d,x)) return true; //평행이지만 한점에서 겹치는 경우
        else return false; //겹치는 경우임
    }
    x = a + (b-a) * ((c-a).cross(d-c)/det);
    return true;
}

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
    if(b<a) swap(a,b);
    if(d<c) swap(c,d);
    double ab = ccw(a,b,c) * ccw(a,b,d); 
    double cd = ccw(c,d,a) * ccw(c,d,b);
    //두 선분이 한 직선 위에 있거나 끝점이 겹치는 경우
    if(ab==0 && cd == 0) {
        return !(b<c || d<a);
    }
    return ab <=0 && cd <=0;
}

struct Line{
    vector2 a,b; //선분의 두 점
};
Line line1, line2;

void input() {
    cin >> line1.a.x >> line1.a.y >> line1.b.x >> line1.b.y;
    cin >> line2.a.x >> line2.a.y >> line2.b.x >> line2.b.y;
}

void Solve() {
    if(segmentIntersects(line1.a, line1.b, line2.a, line2.b)) { //교점이 존재한다면
        cout << 1 << "\n";
        vector2 ans;
        bool c = lineIntersection(line1.a, line1.b, line2.a, line2.b, ans);
        cout << fixed;
        cout.precision(10);
        if(c) cout << ans.x << " " << ans.y << "\n";
    }
    else cout << 0 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    input();
    
    Solve();    
    
    
    return 0;
}
