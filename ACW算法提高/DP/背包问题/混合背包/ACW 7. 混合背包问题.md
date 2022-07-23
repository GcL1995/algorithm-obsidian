[ACW 7. 混合背包问题](https://www.acwing.com/problem/content/7/)
#DP #背包问题 #混合背包问题 #多重背包问题 
> 题目大意：
> 	有N种物品和一个容量为V的背包。
> 	每种物品的体积，价值，数量分别用v， w， s表示
> 	s = 0 表示物品可以使用无限次。
> 	s = -1 表示物品只能使用一次。
> 提示一：数据范围n， V <= 1000， s <= 1000
> 提示二：完全背包和01背包可以直接o(V)求解，多重背包呢？
> 提示三：需要使用二进制优化多重背包，时间复杂度会降到o(Vlog(s))
> 提示四：多重背包和一般的二进制表示的区别在哪里？[[快速幂]] 对比一下
~~~c++
#include <iostream>

using namespace std; 

const int N = 1010; 

int n, m; 
int f[N];

int main() {
    cin >> n >> m; 
    int v, w, s;
    for (int i = 0; i < n; i ++ ) {
        cin >> v >> w >> s;
        if (s == -1) {// 01背包
            for (int j = m; j >= v; j -- ) f[j] = max(f[j], f[j - v] + w); 
        } else if (s == 0) {//完全背包
            for (int j = v; j <= m; j ++ ) f[j] = max(f[j], f[j - v] + w); 
        } else {//多重背包转化为01背包 二进制优化思想
            int k = 1; 
            while (k <= s) {
                for (int j = m; j >= k * v; j -- ) f[j] = max(f[j], f[j - k * v] + k * w); 
                s -= k; 
                k *= 2;
            }
            if (s > 0) {
                for (int j = m; j >= s * v; j -- ) f[j] = max(f[j], f[j - s * v] + s * w); 
            }
        }
    }
    cout << f[m] << endl; 
    return 0; 
}
~~~