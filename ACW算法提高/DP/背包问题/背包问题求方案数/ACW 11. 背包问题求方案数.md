[ACW 11. 背包问题求方案数](https://www.acwing.com/problem/content/11/)
#DP #01背包 #背包问题求方案数 
> 题目大意：
> 	经典01背包问题， N物品， V体积背包，一个物品的体积是v[i], 价值是w[i], 每件物品最多选一次，问总体积不超过背包容量且总价值最大的方案数？
> 提示一：01背包， 该问题与[[ACW 278. 数字组合]] [[ACW 532. 货币系统]]的区别。
> 提示二：如何定义状态？f(i, j) 表示前i件，体积恰好为j的最大值。g(i, j) 表示前i件体积j且价值为f(i, j)的方案数。  ***注意这里f(i, j)的定义是恰好体积为j***
> 提示三：如何状态转移？f(i, j) 当然同经典的01背包问题相同，即使加了恰好也一样。
> 					g(i, j) 的话要看f(i, j) 是从哪里转移过来的，f(i - 1, j) 还是f(i - 1, j - v)。
> 提示四：如何根据f和g数组获得最终的方案数呢？注意恰好定义即可。

~~~c++
#include <iostream>
#include <cstring>

using namespace std; 

const int N = 1010, mod = 1e9 + 7; 

int n, m; 
int f[N], g[N]; 

int main() {
    memset(f, -0x3f, sizeof f); 
    f[0] = 0; 
    g[0] = 1; 
    
    cin >> n >> m; 
    int v, w; 
    for (int i = 0; i < n; i ++ ) {
        cin >> v >> w; 
        for (int j = m; j >= v; j -- ) {
            int maxv = max(f[j], f[j - v] + w); 
            int cnt = 0; 
            if (f[j] == maxv) cnt += g[j];
            if (f[j - v] + w == maxv) cnt += g[j - v]; 
            f[j] = maxv; 
            g[j] = cnt % mod;  
        }
    } 
    
    int res = 0; 
    for (int i = 0; i <= m; i ++ ) res = max(res, f[i]); 
    int cnt = 0; 
    for (int i = 0; i <= m; i ++ ) if (f[i] == res) cnt = (cnt + g[i]) % mod; 
    cout << cnt << endl; 
    
    return 0; 
}
~~~