[ACW 6. 多重背包问题 III](https://www.acwing.com/problem/content/6/)
#DP #背包问题 #多重背包问题 #单调队列优化DP 
>题目大意：
>	N种物品，容量为V的背包。
>	第i中物品，最多有s[i]件， 每件的体积为v[i], 价值为w[i].
>	求解物品体积总和不超过背包容量的最大价值为多少？
>	N <= 1000 V <= 20000 v[i], w[i], s[i] <= 20000
>提示一：将多重背包转化为01背包的时间复杂度为o(V * N * log(N))
>提示二：观察状态转移方程

$$
\begin{aligned}
&f[i][j] = max(f[i - 1][j - v] + w, f[i - 1][j - 2v] + 2w, ...., f[i - 1][j - sv] + sw);\\
&f[i][j - v] = max(f[i - 1][j - 2v] + 2, f[i - 1][j - 3v] + 2w),..., f[i - 1][j - (s + 1)v] + sw;
\end{aligned}
$$
> 提示三：如果撇开偏移量，那么提示二中的状态转移方程意味着找到一个滑动窗口大小为s的最大值。
> 提示四：具体实现过程中，如何来实现这样一个滑动窗口的查询以及如何更新f(i, j)

~~~c++
#include <iostream>
#include <cstring>

using namespace std; 

const int N = 20010; 

int n, m; 
int f[N], g[N], q[N]; 

int main() {
    cin >> n >> m; 
    for (int i = 0; i < n; i ++ ) {
        int v, w, s;
        cin >> v >> w >> s;
        memcpy(g, f, sizeof f); 
        for (int j = 0; j < v; j ++ ) {
            int hh = 0, tt = -1; 
            for (int k = j; k <= m; k += v) {//这一个问题看做一个滑动窗口的子问题 窗口大小为s
                if (hh <= tt && k - q[hh] > s * v) hh ++; //说明第一个数与当前数之间超过了s个数
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt --;
                q[++ tt] = k;//为什么要先添加进队列？这一情况表明应该当前的物品不会对结果产生影响。
                f[k] = g[q[hh]] + (k - q[hh]) / v * w;
            }
        }
    }
    cout << f[m] << endl; 
    return 0; 
}

~~~