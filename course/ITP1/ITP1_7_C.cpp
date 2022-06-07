#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, c;
    cin >> r >> c;

    int m[r+1][c+1];
    int colsum[c+1] = {};
    int sum = 0;

    for(int i = 0; i < r; ++i){
        int d, rowsum = 0;
        for(int j = 0; j < c; ++j){
            cin >> d;
            m[i][j] = d;
            rowsum += d;
            colsum[j] += d;
        }
        m[i][c] = rowsum;
        sum += rowsum;
    }

    for(int i = 0; i < r; ++i){
        for(int j = 0; j <= c; ++j){
            cout << m[i][j];
            if(j <= c - 1) cout << ' ';
        }
        cout << endl;
    }
    for(int i = 0; i < c; ++i){
        cout << colsum[i] << ' ';
    }
    cout << sum;
    cout << endl;
}

