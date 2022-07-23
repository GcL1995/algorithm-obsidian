[D. Mark and Lightbulbs](https://codeforces.com/contest/1705/problem/D)
>题目大意：给定两个01字符串s和t。
>每一次操作选定一个位置，该位置必须左右两个字符不同，然后改变该位置数字。
>也就是说
	-   Select an index ii from 2,3,…,n−1 such that s[i - 1] ≠s[i+1].
	-   Toggle s[i]. Namely, if s[i] is 0, set s[i] to 1 or vice versa.
> 求问经过多少步操作可以将s转化为t。
>提示一：观察01和10的数量。可以发现他们的总数量是不变的。
>提示二：起点和终点的位置当然是不能变的。
>提示三：提示一用数学的语言来说就是说和前一个异或值是1的位置个数是固定的。
>提示四：每次改变等价于交换1的相邻的0的位置。
>提示五:  设异或值之后1的位置记录在s和e中。那么sum(s[i] - e[i]).

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

void solve() {
    cin >> n;
    string s, e;
    cin >> s >> e;
    s = " " + s;
    e = " " + e;
    if (s[1] != e[1] || s[n] != e[n]) {
        cout << "-1\n";
        return;
    }
    vector<int> start, end;
    for (int i = 2; i <= n; i ++ ) {
        int t = (s[i] - '0') ^ (s[i - 1] - '0');
        if (t == 1) start.push_back(i);
        t = (e[i] - '0') ^ (e[i - 1] - '0');
        if (t == 1) end.push_back(i);
    }
    if (start.size() != end.size()) {
        cout << "-1\n";
        return;
    }
    LL ans = 0;
    for (int i = 0; i < start.size(); i ++ ) ans += abs(start[i] - end[i]);
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