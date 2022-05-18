[F. Vlad and Unfinished Business](https://codeforces.com/problemset/problem/1675/F)
#DFS #向上标记法 
> 题目大意：
> n个点n-1条边的一个树，要求刚开始在x点，最终到达y点，途经指定的k个点，路径可以重复，求最短路径长度

~~~c++
/*
i. 以x为根构成一棵树
ii. 将k+1个点到根的需要经过的所有边画出来(k个点 + y)， 则有标记出来的边必须都经过2次，而y到x的整条路径只需要经过1次
iii. 这样我们可以通过dfs标记出来一个点的父节点
iv. 同时遍历k个点，通过向上标记法，获得所需的路径长
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef unsigned long long ULL;

const int N = 200010, M = 2 * N;
const int INF = 1e9;

int T, n, k;
int need[N];
int e[M], ne[M], h[N], idx;
int dist[N], f[N];
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa, int v) {
    dist[u] = v;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j != fa) {
            f[j] = u;
            dfs(j, u, v + 1);
        }
    }
}

void solve() {
    cin >> n >> k;
    memset(h, -1, sizeof h);
    memset(st, false, sizeof st);
    idx = 0;

    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= k; i ++ ) cin >> need[i];
    need[k + 1] = y;
    for (int i = 0; i < n - 1; i ++ ) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(x, x, 0);

    LL ans = 0;
    st[x] = true;
    for (int i = 1; i <= k + 1; i ++ ) {
        int j = need[i];
        while(!st[j]) {
            st[j] = true;
            ans += 2;
            j = f[j];
        }
    }
    ans -= dist[y];
    cout << ans << endl;
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
~~~
[[D. Vertical Paths]]