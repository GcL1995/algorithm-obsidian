[1705C - Mark and His Unfinished Essay](https://codeforces.com/contest/1705/problem/C)
>给定初始字符串str， c次操作，q次询问。
>一次操作(l, r)表示将前一个字符串的l到r位置查到末尾，构成新的字符串。
>一次询问x表示询问最终数组的x位置的字符是什么？
>提示一：所有的字符都是初始字符串中的数字。
>提示二：k次操作增长的字符，可以一一对应到k - 1操作对应的字符。
>提示三：重复提示二，直到确定在提示一中对应的字符。
>提示四：有没有感觉有点像LCA的部分，对比其中的一部分代码[[最近公共祖先-倍增法]]
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
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int>> VII;

const int N = 50, M = 10010;
const int INF = 1e9;

int T, n, c, q;
PLL w[N];
LL query[M];
LL s[N];

void solve() {
   cin >> n >> c >> q;
   string str;
   cin >> str;
   str = " " + str;
   for (int i = 1; i <= c; i ++ ) cin >> w[i].x >> w[i].y;
   for (int i = 1; i <= q; i ++ ) cin >> query[i];
   s[0] = n;
   for (int i = 1; i <= c; i ++ ) s[i] = s[i - 1] + (w[i].y - w[i].x + 1);
   for (int i = 1; i <= q; i ++ ) {
       LL t = query[i];
       int level = c;
       while (level > 0) {
           while (level > 0 && s[level - 1] >= t) level --;
           if (level > 0) {
               LL org = s[level - 1];
               LL l = w[level].x;
               t = t - org + l - 1;
           }
       }
       cout << str[t] << '\n';
   }
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