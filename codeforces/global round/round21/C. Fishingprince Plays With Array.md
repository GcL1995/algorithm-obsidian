[C. Fishingprince Plays With Array](https://codeforces.com/problemset/problem/1696/C)
> 题目大意：
> 	一个长度为n的数组a， 给定一个数m。一个长度为k的数组b。
> 	可以使用下列两个操作：
> 	操作1：选择一个m的倍数a[i], 将a[i]扩增为m个a[i] / m
> 	 操作2：选择m个连续相同的数字a[i ~ i + m - 1], 将这m个数合并为一个数
> 	 问能否通过一系列变化，将a最终变成b
> 提示一：
> 	操作1和2互为逆操作
> 提示二：
> 	根据提示一，如果数组可以变成b，那么b也可以变成a
> 提示三：
> 	根据提示二，只需要找个中间数组a和b都可以变过去就可以。
> 提示四：
> 	扩增或者压缩数组。扩增数组更好实现一些。
> 提示五：
> 	具体实现的问题，扩增之后，用PII存储，x表示值，y表示数量
> 提示六：
> 	具体实现的问题，提示五扩增之后，将相同元素合并，更便于比较。
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
typedef pair<LL, LL> PII;
typedef pair<double, double> PDD;
typedef unsigned long long ULL;

const int N = 50010;
const int INF = 1e9;

int T, n, m, k;
int w[N], g[N];

vector<PII> merge(vector<PII>& ori) {
    vector<PII> res;
    int n = ori.size();
    for (int i = 0; i < n; ) {
        int j = i;
        PII curr = {ori[i].x, ori[i].y};
        while (j + 1 < n && ori[j + 1].x == ori[i].x) {
            j ++;
            curr = {curr.x, ori[j].y + curr.y};
        }
        res.push_back(curr);
        i = j + 1;
    }
    return res;
}

bool solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    vector<PII> pw;
    for (int i = 1; i <= n; i ++ ) {
        int x = w[i], v = 1;
        while (x % m == 0) {
            x /= m;
            v *= m;
        }
        pw.push_back({x, v});
    }


    cin >> k;
    vector<PII> pg;
    for (int i = 1; i <= k; i ++ ) cin >> g[i];
    for (int i = 1; i <= k; i ++ ) {
        int x = g[i], v = 1;
        while (x % m == 0) {
            x /= m;
            v *= m;
        }
        pg.push_back({x, v});
    }

    vector<PII> fw = merge(pw), fg = merge(pg);
    if (fw.size() != fg.size()) return false;
    for (int i = 0; i < fw.size(); i ++ ) {
        if (fw[i] != fg[i]) return false;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    T = 1;
    cin >> T;
    while (T--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
~~~