[D. Permutation Restoration](https://codeforces.com/contest/1701/problem/D)
#贪心 
> 题目大意：
> 	对于一个排列a, 可以将该排列转化为数组b，其中b[i] = i / a[i];
> 	给定一个数组b， 求任意一个满足上述变化的原排列。
> 提示一：
$$
\begin{aligned}
&\lfloor i / a_i \rfloor = b_i \\
& a_i * b_i <= i < a_i * (b_i * 1)\\
& i/(b_i + 1) <  a_i <= i / b_i
\end{aligned}
$$
提示二：
	根据提示一，可以放在位置i的是一个区间的任意值
提示三：
	现在考虑将i放在哪个位置，现在有多个区间都包含i那么要把i放在哪个位置上呢？
提示四：
	将i从1迭代到n的过程中考虑提示三。我们可以在这个过程中我们把左端点小于等于i的依次都放入了堆中。
提示五：
	结论是右端点小的，为什么呢？因为右端点大的一定有机会分配到。
提示六：
	这样的贪心策略是否成功呢？

~~~c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <functional>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef unsigned long long ULL;

const int N = 200010;
const int INF = 1e9;

int T, n, m, k;
int w[N];


void solve() {
    cin >> n >> m;
    vector<LL> a(n + 1);
    vector<LL> s(n + 1);
    for (int i = 1; i <= m; i ++ ) cin >> w[i], a[w[i]] ++;
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];

    auto check = [&](int x) {
        if (a[n] <= x) return true;
        int l = lower_bound(a.begin(), a.end(), x) - a.begin();
        LL rem = s[n] - s[l - 1] - x * (n - l + 1);
        for (int i = 1; i < l; i ++ ) {
            rem -= (x - a[i]) / 2;
        }
        //printf("%d %d %d %d\n", x, l, s[n] - s[l - 1], rem);
        return rem <= 0;

    };
    int l = 1, r = (2 * m + n - 1) / n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
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

