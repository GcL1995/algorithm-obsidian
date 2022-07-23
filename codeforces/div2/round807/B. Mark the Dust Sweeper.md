[B. Mark the Dust Sweeper](https://codeforces.com/contest/1705/problem/B)
> 题目大意：给定一个数组a，表示第i个位置有a[i]灰尘。一个特殊的扫把，如果a[i ~ j - 1] > 0， 那么a[i] = a[i] - 1, a[j] = a[j] + 1。
> 问将所有的灰尘扫到第n个位置需要多少次操作？
> 提示一：如果全部位置都大于0，那么直接从a[1]加到a[n - 1]就行。可以证明这是最优解。
> 提示二：为了能够达到提示一，那么找到第一个不是0的位置，然后填充他之后第一个是0的位置，此时经过一次操作，直到达到提示一的情况。
> 提示三：提示二可以使用双指针算法实现，有没有其他方法？
> 提示四：一个0需要一次操作可以填充。那么遇到0直接ans ++。

~~~c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int>> VII;

const int N = 200010;
const int INF = 1e9;

int T, n, m, k;
LL w[N], s[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    LL ans = 0;
    int i = 1;
    while (i <= n && w[i] == 0) i ++;
    for (;i <= n - 1; i ++ ) {
        if (w[i] == 0) ans ++;
        ans += w[i];
    }
    cout << ans << "\n";
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
