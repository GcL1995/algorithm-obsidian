[acwing 算法基础课 模板题](https://www.acwing.com/problem/content/846/)
#BFS #模板题 
~~~c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 110; 

int n, m; 
int g[N][N]; 
int d[N][N]; 

int bfs() {
    memset(d, -1, sizeof d); 
    queue<PII> q; 
    
    d[1][1] = 0; 
    q.push({1, 1}); 
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (q.size()) {
        auto t = q.front(); 
        q.pop(); 
        
        int x = t.first, y = t.second; 
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i]; 
            if (a < 1 || a > n || b < 1 || b > m || g[a][b] == 1) continue;
            if (d[a][b] == -1) {
                d[a][b] = d[x][y] + 1;
                q.push({a, b}); 
            }
        }
    }
    return d[n][m]; 
}

int main() {
    cin >> n; 
    cin >> m; 
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) cin >> g[i][j]; 
    }
    
    cout << bfs() << endl; 
    
    return 0; 
}
~~~

## 周赛
[[WC 263.到达目的地的第二短时间]]
[[WC 269.找出知晓秘密的所有专家]]