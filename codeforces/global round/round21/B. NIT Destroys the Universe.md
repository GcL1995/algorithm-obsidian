[B. NIT Destroys the Universe](https://codeforces.com/problemset/problem/1696/B)
>题目大意：
>	一个长度为n的数组a, 每次操作可以选取两个下标 l, r。 l < r， a[i] = mex(a[l - r]) (l <= i <= r)
>	求问将数组元素全变为0需要的最少操作数。
>提示一：
>	如果所有元素都没有0，那么可以直接选l = 1, r = n,那么将所有的数变为0
>提示二：
>	如果存在数组元素为0， 那么一次操作可以实现提示一：l = 1, r = n，那么所有的数都将变为一个大于0的数。
>提示三：
>	提示一和提示二结合，可以得到答案最多为2
>提示四：
>	小于2的情况？0或者1
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
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    int i = 1;
    while (i <= n && w[i] == 0) i ++;
    if (i == n + 1) {
        cout << 0 << endl;
        return;
    }
    int j = n;
    while (j >= 1 && w[j] == 0) j --;
    for (int k = i; k <= j; k ++ ) {
        if (w[k] == 0) {
            cout << 2 << endl;
            return;
        }
    }
    cout << 1 << endl;
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