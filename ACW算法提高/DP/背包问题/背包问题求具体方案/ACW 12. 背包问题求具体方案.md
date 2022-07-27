[ACW 12. 背包问题求具体方案](https://www.acwing.com/problem/content/12/)
#DP #背包问题求具体方案 #01背包 
> 题目大意：经典01背包问题，求具体方案。
> 	也就是N个物品，V体积背包，一个物品最多选一次。 每个物品体积为v[i], 价值为w[i]。求字典序最小的具体方案。
> 提示一：把01背包问题看成最短路问题，就看是从哪个点转移过来的。
> 				f(i, j) = max(f(i - 1, j) + f(i - 1, j - v[i]) +w[i])
> 				也就是这个转移有限选择右边的。
> 提示二：与[[ACW 1013. 机器分配]]中求方案类似。我们也需要确定最终的终点，然后一个一个往前推。但是这样倒退求解的话，我们无法确定字典序最小的路径，因为不确定选择当前点是字典序更小还是不选择当前点字典序更小。
> 提示三：如何选择字典序最小的方案呢？其实只要倒着做DP就可以了，这样每次都可以优先选择当前节点。

## 逆推DP
~~~c++
#include <iostream>

using namespace std; 

const int N = 1010; 

int n, m; 
int v[N], w[N], f[N][N]; 

int main() {
    cin >> n >> m; 
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i]; 
    for (int i = n; i >= 1; i -- ) {
        for (int j = m; j >= 0; j -- ) {
            if (j >= v[i]) f[i][j] = max(f[i + 1][j], f[i + 1][j - v[i]] + w[i]); 
            else f[i][j] = f[i + 1][j]; 
        }
    }
    
    int ca = m; 
    for (int i = 1; i <= n; i ++ ) {
        if (ca >= v[i] && f[i][ca] == f[i + 1][ca - v[i]] + w[i]) {
            printf("%d ", i); 
            ca -= v[i]; 
        }
    }
}

~~~