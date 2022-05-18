[C. Palindrome Basis](https://codeforces.com/contest/1673/problem/C)
#回文数 #完全背包 #DP 
> 题目大意：
> 对于给定的n，分解为回文数的和的总方案数。(存在一个数字频率不同即为不同方案)
~~~c++
/*
i. n <= 4 * 10 ^ 4， 可以求得所有小于等于该数的回文数
ii. 这样问题转换为一个完全背包问题 求方案数
iii. 转换方程为：
f[i][j] = sum(f[i - 1][j - k * w[i]]) ( 0 <= k * w[i] <= j)
空间优化到一维的情况下：
则有f[j] = f[j] + f[j - w[i]]， j从w[i] 到 m正序遍历
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

const int N = 40010, mod = 1e9 + 7;
const int INF = 1e9;

int T, n, m;
vector<int> w;
int f[N];

int init = []() {
    LL left = 1;
    bool flag = true;
    while (flag) {
        LL right = left * 10;

        for (int op = 0; op < 2; op ++ ) {
            for (LL i = left; i < right; i ++ ) {
                LL x = (op == 0 ? i / 10: i);
                LL comb = i;
                while (x) {
                    comb = comb * 10 + x % 10;
                    x /= 10;
                }
                if (comb > 1e5) {
                    flag = false;
                    break;
                }
                w.push_back(comb);
            }
            if (!flag) break;
        }
        left = right;
    }
    m = w.size();
    f[0] = 1;
    for (int i = 0; i < m; i ++ ) {
        for (int j = w[i]; j < N; j++) {
            f[j] = ((LL)f[j] + f[j - w[i]]) % mod;
        }
    }
    return 1;
}();

void solve() {
    cin >> n;
    cout << f[n] << endl;
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
~~~