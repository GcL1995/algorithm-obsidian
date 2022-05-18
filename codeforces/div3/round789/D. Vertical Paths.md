[D. Vertical Paths](https://codeforces.com/contest/1675/problem/D)
#构造题 #向上标记法
> 题目大意：
> 一棵树，给出包含所有节点的不相交路径的最小值

~~~c++
/*
i. 找出叶子节点
ii. 向上标记法求路径
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
int p[N];
bool leaf[N], st[N];

void solve() {
    cin >> n;
    if (n == 1) {
        cin >> p[1];
        cout << 1 << endl << 1 << endl << 1 << endl << endl;
        return;
    }
    memset(leaf, 0, sizeof leaf);
    memset(st, 0, sizeof st);
    for (int i =1; i <= n; i ++ ) cin >> p[i];
    for (int i = 1; i <= n; i ++ ) {
        leaf[p[i]] = true;
    }
    int m = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (!leaf[i]) m ++;
    }
    cout << m << endl;
    for (int i = 1; i <= n; i ++ ) {
        if (!leaf[i]) {
            vector<int> res;
            int j = i;
            while (!st[j]) {
                res.push_back(j);
                st[j] = true;
                j = p[j];
            }

            cout << res.size() << endl;
            for (int j = res.size() - 1; j >= 0; j -- ) cout << res[j] << ' ';
            cout << endl;
        }
    }

    cout << endl;
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
~~~
[[F. Vlad and Unfinished Business]]