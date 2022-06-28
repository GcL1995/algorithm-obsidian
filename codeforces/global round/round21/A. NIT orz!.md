[A. NIT orz!](https://codeforces.com/problemset/problem/1696/A)
#构造题 
> 题目大意：
> 	一个大小为n的数组a，给定一个数z，可以执行下列操作n次。
> 	选择一个小标i， 让下面两个赋值同时发生，a[i] = a[i] | z, z = a[i] & z。
> 求问经过任意次操作之后，数组中的最大值最大是多少？
> 提示一：每一次操作，都只会让a[i]变大或者不变。
> 提示二：z每一次都会变小，而且，位数为0的不会变成1.
> 提示三：结合一二，只有第一次操作会将a[i]变大。接下来对a[i]的每一次操作，a[i]都不会变。

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

const int N = 200010;
const int INF = 1e9;

int T, n, m, k;
int w[N];

void solve() {
    int z;
    cin >> n >> z;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) ans = max(ans, w[i] | z);
    cout << ans << '\n';
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