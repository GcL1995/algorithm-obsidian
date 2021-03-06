#### [2242. 节点序列的最大得分](https://leetcode-cn.com/problems/maximum-score-of-a-node-sequence/)
#暴力
> 题目大意：
> 	一个图，要求求出一个四点序列，该四点序列相邻的两个点必须直接相连。
> 	求满足条件的权值和最大值。
> 提示一：确定一条边可以确定两个点。
> 提示二：在提示一的基础上，如果知道了两个点分别相连的所有点，遍历即可。
> 提示三：可以优化提示二中的遍历，易知只需要遍历每个点的最大的三个点。
> 提示四：最终的时间复杂度为o(nlog(n))主要花费在排序。
> 
~~~c++
/*
i. 一个朴素的想法， 点权变成边权，或者点变边，边变点
ii.如果边变点，点变边，那么遍历中间点即可
iii. 实际上即为遍历中间边，找寻最外侧两个点权值最大的点
iv. 只需要遍历最大的三个边即可
*/
typedef pair<int, int> PII;
#define x first
#define y second

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size(); 
        vector<vector<PII>> ne(n); 
        for (auto &edge: edges) {
            int a = edge[0], b = edge[1];
            ne[a].push_back({scores[b], b});
            ne[b].push_back({scores[a], a});
        }
        
        for (int i = 0; i < n; i ++ ) {
            sort(ne[i].begin(), ne[i].end()); 
            reverse(ne[i].begin(), ne[i].end()); 
        }
         
        int ans = -1; 
        for (auto &edge: edges) {
            int a = edge[0], b = edge[1], m1 = ne[a].size(), m2 = ne[b].size();
            for (int i = 0; i < min(3, m1); i ++ ) {
                for (int j = 0; j < min(3, m2); j ++ ) {
                    int x = ne[a][i].y, y = ne[b][j].y; 
                    if (y != a && x != b && x != y) ans = max(ans, scores[a] + scores[b] + scores[y] + scores[x]); 
                }
            }
            //exit(0);
        }
        return ans; 
    }
};
~~~