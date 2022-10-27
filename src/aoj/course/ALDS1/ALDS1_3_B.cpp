#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,quantum,ti;
    string pi;
    cin >> n >> quantum;

    queue<pair<string,int>> q;

    for(int i = 0; i < n; ++i){
        cin >> pi >> ti;
        q.push(make_pair(pi,ti));
    }

    pair<string,int> w;
    int time = 0;
    while(q.empty() == false){

        w = q.front();
        q.pop();
        tie(pi,ti) = w;

        if(ti > quantum){
            time += quantum;
            ti -= quantum;
            q.push(make_pair(pi,ti));
        } else {
            time += ti;
            cout << pi << ' ' << time << endl;
        }
    }
}
