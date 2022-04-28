# 线性DP

[acwing 算法基础课 模板题](https://www.acwing.com/problem/content/900/)
898. 数字三角形
#DP
~~~c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, INF = 1e8; 

int n; 
int w[N][N], f[N][N]; 

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= i; j ++ ) cin >> w[i][j]; 
    }

    //为了在状态更新中，不需要判断临界值，所以涉及到更新的点需要赋值为负无穷
    for (int i = 0; i <= n; i ++ ) {
        for (int j = 0; j <= i + 1; j ++ ) f[i][j] = -INF;
    }

	//只能从[0][0] 点开始更新
    f[0][0] = 0; 
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= i; j ++ ) {
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + w[i][j]; 
        }
    }

    int ans = - INF; 
    for (int i = 1; i <= n; i ++ ) ans = max(ans, f[n][i]); 
    
    cout << ans << endl; 
    
    return 0; 
}
~~~

## lc contest 200
#### [1537. 最大得分](https://leetcode-cn.com/problems/get-the-maximum-score/)
#DP
~~~c++
/*
拓扑排序： 
i.只能从小到大转移 
ii. nums1只能转移到nums1上的点 f[i] = f[i - 1] + nums1[i]， nums2只能转移到nums2上的点 g[i] = g[i - 1] + nums2[i];
iii. nums1和nums2上相等的点合并 f[i] = g[j] = max(f[i - 1] + nums1[i], g[j - 1] + nums2[j]);
iv. f, g只用到上一次的值，可以只用一个值存储
v. 可以通过归并排序代码模板实现
*/
typedef long long LL;
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int mod = 1e9 + 7; 
        LL f = 0, g = 0; 
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) f += nums1[i ++];
            else if (nums2[j] < nums1[i]) g += nums2[j ++];
            else f = g = max(f + nums1[i ++], g + nums2[j ++ ]);
        }
        while (i < n) f = f + nums1[i ++];
        while (j < m) g = g + nums2[j ++];
        return max(f, g) % mod; 
    }
};
~~~

## 周赛
[[WC 279. 移除所有载有违禁货物车厢所需的最少时间]]
[[WC 282. 完成比赛的最少时间]]
[[LC 2088. 统计农场中肥沃金字塔的数目]]
[[LC 1937. 扣分后的最大得分]]
[[BiC 74.用地毯覆盖后的最少白色砖块]]
[[LC 1955. 统计特殊子序列的数目]]
[[LC 2116. 判断一个括号字符串是否有效]]
[[LC 1444. 切披萨的方案数]]
[[WC 286. 从栈中取出 K 个硬币的最大面值和]]
[[WC 264.并行课程 III]]
[[CF 1611D. Weights Assignment For Tree Edges]]
[[CF 1667B. Optimal Partition]]