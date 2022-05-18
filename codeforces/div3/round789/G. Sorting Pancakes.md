[G. Sorting Pancakes](https://codeforces.com/problemset/problem/1675/G)
#DP #TODO 
>题目大意：
>一个数组a表示n个盘子中放得蛋糕，每次可以交换相邻两个盘子的一个蛋糕，问使得a数组非严格递减的最小交换次数
~~~c++
/*
i. f[i][j][k] 表示 前i个前缀和为j， a[i] = k的最小花费
ii. 
	状态转移方程：f[i][j][k] = min(f[i - 1][j - x][x] + abs(s[i] - j)) (x <= k)
	为什么从f[i - 1][j - x][x] ---> f[i][j][k] 的 代价是abs(s[i] - j)
	首先s[i] > j的时候是显然的，只需要把a[i] 往后移动就行
	s[i] < j 的时候，为什么是j - s[i]呢？因为后面所有的情况我们都会考虑的，最终的代价是
	sum((s[i] - sum(b[1-i]))) (1 <= i <= n)
iii. 如何优化：
	for (int x = k; x <= m; x ++ ) {
	    f[i][j][k] = min(f[i][j][k], f[i - 1][j - k][x] + abs(s[i] - j))
    }
    这里面的最小值只和i - 1, j - k 和 k相关
    只需要对于每个f[i][j][k] 预处理出来从k --- m的最小值就可以了(其实需要用到的只有一部分)
iii. 这样时间复杂度是o(n^3)绰绰有余了
*/
//
// Created by Administrator on 2022/5/7.
//
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

const int N = 260;
const int INF = 0x3f3f3f3f;

int T, n, m;
int w[N], s[N], f[N][N][N], g[N][N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + w[i];
    memset(f, 0x3f, sizeof f);
    memset(g, 0x3f, sizeof g);
    f[0][0][m] = 0;

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= m; j ++ ) {
            g[i - 1][j][m] = f[i - 1][j][m];
            for (int k = m - 1; k >= 0; k -- ) {
                g[i - 1][j][k] = min(g[i - 1][j][k + 1], f[i - 1][j][k]);
            }
            for (int k = 0; k <= j; k ++ ) {
                for (int x = k; x <= m; x ++ ) {
                    //f[i][j][k] = min(f[i][j][k], f[i - 1][j - k][x] + abs(s[i] - j));
                    f[i][j][k] = g[i - 1][j - k][k] + abs(s[i] - j);
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i <= m; i ++ ) ans = min(ans, f[n][s[n]][i]);
    cout <<ans;
}

int main() {
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
~~~
