#### [acwing. 285. 没有上司的舞会](https://www.acwing.com/problem/content/287/)
~~~c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 6010, M = N; 

int n; 
int h[N], e[M], ne[M], idx;
int f[N][2]; //f[i][1]表示 包含 i的树的最大权值 f[i][0] 表示不包含i的树的最大权值
int happy[N]; 
bool has_fa[N]; 

void add(int a, int b)  // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u) {
    f[u][1] = happy[u]; 
    
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i]; 
        dfs(j); 
        
        f[u][1] += f[j][0]; 
        f[u][0] += max(f[j][0], f[j][1]); 
    }
}

int main() {
    cin >> n; 
    
    for (int i = 1; i <= n; i ++ ) scanf("%d", &happy[i]); 
    
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ ) {
        int a, b; 
        scanf("%d%d", &a, &b); 
        add(b, a); 
        has_fa[a] = true;
    }
    
    int root = 0; 
    for (int i = 1; i <= n; i ++ ) {
        root = i; 
        if (!has_fa[i]) break; 
    }
    
    dfs(root); 
    
    printf("%d", max(f[root][0], f[root][1]));
}
~~~

## 相关题目
[[LC 968. 监控二叉树]]
[[WC 289. 相邻字符不同的最长路径]]