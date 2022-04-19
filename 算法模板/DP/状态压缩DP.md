# 状态压缩DP
## 男女匹配
#状态压缩 #DP
~~~c++
/*
题目地址
https://leetcode-cn.com/problems/maximum-and-sum-of-array/
https://atcoder.jp/contests/dp/tasks/dp_o
https://atcoder.jp/contests/abc199/tasks/abc199_e
https://codeforces.com/problemset/problem/1215/E
https://codeforces.com/problemset/problem/743/E
https://codeforces.com/problemset/problem/744/C
https://codeforces.com/problemset/problem/377/C
https://codeforces.com/problemset/problem/327/E
*/

/*
状态压缩DP：
f[i] 
集合：前bit_count(i)位女生，匹配的男生是i的二进制中1的位数
集合属性：数量

这里关键是明确情况i代表的集合是什么样的集合

*/

#include <iostream>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
typedef long long LL; 
 
const int N = 25, mod = 1e9 + 7;
 
int n; 
int g[N][N]; // g[i][j] == 1 表示男生i和女生j匹配
LL f[1 << N]; 
 
 
int main() {
    cin >> n; 
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) cin >> g[i][j]; 
    }

    f[0] = 1; // f[0] = 1 表示初始状态有效
    for (int i = 0; i < 1 << n; i ++ ) {
        int c = 0; 
        for (int j = 0; j < n; j ++ ) c += i >> j & 1; //计算i 当前匹配第c个女生(c 可以等于0 )
        for (int j = 0; j < n; j ++ ) {
            if (i >> j & 1) continue; // 第j个男生不能已经匹配
            if (g[j][c]) f[i | 1 << j] = (f[i | 1 << j] + f[i]) % mod; //第j个男生匹配第c个女生
        }
    }
    
    cout << f[(1 << n) - 1] << endl;
    
    return 0; 
}
~~~


## 满足要求的排列
#状态压缩 #DP

~~~c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> PII; 
typedef long long LL; 

const int N = 20; 

int n, m; 
unordered_map<int, vector<PII>> condi; 
LL f[1 << N]; 

bool check(int i, int c) {
    for (auto [y, z]: condi[c + 1]) {
        int cnt = 0; 
        for (int j = 0; j < y; j ++ ) {
            cnt += i >> j & 1;
        }
        if (cnt > z) return false; 
    }
    return true; 
}

/*
f[i] 表示 数字i的二进制中1的位数的数字的 满足条件的所有排列
这样状态更新只需要关注下一个位数的条件即可
*/
int main() {
    cin >> n >> m; 
    for (int i = 0; i < m; i ++ ) {
        int x, y, z;
        cin >> x >> y >> z;
        condi[x].push_back({y, z}); 
    }
    
    f[0] = 1;
    for (int i = 0; i < 1 << n; i ++ ) {
        int c = 0; 
        for (int j = 0; j < n; j ++ ) c += i >> j & 1;
        
        for (int j = 0; j < n; j ++ ) {
            if (i >> j & 1) continue;
            if (check(i | 1 << j, c)) f[i | 1 << j] += f[i];
        }
    }
    cout << f[(1 << n) - 1] << endl; 
    
    return 0; 
}
~~~

## 相关题目
[[LC 1879. 两个数组最小的异或值之和]]
## 周赛
[[WC 280. 数组的最大与和]]
