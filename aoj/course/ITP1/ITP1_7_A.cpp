#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int m, f, r;

        cin >> m >> f >> r;
        if(m == -1 && f == -1 && r == -1) break;

        if(m == -1 || f == -1){
            cout << 'F' << endl;
            continue;
        }

        int score = m + f;
        char j;

        if(score >= 80) j = 'A';
        else if(score >= 65) j = 'B';
        else if(score >= 50) j = 'C';
        else if(score >= 30){
            if(r >= 50) j = 'C';
            else j = 'D';
        }
        else j = 'F';

        cout << j << endl;
    }
}

