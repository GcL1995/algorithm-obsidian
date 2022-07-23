[A. Mark the Photographer](https://codeforces.com/contest/1705/problem/A)
#贪心 
> 题目大意：照相，将2n个人分成两排，每一排的后一个人都要比前一个人高x。
> 如何排？
> 提示一：当然选择n个最低的人。
> 提示二：这样分两排，然后直接按照顺序来就行。
> 提示三：使用交换法能够证明，这样是最优的。

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
int w[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= 2 * n; i ++ ) cin >> w[i];
    sort(w + 1, w + 2 * n + 1);
    for (int i = 1; i <= n; i ++ ) {
        if (w[i + n] - w[i] < k) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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