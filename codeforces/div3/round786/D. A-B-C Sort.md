[D. A-B-C Sort](https://codeforces.com/contest/1674/problem/D)
#构造题 #找规律
> 题目大意： 
> 给定一个数组A， 
> 首先将A转化为数组B，可以简述为结尾元素放到B数组的中间end->middle
> 然后将B转化为数组C，可以简述为中间元素放到C数组的结尾， middle -> end
~~~c++
/*
i.不能一个一个元素的思考，必须成对思考
ii. (a[n - 1], a[n]) -> 一定在B数组的两边 -> 一定在C数组的结尾
iii. (a[n - 2 * k - 1], a[n - 2 * k]) 在C数组的对应位置，或者交换之后的位置
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
int b[N], c[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    for (int i = 1; i <= n; i ++ ) c[i] = w[i];
    sort(c + 1, c + n + 1);
    int t = 0;
    if (n % 2 == 1) {
        if (w[1] != c[1]) {
            cout << "NO" << endl;
            return;
        }
        t = 1;
    }
    for (int i = t + 1; i <= n; i += 2) {
        if (w[i] == c[i] && w[i + 1] == c[i + 1] || w[i] == c[i + 1] && w[i + 1] == c[i]) continue;
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
~~~