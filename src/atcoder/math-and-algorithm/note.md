アルゴリズムと数学　演習問題集　ノート


# 問題ページ
https://atcoder.jp/contests/math-and-algorithm


# 026
**クーポンコレクター問題（食玩問題）**

$N$ 種類のクーポンを全て集めるのに必要な試行回数を求める。

期待値 $E$ は以下の計算で求まる。

$$
  E = E(p_1) + E(p_2) + \dots+ E(p_n) \\
  = \frac{1}{p_1} + \frac{1}{p_2} + \frac{1}{p_3} + \dots + \frac{1}{p_n} \\
  = \frac{n}{1} + \frac{n}{n-1} + \frac{n}{n-2} + \dots + \frac{n}{1} \\
  = n  (\frac{1}{1} + \frac{1}{2} + \frac{1}{3} + \dots + \frac{1}{n})
$$


# 036
**時計の長針と短針に挟まれた角度・2本の針の距離を求める**

- 長針の角度
    - $360$ 度 $/ \space 60$ 分 $ = 6$ 度 $/$ 分
    - $\displaystyle rad\_a = \frac{\pi}{180} \times minute \times 6$
- 短針の角度
    - $360$ 度 $/ \space 12$ 時間 $=30$ 度 $/$ 時間 $=0.5$ 度 $/$ 分
    - $\displaystyle rad\_b = \frac{\pi}{180} \times (hour \times 30 + minute \times 0.5)$
- 長針と短針が作る角度
    - $C = rad\_b - rad\_a$
- 長針と短針の端点同士の距離
    - 余弦定理より、 $c = \sqrt{a^2+b^2-2ab \cos C}$


# 047
**二部グラフ判定**

DFSでもBFSでもいいので、頂点 $1$ から始めてグラフの経路を全て辿っていく。

$m(i) = 0 \space or \space 1$ という配列を用意し、$m(1) = 0$ から始める。

頂点 $i$ を探索して頂点 $j$ が新たに見つかった場合、 $m(j) = 1 - m(i)$ を入れる。

頂点 $i$ を探索して探索済の頂点 $k$ が見つかった場合、$m(i) = m(k)$ なら二部グラフではない。

この問題の場合は、連結グラフとは限らないので、未探索の頂点があればその点からDFS及びBFSで探索を行う必要がある。

Union Findで解くことも可能。


# 048

(pending)


# 050
**modpow**

$a^b \space mod \space 1000000007$ を求める

制約が $1 \le b \le 10^9$ と $b$ の値が大きいので、繰り返し二乗法を使う。

繰り返し二乗法とは、指数部を2の累乗の積に分解して計算する方法。

$2^n$ についてだけ計算すればよくなるので、 $O(\log b)$ の計算量で答えを求められる。

ex. $b = 10000$

$$
\begin{aligned}
b &= 10000 \\
  &= 8192 + 1024 + 512 + 256 + 16 \\
  &= 2^{13} + 2^{10} + 2^{9} + 2^{8} + 2^{4}
\end{aligned}
$$


# 051
**二項係数を素数で割った余り**

右に移動する回数が $X$ 回、上に移動する回数が $Y$ 回で順序を問わないので、この組み合わせである $_{X+Y}C_X \space mod \space 1000000007$ が答えになる。

組み合わせを求める式は以下のように変形できる

$\displaystyle _nC_k = \frac{n!}{k!(n-k)!} = n! \cdot (k!)^{-1} \cdot ((n-k)!)^{-1}$

$n!$ 、 $(k!)^{-1}$ 、 $((n-k)!)^{-1}$ の3つを求める。


二項係数を求める前処理として以下の配列を作成する。
- 階乗 $fact(i+1) \equiv i! \cdot (i+1) \qquad (mod \space P)$
- 逆元 $\displaystyle inv(i)^{-1} \equiv - (P \% (i ))^{-1} \cdot \lfloor \frac{P}{i} \rfloor \qquad (mod \space P)$
- 階乗の逆元 $fact\_inv(i) = fact\_inv(i-1) * inv(i)$

この3つを求められれば、組み合わせの式に代入して答えが求められる。

$$
_nC_k = n! \cdot (k!)^{-1} \cdot ((n-k)!)^{-1} \\
 = fact(n) \cdot (fact\_inv(x) \cdot fact\_inv(n-x) \% mod) \% mod
$$


# 052

051の応用問題。

051では1ステップにつき $(a+1,b)$ か $(a,b+1)$ 動くのに対し、本問では $(a+1,b+2)$ か $(a+2,b+1)$ 動く。

それぞれの移動回数を求めるには以下の連立方程式を解けば求まる。

$$
\begin{cases}
 \space p(A + 2B) = X \\
 \space q(2A + B) = Y
\end{cases}
$$

但し、 $p>2q$ または $q>2p$ となるような解になった場合、辿り着けないので除外する必要があるので少し面倒。

$X,Y \le 10^6$ なので、$A$ について全探索して答えを探す。

$A$ を固定すると $B = X - 2A$ で求まるので $A + 2B = Y$ かつ、 $Y \ge 0$ が成立すれば答えになる組み合わせなので、$_{A+B}C_A$ を二項係数を使って答えを求める。


# 053

$4^0+4^1+4^2+4^3+...+4^{N}$

これは、初項 $a=1$、公比 $r=4$ の等比数列なので、等比数列の総和の公式を使って総和を求める。

$$
\displaystyle
 \sum_{i=1}^{n}ar^{k-1} = \frac{ar^{n+1}-1}{r-1} \\
  = \frac{1 \cdot 4^{n+1}-1}{4-1}
  = \frac{4^{n+1}-1}{3}
$$

分母、分子それぞれを剰余を考慮しながら計算する。


# 054
**行列累乗**

$$
a_1 = 1, a_2 = 1 \\
a_{n} = a_{n-1} + a_{n-2} \space (n\ge3)
$$

この漸化式を行列で表現する。

$$
\left( 
  \begin{array}{ccc} 
    a_{n+2} \\
    a_{n+1} 
  \end{array} 
\right) 
 = 

\left( 
  \begin{array}{ccc} 
    a_{n+1} + a_{n} \\ 
    a_{n+1} 
  \end{array} 
\right) \\

 =
\left( 
  \begin{array}{ccc} 
    1 & 1  \\ 
    1 & 0
  \end{array} 
\right) 
\left( 
  \begin{array}{ccc} 
    a_{n+1} \\ 
    a_{n}
  \end{array} 
\right) \\

 =
\left( 
  \begin{array}{ccc} 
    1 & 1  \\ 
    1 & 0
  \end{array} 
\right) ^ {n-1}
\left( 
  \begin{array}{ccc} 
    a_2 \\ 
    a_1
  \end{array} 
\right) \\

 =
\left( 
  \begin{array}{ccc} 
    1 & 1  \\ 
    1 & 0
  \end{array} 
\right) ^ {n-1}
\left( 
  \begin{array}{ccc} 
    1 \\ 
    1
  \end{array} 
\right) 

$$


となる。

最後の部分、

$$
\left( 
  \begin{array}{ccc} 
    1 & 1  \\ 
    1 & 0
  \end{array} 
\right) ^ {n-1}
$$

は、繰り返し二乗法を行列計算に応用することで高速に計算が行える。

（余談）ビネの公式

フィボナッチ数列の一般項を求める公式にビネの公式がある。

$ \displaystyle a_n = \frac{1}{\sqrt{5}} \{ (\frac{1 + \sqrt{5}}{2})^n - (\frac{1 - \sqrt{5} }{2})^n \}$

この方法だと行列演算はしなくていいが、ルートの処理が必要になるので誤差が生じる可能性がある。


# 055

054の類題。漸化式を行列で表現する。

あとは054と同じ。

$$
a_1 = 1, a_2 = 1 \\
a_{n} = 2a_{n-1} + a_{n-2} \space (n\ge3)
$$

$$
\left( 
  \begin{array}{ccc} 
    a_{n+2} \\
    a_{n+1} 
  \end{array} 
\right) 
 = 

\left( 
  \begin{array}{ccc} 
    2a_{n+1} + a_{n} \\ 
    a_{n+1} 
  \end{array} 
\right) \\

 =
\left( 
  \begin{array}{ccc} 
    2 & 1  \\ 
    1 & 0
  \end{array} 
\right) 
\left( 
  \begin{array}{ccc} 
    a_{n+1} \\ 
    a_{n}
  \end{array} 
\right) \\

 =
\left( 
  \begin{array}{ccc} 
    2 & 1  \\ 
    1 & 0
  \end{array} 
\right) ^ {n-1}
\left( 
  \begin{array}{ccc} 
    a_2 \\ 
    a_1
  \end{array} 
\right) \\

 =
\left( 
  \begin{array}{ccc} 
    2 & 1  \\ 
    1 & 0
  \end{array} 
\right) ^ {n-1}
\left( 
  \begin{array}{ccc} 
    1 \\ 
    1
  \end{array} 
\right) 

$$


# 056

054の応用。漸化式を行列で表現する。

3x3の行列になるが、あとは054と同じ。

$$
a_1 = 1, a_2 = 1, a_3 = 2 \\
a_{n} = a_{n-1} + a_{n-2} + a_{n-3} \space (n\ge4)
$$


$$
\left( 
  \begin{array}{ccc} 
    a_{n+3} \\ 
    a_{n+2} \\
    a_{n+1} 
  \end{array} 
\right) 
 = 

\left( 
  \begin{array}{ccc} 
    a_{n+2} + a_{n+1} + a_{n} \\ 
    a_{n+2} \\
    a_{n+1} 
  \end{array} 
\right) \\

 =
\left( 
  \begin{array}{ccc} 
    1 & 1 & 1 \\ 
    1 & 0 & 0 \\
    0 & 1 & 0
  \end{array} 
\right) \\

\left( 
  \begin{array}{ccc} 
    a_{n+2} \\ 
    a_{n+1} \\
    a_{n} 
  \end{array} 
\right) \\

 =
\left( 
  \begin{array}{ccc} 
    1 & 1 & 1 \\ 
    1 & 0 & 0 \\
    0 & 1 & 0
  \end{array} 
\right) ^{n-1}

\left( 
  \begin{array}{ccc} 
    a_3 \\ 
    a_2 \\
    a_1 
  \end{array} 
\right) \\

 =
\left( 
  \begin{array}{ccc} 
    1 & 1 & 1 \\ 
    1 & 0 & 0 \\
    0 & 1 & 0
  \end{array} 
\right) ^{n-1}

\left( 
  \begin{array}{ccc} 
    2 \\ 
    1 \\
    1 
  \end{array} 
\right) 

$$

# 057

(pending)


# 061

このゲームの必勝法を考える。

小さい数字でシミュレーションしてみる。


$$
N=1 \quad 1 \xrightarrow{1 \text{\textasciitilde} 1/2} \times \quad  \text{Second} \\

N=2 \quad 2 \xrightarrow{1 \text{\textasciitilde} 2/2} 1 \xrightarrow{1 \text{\textasciitilde} 1/2} \times \quad \text{First} \\
N=3 \quad 3 \xrightarrow{1 \text{\textasciitilde} 3/2} 2 \rightarrow 1 \quad \text{Second} \\
N=4 \quad 4 \xrightarrow{1 \text{\textasciitilde} 4/2} 3 \rightarrow 2 \rightarrow 1 \quad \text{First} \\

N=5 \quad 5 \xrightarrow{1 \text{\textasciitilde} 5/2} 3 \rightarrow 2 \rightarrow 1 \quad \text{First} \\

N=6 \quad 6 \xrightarrow{1 \text{\textasciitilde} 6/2} 3 \rightarrow 2 \rightarrow 1 \quad \text{First} \\

N=7 \quad 7 \xrightarrow{1 \text{\textasciitilde} 7/2} 4 \space or \space 5 \space or \space 6 \rightarrow 3 \rightarrow 2 \rightarrow 1 \quad \text{Second} \\

N=8 \quad 8 \xrightarrow{1 \text{\textasciitilde} 8/2} 7 \rightarrow  4 \space or \space 5 \space or \space 6 \rightarrow 3 \rightarrow 2 \rightarrow 1 \quad \text{First} \\

N=9 \quad 9 \xrightarrow{1 \text{\textasciitilde} 9/2} 7 \rightarrow  4 \space or \space 5 \space or \space 6 \rightarrow 3 \rightarrow 2 \rightarrow 1 \quad \text{First} \\

$$

$N=7$ の場合は先手は1個～3個の範囲から取ることになるが、 取った後のパターン $a=4,5,6$ のいずれにおいても後手が3を作って必ず勝つことが分かる。

また、 $N=8,9$ を見ると、$N=10,11,12,13,14$ の場合も先手は $a=7$ になるように取れるので必ず勝てることが分かる。

$N=15$ の場合は $N=7$ の時と同様に、先手の取り方に関係なく後手は $a=7$ を作れるので後手勝ちになる。

$N=16 \text{\textasciitilde} 31$ の場合は $N=8 \text{\textasciitilde} 14$ の時と同じパターンになる。

以上から、 $N\gt2$ の時において $N=2^k-1$ の場合のみ後手が勝ち、それ以外の時は先手が勝つ。


# 062
**周期性／ダブリング**

**解法１：周期性を見つける**

町１からのテレポートを順に辿っていき、ループの始点を2度訪れたら処理を終了。

Kがループに入る前にあるならそのままK+1番目の位置が答え。

Kがループの中なら、Kから始点までの距離を引いた値とループの長さの剰余の位置が答え。

**解法２：ダブリング**

参考：ダブリングの基本概念とその応用

https://algo-logic.info/doubling/


# 066

制約の2つ目の、

- $1 \leq K \leq \min(5,N-1)$

より、$K$ は最大でも $5$ であるから、書き込めるパターンを数えるよりも書き込めないパターンを数えて全体から引いたほうが計算は簡単になる。

書き込めないパターンは、黒色・白色・灰色のカードの整数差がKより小さい場合になる。このパターンの洗い出しであれば、$N \times 4 \times 4$ で $O(N)$ の計算量で済む。両端の扱いに注意。


# 067

**包除原理**

あらかじめ各行と各列の総和を求めておき、マス $(i,j)$ の値は包除原理を使って求める。

$$
\displaystyle
 B(i,j) = \sum_{k=1}^{h}A(i,k) + \sum_{k=1}^{w}A(k,j) - A(i,j)
$$

# 068

包除原理の応用。

$n$ 個の有限集合 $A_1, ..., A_n$ が与えられたとき、その和集合に属する元の数は次のように表せる。

$$
\displaystyle
 \left| \bigcup_{i-1}^{n} Ai \right| = \sum_{k=1}^n (-1)^{k-1}  \sum_{j \sube |n|, |J| = k } \left| \bigcap_{j \in J}  A_j \right| \\
 = \sum_i |A_i| - \sum_{i<j} \left| Ai \cap Aj \right| + \cdots + (-1)^{n-1} \left| Ai \cap \cdots \cap \ A_n \right|
$$

集合の重なった部分のパターンはビット全探索で洗い出せるので、該当する用の数をLCMを使って求め、立っているビットの数が奇数なら加算、偶数なら減算していくと答えが求まる。


# 070

最小の面接となる長方形は、 $K \ge 4$ の時、辺上に点が少なくとも4つ存在する。$K \lt 4$ の場合は全ての点が辺上にある。

$N \lt 50$ と小さいので、点を使って全探索する。計算量は $O(N^5)$ になるが時間内に処理は完了できる。


# 071

**線形計画問題**

まず $N=2$ の場合について考える。

$a_1x+b_1y \le c_1, \space a_2x+b_2y \le c_2$ において、 $(x,y)$ が以下の2つの直線の交点になる時に $x+y$ が最大になる。

- $a_1x + b_1y - c_1 = 0$
- $a_2x + b_2y - c_2 = 0$

$$
\begin{cases}
  a_1x + b_1y - c_1 = 0 \quad \cdots (1) \\
  a_2x + b_2y - c_2 = 0 \quad \cdots (2) \\
\end{cases}
$$

まず $y$ を消した式を作る。
$(1)$ の両辺に $b_2$ を、 $(2)$ の両辺に$b_1$ を掛ける。

$$
\begin{cases}
  a_1b_2x + b_1b_2y - b_2c_1 = 0 \quad \cdots (1)' \\
  a_2b_1x + b_1b_2y - b_1c_2 = 0 \quad \cdots (2)' \\
\end{cases}
$$

$(1)' - (2)'$

$$
a_1b_2x - b_2c_1 - a_2b_1x + b_1c_2 = 0 \\
(a_1b_2 - a_2b_1)x = b_2c_1 - b_1c_2  \quad \cdots (3)
$$

同様にして $x$ を消した式を作る。
$(1)$ の両辺に $a_2$ を、 $(2)$ の両辺に$a_1$ を掛ける。

$$
\begin{cases}
  a_1a_2x + b_1a_2y - a_2c_1 = 0 \quad \cdots (1)" \\
  a_1a_2x + a_1b_2y - a_1c_2 = 0 \quad \cdots (2)" \\
\end{cases}
$$

$(2)" - (1)"$

$$
a_1b_2y - a_1c_2 - b_1a_2y + a_2c_1 = 0 \\
(a_1b_2 - b_1a_2)y = a_1c_2 - a_2c_1  \quad \cdots (4)
$$

$(3),(4)$ より、 $a_1b_2 - b_1a_2 = 0$ の場合は解がないので2本の直線は平行。

$a_1b_2 - b_1a_2 \ne 0$ の場合には解があり、その解は、

$$
\displaystyle
 x = \frac{b_2c_1 - b_1c_2}{a_1b_2 - a_2b_1} \quad, \quad y = \frac{a_2c_1 - a_1c_2}{a_1b_2 - b_1a_2}
$$

となる。

ここから $N > 2$ の場合を考える。

問題の答えとなる $(x,y)$ は、$N$ 個の式から2つを選んだ場合のいずれかになる。

$N \le 500$ と数が小さいので全探索で全ての組み合わせの場合の $x+y$ を計算し、その中の最大値が最終的に求める答えになる。

# 072

$x$ と $y$ を全探索すると計算量が大きくなってTLEする。

答えとなる最大値で全探索する方法であれば計算量は十分足りる。

$C=GCD(A,B) \quad (A<B)$ とすると $C$ は $A$ より大きくなることはないので、$A$ から始めてデクリメントしながら答えを探していく。

選んだ $C$ が答えになり得るかは、$[A,B]$ に $C$ の倍数が2つ以上あるかで分かる。倍数の個数は、

$\displaystyle \lfloor \frac{C}{A} \rfloor  - \lfloor \frac{C}{B} \rfloor $

で求まる。


# 073

$A_1, A_2, \dots , A_N$ がそれぞれ何回使われるかを考える。

最大値を数えやすくするためにまず $A$ をソートする。

例として $N=4, A={2,3,5,7}$ でパターンを洗い出すと、
{2}, {3}, {5}, {7}, {2,3}, {2,5}, {2,7}, {3,5}, {3,7}, {5,7}, {2,3,5}, {2,3,7}, {2,5,7}, {3,5,7}, {2,3,5,7} の15通りのそれぞれ一番右にある要素の数を数えると7が8回、5が4回、3が2回、2が1回となる。
ここから、$A_i$ を使う回数は $2^i$ になると予想できる。よって、

$$
\displaystyle
    \sum_{i=1}^{n} A_i \times ^i \mod 1000000007
$$

が答えになる。

**wip**  続きここから

# 074

ある要素 $A_k$ が $(A_j-A_i)$ の部分の左側で何回、右側で何回使われるかを数えて最後に乗算すると計算量を減らせる。

$A_k$ が $A_j$ 側として使われる回数は $k-1$ 回、$A_i$ 側として使われる回数は $N-k-1$ 回である。

よって、問題文で与えられた計算は、

$$
\displaystyle \sum_{i=1}^{N} \sum_{j=i+1}^{N} (A_j-A_i) \\
 = \sum_{i=1}^{N} A_i \times (i-1 - (N-i-1))
 = \sum_{i=1}^{N} A_i \times (2i- N)
$$

と置き換えられ、計算量を $O(N^2)$ から $O(N)$ にすることができる。

# 075
**二項係数**

与えられた最下段の各要素を操作中で使う回数は、パスカルの三角形の値と一致する。 
最下段の値の合計が答えになるので、

$$
\displaystyle \sum_{i=0}^{N-1}  (_{N-1}C_{i})
$$


で求められる。

$_{N-1}C_{i}$ は二項係数を計算する方法を使って求めていく。


# 076
074の応用問題

絶対値をそのまま計算すると計算量が減らせないのでAをソートする。（順番を変えても答えは変わらない）

そうすると、

$$

|A_1-A_2| + |A_1-A_3| + |A_1-A_4| + |A_1-A_5| \\
+ |A_2-A_3| + |A_2-A_4| + |A_2-A_5| \\
+ |A_3-A_4| + |A_3-A_5| \\
+ |A_4-A_5| \\
= (A_2-A_1) + (A_3-A_1) + (A_4-A_1) + (A_5-A_1) \\
+ (A_3-A_2) + (A_4-A_2) + (A_5-A_2) \\
+ (A_4-A_3) + (A_5-A_3) \\
+ (A_5-A_4) \\
= \{(A_2+A_3+A_4+A_5) - 4A_1\} + \{(A_3+A_4+A_5) - 3A_2\} + \{(A_4+A_5) - 4A_3\} + \{A_5 - A_4\}
$$

と変形できる。

$A_2+A_3+A_4+A_5$ 、 $A_3+A_4+A_5$ 、 $A_4+A_5$ 、$A_5$ の部分は累積和を使えば、それぞれ $O(1)$ で求められる。よって $O(N)$ で計算できる。


# 077
076の応用問題

マンハッタン距離は $|x_1 − x_2| + |y_1 − y_2|$ で求めるとあり、本問では $x$ と $y$ を独立して考えることができる。


# 079

$N$ が $10^9$ までと大きいので、組み合わせ全探索では計算量が大きすぎてTLEする。

規則性を考える。

例３で `78` となるのはどんな並びの時かを考える。

左から貪欲法でやってみると、 $P=\{2,3,4,5,6,7,8,9,10,11,12,13,1\}$ とすると、 $1+2+3+4+5+6+7+8+9+10+11+12+13 = 78$ になる。

一番右の要素を除いては最大の値になるのでこれが最大値であると考えられる。
よって、$1$ から $N-1$ までの総和が答えとなる。


# 080

(pending)


# 084

そのまま `sqrt` 関数で比較すると浮動小数点数の誤差で誤った結果を返すことがある。

計算機イプシロンの `DBL_EPSILON` ないし `LDBL_EPSILON` を使って、浮動小数点数の誤差範囲内であれば `Yes` を返すようにする。

**別解 整数のまま比較する**

条件の式を変形する。

$$
\displaystyle
\begin{align*}
\sqrt{a} + \sqrt{b} \lt \sqrt{c} \\
 \Leftrightarrow (\sqrt{a} + \sqrt{b})^2 < c \\
 \Leftrightarrow a+b+2\sqrt{ab} < c \\
 \Leftrightarrow 2\sqrt{ab} < c-a-b \quad \dots (1) \\
 \Leftrightarrow 4ab < (c-a-b)^2 \quad \dots (2) \\
\end{align*}
$$

$(2)$だけで判定すると $c-a-b$ が負の場合でも成立するケースがあるので、 $c-a-b > 0$ と合わせて両方が真であれば `Yes` を返す。


# 087

愚直に計算すると計算量が $O(N^2)$ となりTLEするので、計算量を減らす工夫を考える。

$n=3$ の場合で考えてみると、以下のように変形ができる。

$$
\displaystyle
\sum_{i=1}^{N} \sum_{j=1}^{N} ij \\
  = (1 \times 1) + (1 \times 2) + (1 \times 3) \\
  \quad + (2 \times 1) + (2 \times 2) + (2 \times 3) \\
  \quad + (3 \times 1) + (3 \times 2) + (3 \times 3) \\
  = 1 \times (1+2+3) \\
  \quad + 2 \times (1+2+3) \\
  \quad + 3 \times (1+2+3) \\
  = (1+2+3) \times (1+2+3) \\
  = (1+2+3)^2
$$

よって、 $\displaystyle (\sum_{i=1}^{N}i)^2 = \{\frac{n(n+1)}{2}\}^2$ を計算することで $O(1)$ で答えが求められる。


# 088
087の応用問題。

まず、$a$ と $b$ だけで考えてみる。

087と同じように考えると、

$$
\displaystyle
\sum_{a=1}^{A} \sum_{b=1}^{B} ab \\
= (\sum_{i=1}^{A}i) \times (\sum_{j=1}^{B}j)
$$

となる。
値が3つになった場合も同様に扱うことができるので、

$$
\displaystyle
\sum_{a=1}^{A} \sum_{b=1}^{B} \sum_{c=1}^{C} abc \\
= (\sum_{i=1}^{A}i) \times (\sum_{j=1}^{B}j) \times (\sum_{k=1}^{C}k) \\
= \frac{A(A+1)}{2} \times \frac{B(B+1)}{2} \times \frac{C(C+1)}{2}
$$

で $O(1)$ で答えが求められる。


# 089

$a,b,c \le 10^{18}$ と値が大きいので、そのまま `log2` 関数を使うと誤差が生じて正しい結果が得られない場合がある。

誤差が生じないようにする方法として、整数で考える。

判定式は以下のように置き換えられる。

$$
\log_2{a} \le b \log_2{C} \\
\Leftrightarrow \log_2{a} \le \log_2{C}^{b} \\
\Leftrightarrow  a \le c^b
$$

整数に変換しても、このままでは $c^b$ の部分が $10^{18}$ の $10^{18}$ 乗を計算することになり、これもこのまま計算することはできない。

そこで、$c^k$ が $a$ を超えた時点でループを抜けるようにする。
$a$ がオーバーフローしないようにする工夫として、判定の部分を以下のようにする。

$$

a \le c^k \\
\Leftrightarrow \frac{a}{c} \le c^{k-1}
$$

さらに、$c=1$ の場合、ループを最悪 $10^{18}$ 回繰り返してしまうので、この場合だけ処理を分ける。この時、$a$ にどんな値を入れても左辺の方が小さくなることはないので、 $c=1$ ならば無条件に `No` を返すようにする。

これで全てのテストケースが通る。


# 092

縦の長さと横の長さは整数であることから、面積 $N$ の約数になる。

よって、$N$ の約数を洗い出す。

約数の数は高々しれているので、全探索して周囲の長さの最小値を探しても十分間に合う。


# 093

$A$ と $B$ の値が大きいのでそのまま $LCM(A,B)$ を求めようとするとオーバーフローしてしまう。

LCMとGCDには以下のような性質がある。

- 正整数 $A,B$ について、 $A \times B = LCM(A,B) \times GCD(A,B)$

この説明については以下を参照。

参考：高校数学の美しい物語　最大公約数と最小公倍数の積の性質の２通りの証明

https://manabitimes.jp/math/1032

ここで、GCDはオーバーフローせずに求めることができるので、GCDを使ってLCMを求める。

上の等式を変形すろと、$\displaystyle LCM(A,B) = \frac{A \times B}{GCM(A,B)}$ となるので、これを計算して値が $10^{18}$ を超えるかが判定できる。

この計算のみを浮動小数点型で行ってもよいし、LONG LONG型のまま判定するなら、 $\displaystyle \frac{A}{GCM(A,B)} \le \frac{10^{18}}{B}$ で比較すればオーバーフローしないで正しく判定できる。
