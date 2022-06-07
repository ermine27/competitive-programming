#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> cards(4, vector<int>(13,0));
    const char suitkind[5] = {'S', 'H', 'C', 'D'};
    for(int i = 0; i < n; ++i){
        char suit;
        int number, suitnum;
        cin >> suit >> number;
        if(suit == 'S') suitnum = 0;
        if(suit == 'H') suitnum = 1;
        if(suit == 'C') suitnum = 2;
        if(suit == 'D') suitnum = 3;
        cards[suitnum][number-1] = 1;
    }

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 13; ++j){
            if(cards[i][j] == 0){
                cout << suitkind[i] << ' ' << j+1 << endl;
            }
        }
    }
}
