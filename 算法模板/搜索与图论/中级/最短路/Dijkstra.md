# dijkstra
#最短路 
#### [850. Dijkstra求最短路 II](https://www.acwing.com/problem/content/description/852/)
~~~c++
/*
i. dijkstra 算法 的适用性----非负权图
ii. 
命题：算法进行到第k步时，visited_Set中的每个节点visited[i]的dist[visited[i]]等于全局最短路径short[visited[i]]

(第n步时，dist[visited[n]]=short[visited[n]]，此时找到点1到所有点的最短距离)

数学归纳法 + 反证法：
k = 1 set = {start}, dist[start] = 0命题成立
...
k = i 命题成立
k = i + 1时，假设命题不成立，不妨设第i + 1新加入的点为v， dist[v] > short[v]
不妨设路径中最后一个在visited_set中的点为a, 第一个不在visited_set中的点为b
因为 dist[b] <= short[v] < dist[v] 所以b一定比v先入队， 产生矛盾


iii. dijkstra算法 的实现记住一句话， 一个点第一次出队的时候确定起点到该点的最短路
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std; 

typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, m; 
int h[N], w[N], e[N], ne[N], idx; 
int dist[N]; 
bool st[N]; 

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist); 
    dist[1] = 0; 
    priority_queue<PII, vector<PII>, greater<PII>> heap; 
    heap.push({0, 1}); 
    
    while (heap.size()) {
        auto t = heap.top(); 
        heap.pop(); 
        
        int ver = t.second, distance = t.first; 
        
        if (st[ver]) continue; 
        st[ver] = true; 
        
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i]; 
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i]; 
                heap.push({dist[j], j});
            }
        }
    }
    
    if (dist[n] == 0x3f3f3f3f) return -1; 
    return dist[n]; 
}

int main() {
    scanf("%d%d", &n, &m); 
    
    memset(h, -1, sizeof h); 
    while (m -- ) {
        int a, b, c; 
        scanf("%d%d%d", &a, &b, &c); 
        add(a, b, c); 
    }
    
    cout << dijkstra() << endl; 
    
    return 0; 
}
~~~

## 相关题目
[[WC 284. 得到要求路径的最小带权子图#6032 得到要求路径的最小带权子图 https leetcode-cn com problems minimum-weighted-subgraph-with-the-required-paths]]