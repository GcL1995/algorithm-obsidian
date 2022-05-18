[F. Desktop Rearrangement](https://codeforces.com/contest/1674/problem/F)
#树状数组 
> 题目大意：
> 二维数组01字符串，要求1的左边所有列都是1，1的上边都是1需要交换多少次01.
~~~c++
/*
i. 二维数组变化为一维数组
ii. 需要求所有的1的个数 star，以及前star位的1的个数
iii. 树状数组可以o(longn)时间复杂度内求解得到
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

const int N = 1010;
const int INF = 1e9;

int T, n, m, q;
char w[N][N];
char g[N*N];
int tr[N * N];

int lowbit(int x) {
    return -x & x;
}

void add(int x, int c) {
    for (int i = x; i <= n * m; i += lowbit(i) ) {
        tr[i] += c;
    }
}

LL query(int x) {
    LL ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        ans += tr[i];
    }
    return ans;
}

void solve() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) scanf("%s", w[i]);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) g[i * n + j + 1] = w[j][i];
    }
    for (int i = 1; i <= n * m; i++) {
        if (g[i] == '*') add(i, 1);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int fx = x + y * n + 1;
        if (g[fx] == '.') {
            g[fx] = '*';
            add(fx, 1);
        } else {
            g[fx] = '.';
            add(fx, -1);
        }
        LL star = query(n * m);
        LL empty = star - query(star);
        cout << empty << endl;
    }
}

int main() {
    T = 1;
    while (T -- ) {
        solve();
    }
    return 0;
}
~~~