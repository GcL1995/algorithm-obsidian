[C. Zero Path](https://codeforces.com/problemset/problem/1695/C)
> 题目大意：
> 	n * m个格子，每个格子是1或者-1， 从（1， 1）走到（n, m) 每次向下或者向右走一个格子，存不存在一条路径和为0的路径？
> 提示一：n + m必须是奇数
> 提示二：走到(n, m)的路径和最大值-最小值必须包含0
> 提示三：提示二是充分必要条件
> 证明：使用R和D分别表示向右走，必然存在两条路径分别满足最大值和最小值，交换路径的两个相邻点仍然是一条合法路径，且两条路径和差值为2或者0或者-2。
> 通过交换将最大值变为最小值，中间必然有一条合法路径的和为0。
#DP #数学 
~~~c++
#include <iostream>
#include <cstring>

using namespace std; 

const int N = 1010, INF = 1e9; 

int T, n, m; 
int w[N][N], mx[N][N], mn[N][N];

int init = []() {
    for (int i = 0; i < N; i ++ ) mx[i][0] = -INF, mx[0][i] = -INF, mn[i][0] = INF, mn[0][i] = INF;
    mx[1][0] = 0;
    mn[1][0] = 0; 
    return 0;
}();

void solve(int t) {
    cin >> n >> m; 
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) cin >> w[i][j]; 
    }
    if ((n + m) % 2 == 0) {
        cout << "NO\n";
        return; 
    }

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) + w[i][j];
            mn[i][j] = min(mn[i - 1][j], mn[i][j - 1]) + w[i][j];
        }
        
    }
    if (mx[n][m] >= 0 && mn[n][m] <= 0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    cin >> T; 
    for (int t = 1; t <= T; t ++ ) {
        solve(t); 
    }
}
~~~