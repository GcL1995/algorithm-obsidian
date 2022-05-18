[E. Breaking the Wall](https://codeforces.com/problemset/problem/1674/E)
#数学 #分类讨论 
> 题目大意：
> 给定一个数组a， a[i] 表示 section i具有的durability，每次攻击选定一个section i, 攻击之后a[i - 1] - 1, a[i] - 2, a[i + 1] - 1， 问摧毁两个section(任意位置) 需要的最少攻击次数
~~~c++
/*
i. 三种情况： 
	1.  break two neighboring sections (i and i+1);
	2.  break two sections with another section between them (i and i+2);
	3.  break two sections with more than one section between them
ii.
	1. 直接 (w[i] + 1) / 2， 排序得到前两个最少的(不需要在意相隔距离)
	2. 2a + b = w[i], 2c + b = w[i + 2]， 可得 (a + b + c) = (w[i] + w[i + 2] + 1)/2
	3.  让 x = max(w[i], w[i + 1]), y = min(w[i], w[i + 1]),2a + b = x, 2b + a = y, （a + b) = (x+ y + 2) / 3
	但是， 这里我们需要注意a >= b >= 0, 
	观察临界点，b = 0, 2a = x, a = y, 2y = x,
	如果2y < x，那么 b必须小于0
	那么则有 2 * y >= x
	当2*y >= x时， t = (x +y +2)/3
	当2*y < x时， t = (x + 1) / 2
iii.
上面是偏数学推导的，实际上，还是要记住这样的边界情况
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

const int N = 200010;
const int INF = 1e9;

int T, n;
int w[N];
int f[N], g[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    int ans = 1e9;
    for (int i = 1; i <= n; i ++ ) f[i] = (w[i] + 1) / 2;
    sort(f + 1, f + n + 1);
    ans = min(ans, f[1] + f[2]);

    for (int i = 1; i <= n - 2; i ++ ) {
        int t = (w[i] + w[i + 2] + 1) / 2;
        ans = min(ans, t);
    }

    for (int i = 1; i <= n - 1; i ++ ) {
        int x = max(w[i], w[i + 1]), y = min(w[i], w[i + 1]);
        int t;
        if (2 * y >= x) t = (w[i] + w[i + 1] + 2) / 3;
        else t = (x + 1) / 2;
        ans = min(ans, t);
    }

    cout << ans << endl;
}

int main() {
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
~~~