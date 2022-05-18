
[Round785 B. A Perfectly Balanced String?](https://codeforces.com/contest/1673/problem/B)
#贪心 
> 对于给定的字符串，判断字符串是否为balanced string
> balanced string: 对于任意的区间，区间中两个数字(可以不在该区间，但在字符串中)出现的频率相差均在1以内
~~~c++
/*
i. 如果有k个不同的元素，那么一个balanced string必须是一个所有k长度区间必须所有元素都不同的string
ii. 必要性： 如果有一个k区间有两个数相同记为u，根据抽屉原理，必然有一个数记为v没有出现，那么f("", u, v) = 2,矛盾
iii. 充分性：
	如果所有的k区间数字都不同，那么意味着s[u] = s[u - k]， string是一个k循环的string，那么区间第一个字母必然是出现最多的字母，其余字母要么相等，要么比该次数少一次
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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

int T, n;
string str;

void solve() {
    cin >> str;
    n = str.size();
    set<char> S;
    int k = 0;
    for (;k < n; k ++ ) {
        if (S.find(str[k]) == S.end()) S.insert(str[k]);
        else break;
    }
    for (int i = k; i < n; i ++ ) {
        if (str[i] != str[i - k]) {
            cout << "NO" << endl;
            return;
        }
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