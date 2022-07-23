[ACW 8. 二维费用的背包问题](https://www.acwing.com/problem/content/8/)
#DP #01背包 #背包问题 #二维费用背包 
>题目大意：
>	一共有n件物品，有一个容量为V， 承重为M的背包。
>	每件物品的体积为v， 重量为m， 价值为w。
>	每一件物品最多只能装一次，求背包能够装的物品的最大价值为？
>提示一：二维费用的背包问题和一维的状态转移基本一致

$$
\begin{aligned}
&f[i][j][k] = max(f[i - 1][j - v][k - m] + w, f[i - 1][j][k])\\
\end{aligned}
$$
>提示二：将三维的优化成二维的思路和将二维的优化成一维的思路是一致的

~~~c++
#include <iostream>

using namespace std; 

const int N = 110; 

int n, V1, V2; 
int f[N][N]; 

int main() {
    cin >> n >> V1 >> V2;
    int v, m, w; 
    for (int i = 0; i < n; i ++ ) {
        cin >> v >> m >> w; 
        for (int j = V1; j >= v; j -- ) {
            for (int k = V2; k >= m; k -- ) {
                f[j][k] = max(f[j][k], f[j - v][k - m] + w); 
            }
        }
    }
    cout << f[V1][V2] << endl; 
    return 0; 
}
~~~