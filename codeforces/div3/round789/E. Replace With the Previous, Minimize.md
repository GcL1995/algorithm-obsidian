[E. Replace With the Previous, Minimize](https://codeforces.com/contest/1675/problem/E)
#构造题
>
题目大意：
> 长度为n的字符串，每次可以将其中的相同字符，全部减一，最多操作k次，求操作后字典序最小的结果为？
#贪心 
~~~c++
/*
i. 只需要维护最多两个区间， 存在于这两个区间中的所有数，都可以free变为区间左端点
ii. 第一个区间左端点一定为'a', 产生第二个区间之后，k值一定变为0
iii. 从左到右，贪心处理
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

int T, n, k;
char w[N];
char g[N];

void solve() {
    cin >> n >> k;
    scanf("%s", w + 1);
    char st1 = 'a', ed1 = 'a', st2 = 'a', ed2 = 'a';
    for (int i = 1; i <= n; i ++) {
        if (st1 <= w[i] && w[i] <= ed1) w[i] = st1;
        if (st2 <= w[i] && w[i] <= ed2) w[i] = st2;
        if (k == 0) continue;

        int minus = min(w[i] - 'a', k);
        char c = w[i] - minus;
        //printf("before %c %c\n", w[i], c);
        if (c <= ed1) {
            c = ed1;
            minus = max(w[i] - c, 0);
            ed1 = max(ed1, w[i]);
            k -= minus;
            w[i] = st1;
        } else if (minus != 0){
            st2 = c;
            ed2 = w[i];
            k = 0;
            w[i] = c;
        }
        //printf("%d %c %c %c %c %c\n", i, w[i], st1, ed1, st2, ed2);
    }
    printf("%s\n", w + 1);
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
~~~