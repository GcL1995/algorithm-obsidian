[D. Permutation Graph](https://codeforces.com/problemset/problem/1696/D)
#二分 #稀疏表 #DFS 
> 题目大意：
> 	数组a为一个从1到n的排列。
> 	如果一个区间的两个端点分别是这个区间的最小值和最大值，那么这两个点之间连一条边。
> 	这样可以构造一个无向连通图。
> 	求问从1到n的最短路径长度。
> 提示一：如果a[1]和a[n]分别是最大值和最小值, 那么直接结束
> 提示二：如果a[1]和a[n]不满足提示一，那么一定会通过的中间点是哪个？最大值或者最小值的位置。
> 提示三：根据提示二缩小问题规模，之后可以使用同样的逻辑吗？当然可以。
> 提示四：交换寻找最大值和最小值一定可以缩小规模，否则，就满足提示一。
> 提示五：提示四确定了一个递归问题，这个递归问题如何结束？提示一结束或者只有一个点结束。
> 提示六：需要确定任意一个区间最大值和最小值的下标，如何在log(n)的时间复杂度内获得？稀疏表 + map

~~~c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef unsigned long long ULL;

const int N = 250010, M = 18;
const int INF = 1e9;

int T, n, m, k;
int w[N], f[N][M], g[N][M];
int pos[N];

void init() {
    for (int j = 0; j < M; j ++ ) {
        for (int i = 1; i + (1 << j) - 1 <= n; i ++ ) {
            if (!j) f[i][j] = w[i], g[i][j] = w[i];
            else {
                f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
                g[i][j] = min(g[i][j - 1], g[i + (1 << j - 1)][j - 1]);
            }
        }
    }
}

int query(int l, int r, int t) {
    int k = log(r - l + 1) / log(2);
    if (t == 0) return max(f[l][k], f[r - (1 << k) + 1][k]);
    return min(g[l][k], g[r - (1 << k) + 1][k]);
}

int dfs(int l, int r, int t) {
    if (l == r) return 0;
    int mid;
    if (t == 0) {
        if (w[r] == query(l, r, 0)) mid = pos[query(l, r, 1)];
        else mid = pos[query(l, r, 0)];
    } else {
        if (w[l] == query(l, r, 0)) mid = pos[query(l, r, 1)];
        else mid = pos[query(l, r, 0)];
    }
    if (mid == l || mid == r) return 1;
    return dfs(l, mid, 0) + dfs(mid, r, 1);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i], pos[w[i]] = i;
    init();
    cout << dfs(1, pos[n], 0) + dfs(pos[n], n, 1)<< endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
~~~