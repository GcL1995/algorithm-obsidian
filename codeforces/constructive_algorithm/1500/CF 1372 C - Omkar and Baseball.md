[CF 1372 C - Omkar and Baseball](https://codeforces.com/problemset/problem/1372/C)
#构造题 
> 题目大意：
> 给定一个1-n的permutation，判断最少几次special exchange能够将排列转化为identity permutation
> special exchange：choose any subarray of the scores and permute elements such that no element of subarray gets to the same position as it was before the exchange.
> （选定一个子数组，exchange之后的子数组中的所有元素和原来的元素不在同一个位置).
~~~c++
/*
i. 0和1的情况是最好判断的
如果已经是一个identity permutation那么是0
如果所有与identity permutation位置不同的元素在一个连续区间上，那么是1
ii. 不会有超过2的情况，也就是说其他情况都可以构造出来一个中间排列p，该中间排列可以special exchange 到 原排列 a，也可以special exchange 到 identity permutation.
现在构造这个中间排列：
假设n是偶数：
那么首先分为两半，1-n/2 放在右半区间，n/2-n放在左半区间，这样能够保证，该permutation一次special exchange既可以到identity permutation。
其次 如果 p[i]在原排列和p排列中在同一个半区，那么就让p[i] = a[i]，也就是放在同一个位置，然后做一个旋转，这样能保证a和p所有元素都不在同一个位置。

如果n是奇数，那么类似的我们可以构造出来一个中间permutation，这个把偶数放在奇数位置，奇数放在偶数位置，与上述类似的，如果一个元素在a和p中在同一半区(奇数半区或者偶数半区)，那么就把它们放在同一个位置，然后做一次旋转即可。
可以看到n数的奇数的证明可以直接证明所有的情况，只不过分为左右半区是很容易想到的，分为奇数和偶数半区是不容易想到的。
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

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    bool flag = true;
    for (int i = 1; i <= n; i ++ ) {
        if (w[i] != i) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << 0 << endl;
        return;
    }

    int i = 0, j = n + 1;
    while (i + 1 <= n && w[i + 1] == i + 1) i ++;
    while (j - 1 >= 1 && w[j - 1] == j - 1) j --;
    for (int k = i + 1; k < j; k ++ ) {
        if (w[k] == k) {
            cout << 2 << endl;
            return;
        }
    }

    cout << 1 << endl;

}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
~~~