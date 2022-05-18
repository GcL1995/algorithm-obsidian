[C. Detective Task](https://codeforces.com/contest/1675/problem/C#)
#构造题 
> 题目大意：
> n个人分别参观，其中一个人偷了东西，分别回答是否看到该物品，0 1 ？
> 求可能是小偷的人数
~~~c++
/*
i. 最后一个1之前的所有数都不可能是小偷
ii. 第一个0之后的都不能是小偷
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
    string str;
    cin >> str;
    n = str.size();
    str = " " + str;
    int one = 0;
    for (int i = 1; i <= n; i ++ ) if (str[i] == '1') one = i;
    int zero = 0;
    for (int i = one + 1; i <= n; i ++ ) if (str[i] == '0') {
            zero = i;
            break;
    }
    if (one == 0 && zero == 0) {
        cout << n << endl;
        return;
    }
    if (zero == 0) {
        cout << n - one + 1 << endl;
        return;
    }
    if (one == 0) {
        cout << zero << endl;
        return;
    }
    cout << zero - one + 1 << endl;
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
~~~