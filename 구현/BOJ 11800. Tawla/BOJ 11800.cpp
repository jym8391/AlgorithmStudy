#include <bits/stdc++.h>
using namespace std;

string dice[7] = {"", "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};
string samedice[7] = {"", "Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"};


void Tawla(int a,int b) {
    if(b>a) swap(a,b);
    if(a==b) {
        cout << samedice[a];
        return ;
    }
    else if(a==6&&b==5) {
        cout << "Sheesh Beesh";
        return ;
    }
    else {
        cout << dice[a] << " " << dice[b];
    }


}

void input() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int a, b;
        cin >> a >> b;
        cout << "Case " << t << ": ";
        Tawla(a,b);
        cout << "\n";
    }
}


int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();

    return 0;
}
