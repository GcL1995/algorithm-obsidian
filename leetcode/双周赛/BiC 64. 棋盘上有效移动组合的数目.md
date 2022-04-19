# D

#### [2056. 棋盘上有效移动组合的数目 - 力扣（LeetCode）](https://leetcode-cn.com/problems/number-of-valid-move-combinations-on-chessboard/)
#DFS
~~~c++
/*
i. 数据范围确定可以用爆搜 (4 * 8) ^ 4 < 2e6 (最多有4个点， 每个点的移动最多是queue 4 * 8个位置)
ii. dfs爆搜的步骤是从第一个点到最后一个点，每个点有八个方向，也就是整个搜索树是一个4层的8叉搜索树
iii. 其实主要的问题是判断一个转移是不是一个合法的转移，这意味着移动的每一步，所有的棋子都互相不重叠，可以直接暴力解决
*/
class Solution {
public:
    vector<string> pc;
    vector<vector<int>> pt;    //每个点的初始位置
    vector<vector<int>> path; //每个点的移动方向和位数
	//顺时针8个方向， queue可以全走八个方向，车走偶数方向，象走奇数方向
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1}; 
    int p[5][2]; 
    int n; 
    int res = 0; 

    bool check() {

		//(p[i][0], p[i][1])表示第i个棋子的当前位置
        for (int i = 0; i < n; i ++ ) {
            p[i][0] = pt[i][0]; 
            p[i][1] = pt[i][1]; 
        }

		// i 表示第i步
        for (int i = 1; ; i ++ ) {
            bool flag = false; 
            for (int j = 0; j < n; j ++ ) { //j表示第j个棋子的移动
                int d = path[j][0], t = path[j][1]; 
                if (i <= t) {
                    flag = true; 
                    p[j][0] += dx[d]; 
                    p[j][1] += dy[d]; 
                }
            }

            if (!flag) break; //所有棋子都已经移动到最后一个位置了，就跳出

            for (int j = 0; j < n; j ++ ) { //暴力判断是否有棋子位置重合
                for (int k = j + 1; k < n; k ++ ) {
                    if (p[j][0] == p[k][0] && p[j][1] == p[k][1]) return false; 
                }
            }
        }

        return true; 
    }

    void dfs(int u) {
        if (u == n) {
            if (check()) res ++; 
            return; 
        } 

		//该点不动也算一种移动
        path.push_back({0, 0}); 
        dfs(u + 1); 
        path.pop_back(); //恢复现场

        for (int i = 0; i < 8; i ++ ) {
            string& s = pc[u]; 
            if (s == "rook" && i % 2) continue;
            if (s == "bishop" && i % 2 == 0) continue; 
            int x = pt[u][0], y = pt[u][1];
            for (int j = 1; ; j ++ ) {
                x += dx[i]; y += dy[i]; 
                if (x < 1 || x > 8 || y < 1 || y > 8) break; 

                path.push_back({i, j});
                dfs(u + 1); 
                path.pop_back(); 
            }
        }
    }

    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        pc = pieces; pt = positions;
        n = pc.size(); 
        dfs(0);
        return res; 
    }
};

~~~

