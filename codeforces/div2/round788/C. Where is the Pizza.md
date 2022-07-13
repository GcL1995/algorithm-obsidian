[C. Where is the Pizza?](https://codeforces.com/contest/1670/problem/C)
#并查集 
> 题目大意：
> 	两个n的排列，a 和 b
> 	求问可以构造出多少中排列c，满足
> 	c[i] == a[i] || c[i] == b[i]
> 提示一：记不记得b站上看的那个脑筋急转弯？[反直觉智力题](https://www.bilibili.com/video/BV1kt4y1t75F?spm_id_from=333.880.my_history.page.click&vd_source=1eed22760e8996911978e95be02bb5f2)
	提示二：a和b中每个元素可以向外连两条边，一个是a[i]和b[i]相连，一条是a[i] == b[j]，那么a[i]和b[j]相连。这样必然形成多个欧拉环。这个和提示一是否也有联系呢？
	提示三：提示二中的一个欧拉环的元素，要满足构造出来序列的性质，意味着要么全选a要么全选b。
	提示四：使用并查集，如果最终元素数量大于1的并查集数目为p。res = 2^p
~~~c++
/*
i. 如果a, b中的几个元素单独构成一个permutation且删除掉任何一个元素都不构成，那么这几个元素要么同属于a要么同属于b
ii. 可以通过并查集将这些元素计算出来
iii. 如果d全为0，那么res=2^p, p为并查集的集合数量
iv. 如果d不等于0，那么这几个元素只能选择ab中的一个
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
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
const int mod = 1e9 + 7;

int T, n;
int a[N], b[N], d[N];
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) cin >> b[i];
    for (int i = 1; i <= n; i ++ ) cin >> d[i];
    for (int i = 0; i <= n; i ++ ) p[i] = i;
    for (int i = 1; i <= n; i ++ ) {
        int x = find(a[i]), y = find(b[i]);
        if (x != y) p[x] = y;
    }
    unordered_set<int> S1, S2;
    for (int i = 1; i <= n; i ++ ) {
        if (a[i] != b[i]) S1.insert(find(a[i]));
        if (d[i] != 0 && a[i] != b[i]) S2.insert(find(d[i]));
    }

    LL res = 1;
    int cnt = S1.size() - S2.size();
    while (cnt -- ) res = 2 * res % mod;
    cout << res << endl;
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
~~~