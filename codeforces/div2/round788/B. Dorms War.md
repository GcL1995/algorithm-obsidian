[B. Dorms War](https://codeforces.com/contest/1670/problem/B)
> 题目大意：
>  一个01字符串， 一次操作每个1前面的字符都会消失
>  问多少次操作之后，字符串的操作不会发生变化
~~~c++
/*
i. 如果只考虑只有一个1的字符串情况，那么操作次数就是这个1前面的0的个数
ii. 如果考虑多个1， 那么将字符串分为00001， 1, ....，也就是每个子字符串的最后一个字符都是1， 且只包含一个1
iii. 可以将每个子字符的第一个0之前字符当做一个字符，那么res = max(res, curr + 1)
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
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

int T, n, k;
bool st[26];

void solve() {
    cin >> n;
    string w;
    cin >> w;
    w = " " + w;
    cin >> k;
    memset(st, 0, sizeof st);

    for (int i = 1; i <= k; i ++ ) {
        char c;
        cin >> c;
        st[c - 'a'] = true;
    }

    int pre = 0, res = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (st[w[i] - 'a']) {
            int curr = i - pre - 1;
            if (pre == 0) res = max(res, curr);
            else res = max(res, curr + 1);
            pre = i;
        }
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
~~~