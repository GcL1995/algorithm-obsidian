> 深度优先搜索
> i. 使用深度优先搜索的问题，意味着我们将暴力搜索的过程转化为一个搜索树， 叶子节点意味着答案
> ii. 通常我们会使用点来判重， 这样意味着每个点的每条边只会被扩展一次，那么时间复杂度就是o(n + m)
> iii. 我比较习惯于在dfs之前更改状态。
## 小猫爬山
#DFS 
[acwing 165](https://www.acwing.com/problem/content/description/167/)
~~~c++
#include <iostream>

using namespace std; 

const int N = 20; 

int n, m; 
int w[N], sum[N]; 
int ans = N; 

void dfs(int u, int k) { //当前匹配到第u个猫，使用到的小车数量为k
    if (u == n) {
        ans = min(ans, k); 
        return; 
    }
    
    if (k >= ans) return; // 剪枝
    
    sum[k] = w[u];  //加个新车
    dfs(u + 1, k + 1); 
    sum[k] = 0; 
    
    for (int i = 0; i < k; i ++ ) { // 用旧车
        if (sum[i] + w[u] <= m) {
            sum[i] += w[u]; 
            dfs(u + 1, k); 
            sum[i] -= w[u]; 
        }
    }
}

int main() {
    cin >> n >> m; 
    
    
    for (int i = 0; i < n; i ++ ) {
        cin >> w[i]; 
    }

    dfs(0, 0); 
    
    cout << ans << endl;
}
~~~

## 周赛
[[WC 266.最大化一张图中的路径价值]]
[[BiC 64. 棋盘上有效移动组合的数目]]

