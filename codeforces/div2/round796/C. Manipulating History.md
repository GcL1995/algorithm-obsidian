[C. Manipulating History](https://codeforces.com/contest/1688/problem/C)
#构造题 
> 题目大意：
> 	一个字符串刚开始有一个字母，后续每次变化，可以选择当前字符串的一个子字符串，改变为任意一个子字符串。
> 	现在将变化过程中的子字符串打乱，并给定最终的字符串，求问刚开始的字符串是什么？
> 提示一：
> 	一个字符，如果最后不在最终字符串中，那么必然存在一个strwithc ---> strnoc
> 提示二：
> 	一个字符，如果最终在字符串，必然存在strnoc ----> strwithc
> 提示三：
> 	除了第一个字符，其他字符必然出现偶数次。
> 	strnoc---> strcwithc strcwithc ----> strcnoc
> 	strnoc---> strcwithc + final with c
> 提示四：
		第一个字符出现奇数次。
		c ---> strnoc  + final noc  			
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

int T, n, m;
int w[N];

void solve() {
    cin >> n;
    map<char, int> cnt;
    for (int i = 0; i <= 2 * n; i ++ ) {
        string str;
        cin >> str;
        for (auto &x: str) {
            cnt[x]  ++;
        }
    }
    for (auto &e: cnt) {
        if (e.y % 2) {
            cout << e.x << endl;
            return;
        }
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