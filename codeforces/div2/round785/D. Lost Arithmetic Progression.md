[D. Lost Arithmetic Progression](https://codeforces.com/contest/1673/problem/D)
#数学 #等差数列 #最大公约数 
> 题目大意：
> 	两个等差数列A，B 相交得到等差数列C。
> 	现在已知B和C的所有元素，求满足条件的所有A的可能情况个数
~~~c++
/*
i. 两个等差数列的交集如果大于两个数必然为另一个等差数列，且该等差数列的d = d1 * d2 / gcd(d1, d2)， 也就是d是d1 和 d2 的最小公倍数
ii. 如果B和C没有交集，那么ans = 0
iii. 如果C的左右边界没有限制，那么ans = -1， 所谓的没有限制，按我的写法也就是r2 + y > r1, l2 - y < l1满足其中一个
iv. 当C的左右边界有限制，也就是他必然不能取到r2 + y 和 l2 - y时，那么我们可以遍历y的所有因子，如果一个因子设为i， 如果i * b = y * gcd(i, b),那么A的等差数列的差值为i的所有可能性为 (y / i) ^ 2
v. 注意long long
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

const int N = 200010, mod = 1e9 + 7;
const int INF = 1e9;

int T, n;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    LL a, b, c;
    LL x, y, z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    if (y % b != 0) { //非倍数
        cout << 0 << endl;
        return;
    }

    LL l1 = a, r1 = a + b * (c - 1);
    LL l2 = x, r2 = x + y * (z - 1);
    if (l2 < l1 || r2 > r1) { // 2范围大
        cout << 0 << endl;
        return;
    }
    if ((r2 - l1) % b != 0) { // 不包含
        cout << 0 << endl;
        return;
    }
    if (l1 == l2 || r2 == r1) { // 边界
        cout << -1 << endl;
        return;
    }


    if (r2 + y > r1 || l2 - y < l1) { // 差一个数特殊情况
        cout << -1 << endl;
        return;
    }

    LL ans = 0;
    for (int i = 1; i <= y / i; i ++ ) {
        if (y % i == 0) {
            //printf("%d %d %d %d\n", i, b, gcd(i, b), y);
            if ((LL) i * b == gcd(i, b) * y) {
                //printf("debug %d %d %d\n", y, b, i);
                ans = (ans + (LL)(y / i) * (y / i)) % mod;
            }
            if (i != y / i) {
                int j = y / i;
                if ((LL) j * b == gcd(j, b) * y) {
                    //printf("debug %d %d %d\n", y, b, i);
                    ans = (ans + (LL)(y / j) * (y / j)) % mod;
                }
            }
        }
    }
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