[AcWing 10. 有依赖的背包问题](https://www.acwing.com/problem/content/10/)
#DP #有依赖的背包问题 #树形DP #分组背包 #分组背包问题
> 题目大意：
> 	n个物品构成一个树，一个容量为m的背包，如果要背一个物品，那么必须要背这个物品的根。
> 	求如何选择物品能够使得背包的价值最大，最大价值为多少？
> 提示一：一个典型的树形DP。同时是一个背包问题。
> 提示二：如何定义状态，似乎是一个比较明显的f(i, j)表示以i为根的子树，最大价值为多少？
> 提示三：状态转移方程如何写？一个儿子就是一组这样构成分组背包问题，与通常的分组背包问题的不同之处在哪里？必须要留v[u]来放当前节点。

$$
\begin{aligned}
&for \;su \;in \;son[u]:\\
&f[u][j] = max(f[u][j], f[u][k] + f[su][j - k])
\end{aligned}
$$
>提示四：提示三中的式子没有考虑放入当前节点，那么如何把当前节点考虑进去？平移提示三中得到的值即可。具体见代码。

~~~c++
#include <iostream>
#include <cstring>

using namespace std; 

const int N = 110; 

int n, m; 
int v[N], w[N], f[N][N]; 
int e[N], ne[N], h[N], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++; 
}

void dfs(int u) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int son = e[i]; 
        dfs(son); 
        for (int j = m - v[u]; j >= 0; j -- ) {
            for (int k = 0; k <= j; k ++ ) f[u][j] = max(f[u][j], f[u][k] + f[son][j - k]); 
        }
    }
    for (int j = m; j >= v[u]; j -- ) f[u][j] = f[u][j - v[u]] + w[u]; 
    for (int j = 0; j < v[u]; j ++ ) f[u][j] = 0; 
}

int main() {
    cin >> n >> m; 
    int root; 
    
    int p;     
    memset(h, -1, sizeof h); 
    for (int i = 1; i <= n; i ++ ) {
        cin >> v[i] >> w[i] >> p; 
        if (p == -1) root = i; 
        else add(p, i); 
    }
    
    dfs(root); 
    cout << f[root][m] << endl; 
    
    return 0; 
}
~~~