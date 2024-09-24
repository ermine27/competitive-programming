/*
A68の応用問題

最小カット問題

最小カットは、最大フローを求めることで計算ができる。
求める利益の最大値は、全体の正の利益の合計から最小カットを引いた値。

FordFulkerson法は負数は扱えないので、利益がマイナスの場合は特急駅に指定しない時にプラスになると置き換える。
S -- 駅1～駅n -- T
と、n+2個の頂点からなるグラフを作り、各駅の利益に基づいてSから駅i、または駅iからTへの辺を追加する

詳しくは公式pdfの解説を参照
*/

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// clang-format on

template <typename T>
struct Edge {
    // rev:逆向きの辺の番号
    int rev, from, to;
    T cap, original_cap;
    Edge(int r, int f, int t, T c) : rev(r), from(f), to(t), cap(c), original_cap(c) {}
};

template <typename T>
struct Graph {
    vector<vector<Edge<T>>> G;
    Graph(int n = 0) : G(n) {}
    vector<Edge<T>>& operator[](int i) { return G[i]; }
    // warning: type qualifiers ignored on function return type
    // [-Wignored-qualifiers]　が出るので書き換える const size_t size() const { return G.size(); }
    const T size() const { return G.size(); }

    // 逆向きの辺を返す
    // 自己ループはないと仮定（あれば G[e.to][e.rev + 1] とする必要がある）
    Edge<T>& redge(Edge<T> e) { return G[e.to][e.rev]; }
    // 有向辺を加える
    void add_edge(int from, int to, T cap) {
        G[from].push_back(Edge<T>((int)G[to].size(), from, to, cap));
        G[to].push_back(Edge<T>((int)G[from].size() - 1, to, from, 0));
    }
};

/* FordFulkerson: Ford-Fulkersonのアルゴリズムで最大流を求める構造体
    max_flow(G,s,t)：sからtへのグラフGの最大流を求める
    副作用：G は最大流の残余ネットワークになる
    計算量: O(|f*||E|) (f*:最大流) (この最悪ケースになることはほぼ無い)
*/
template <typename T>
struct FordFulkerson {
    const T INF = 1e9;
    vector<int> used;

    FordFulkerson() {};
    // 増加可能経路を見つけて増加分のフローを返す
    T dfs(Graph<T>& G, int v, int t, T f) {
        if (v == t)
            return f;
        used[v] = true;
        for (auto& e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
                T d = dfs(G, e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G.redge(e).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    T max_flow(Graph<T>& G, int s, int t) {
        T flow = 0;
        while (true) {
            used.assign(G.size(), 0);
            T f = dfs(G, s, t, INF);
            if (f == 0) {
                return flow;
            } else {
                flow += f;
            }
        }
        return 0;
    }
};

const int INF = 1e9;

int main() {
    int n, m, p, a, b, offset = 0;
    cin >> n >> m;
    Graph<int> g(n + 2);
    rep(i, n) {
        cin >> p;
        if (p >= 0) {
            g.add_edge(n, i, p);
            offset += p;
        } else {
            g.add_edge(i, n + 1, -p);
        }
    }
    rep(i, m) {
        cin >> a >> b;
        g.add_edge(a - 1, b - 1, INF);
    }
    FordFulkerson<int> ff;
    cout << offset - ff.max_flow(g, n, n + 1) << endl;
    return 0;
}
