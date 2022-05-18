#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)


int main() {
    int r,c,sy,sx,gy,gx;
    vector<vector<char>> map;
    vector<vector<int>> step;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    --sy; --sx; --gy; --gx;
    map.resize(r,vector<char>(c));
    step.assign(r,vector<int>(c, -1));

    rep(i,r) rep(j,c) cin >> map[i][j];

    queue<pair<int,int>> q;

    q.push(make_pair(sy,sx));
    step[sy][sx] = 0;
    while(q.empty() == false){
        pair<int,int> cur = q.front();
        q.pop();
        int cy = cur.first;
        int cx = cur.second;
        int cs = step[cy][cx] + 1;

        if(cy == gy && cx == gx) break;

        int dy[4] = {1,-1,0,0};
        int dx[4] = {0,0,1,-1};
        rep(i,4){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(map[ny][nx] == '.' && step[ny][nx] == -1){
                step[ny][nx] = cs;
                q.push(make_pair(ny, nx));
            }
        }

    }

    cout << step[gy][gx] << endl;
}
