# Floyd
#floyd #最短路 
[ACW 854. Floyd求最短路](https://www.acwing.com/problem/content/submission/code_detail/7661439/)
#模板题 
~~~c++
#include <cstring>
#include <iostream>
#include <algorithm>
/*
适用场景：
多源最短路 无负权回路
i. DP证明
ii. f[k][i][j] 表示只经过前k个点，从i到j的最短路
iii. 转移方程
f[k][i][j] = min(f[k - 1][i][j], f[k - 1][i][k] + f[k - 1][k][j]);
*/
using namespace std; 

const int N = 210, INF = 1e9;
int n, m, Q; 
int d[N][N]; 

void floyd() {
    for (int k = 1; k <= n; k ++ ) {
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &Q); 
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            if (i == j) d[i][j] = 0; 
            else d[i][j] = INF; 
        }
    }
    
    while (m -- ) {
        int a, b, c; 
        scanf("%d%d%d", &a, &b, &c); 
        d[a][b] = min(d[a][b], c); 
    }
    
    floyd(); 
    
    while (Q -- ) {
        int a, b; 
        scanf("%d%d", &a, &b); 
        
        int t = d[a][b]; 
        
        if (t > INF / 2) puts("impossible"); 
        else printf("%d\n", t); 
    }
    return 0; 
}
~~~

### 相关题目
[[LC 847. 访问所有节点的最短路径]]
