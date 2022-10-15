#include <bits/stdc++.h>
using namespace std;

#define reps(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(i,n) reps(i,0,n)

const int dx[] = {0,1,1,-1};
const int dy[] = {1,0,1,1};

int n;
vector<string> s;

bool check(int x, int y, int dx, int dy){
    int cnt = 0, k = 0;

    while(k < 6 && s[x][y] != 'X'){
        if(s[x][y] == '#') ++cnt;
        x += dx;
        y += dy;
        ++k;
    }
    return (cnt >= 4 && k == 6) ? true : false;
}


int main(){
    cin >> n;
    s.resize(n+2);
    string si = "";
    rep(i,n+2) si += 'X';
    s[0] = si;
    s[n+1] = si;
    rep(i,n){
        cin >> si;
        s[i+1] = 'X' + si + 'X';
    }

    reps(i,1,n+1){
        reps(j,1,n+1){
            rep(k,4){
                if(check(i, j, dx[k] ,dy[k])){
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }

    cout << "No";
    return 0;    
}
