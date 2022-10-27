#include <bits/stdc++.h>
using namespace std;

struct card {
    char suit;
    int number;
};

void print(vector<card> &c, int n) {
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        cout << c[i].suit << c[i].number;
    }
    cout << endl;
}

void bubbleSort(vector<card> &c, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (c[j].number < c[j - 1].number) {
                swap(c[j], c[j - 1]);
            }
        }
    }
}

void selectionSort(vector<card> &c, int n) {
    for (int i = 0; i < n; ++i) {
        int minj = i;
        for (int j = i; j < n; ++j) {
            if (c[j].number < c[minj].number) {
                minj = j;
            }
        }

        if (minj != i) {
            swap(c[i], c[minj]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<card> c(n), c2(n);
    for (int i = 0; i < n; ++i) cin >> c[i].suit >> c[i].number;
    c2 = c;

    bubbleSort(c, n);
    selectionSort(c2, n);

    print(c, n);
    cout << "Stable" << endl;
    print(c2, n);

    bool isStable = true;
    for (int i = 0; i < n; ++i) {
        if (c[i].suit != c2[i].suit) isStable = false;
    }
    cout << (isStable ? "Stable" : "Not stable") << endl;

    return 0;
}
