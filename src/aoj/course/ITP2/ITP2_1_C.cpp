#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l;
    auto it = l.end();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int cmd;
        cin >> cmd;

        if (cmd == 0) {
            int x;
            cin >> x;
            it = l.insert(it, x);
        }
        if (cmd == 1) {
            int d;
            cin >> d;

            // 以下のようにdが正か負かによって分岐せずにnextの第2引数に負数が入っても正しく動く
            // if(d>0)
            //     it = next(it, d);
            // else
            //     it = prev(it,-d);
            it = next(it, d);
            // advance関数を使っても同じ結果が得られる
            // advance(it,d);
        }
        if (cmd == 2) {
            it = l.erase(it);
        }
    }

    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}
