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

