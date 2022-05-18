# 扩展KMP
[oiwiki 参考资料](https://oi-wiki.org/string/z-func/)
#### [2223. 构造字符串的总得分和](https://leetcode-cn.com/problems/sum-of-scores-of-built-strings/)
#扩展KMP #模板题
~~~c++
/*
i. 运用自动机的思想寻找限制条件下的状态转移函数，使得可以借助之前的状态来加速计算新的状态。
ii. 关键是算法的过程中我们维护右端点最靠右的匹配段。
严谨的定义是，遍历到当前点，假设为x， 此时 L, R 表示 对于所有的L <= x 最大的满足匹配段的R
也就是满足s[L, R] == s[0, R - L]， 最大的r(只考虑非平凡情况)
iii. 则可以利用该段进行z[x + 1]的计算

自动机的具体转移方程：
i.如果 i <= r, 那么 根据 s[L, R] == s[0, R - L] 有 s[i, R] == s[i - L, R - L]
那么有 z[i] >= min(z[i - L], R - i + 1) 

	进一步的如果z[i - L] = len < R - i + 1, 那么 s[i - L + len] != s[len] 且 (i + len <= R)
	所以z[i - L + len] == s[i + len] 
	所以有 s[i + len] != s[len]
	所以z[i] < len + 1
	所以z[i] = len

所以如果z[i - L] < R - L + 1, 那么 z[i] = z[i - L]
而如果z[i - L] >= R - L + 1, 那么我们就可以直接暴力去求， 要知道R的取值最多只有n个，所以这一重循环，最多执行n次。

ii. 如果 i > r, 那么同样的可以暴力去求解z[i], 这样也必然更新[L, R], 同样的执行次数最多n次
*/
typedef long long LL; 
const int N = 100010; 
int z[N];

class Solution {
public:
    LL sumScores(string num) {
        int n = num.size();
        int l = 0, r = 0;  
        for (int i = 1; i <= n - 1; i ++ ) {
            if (i <= r && z[i - l] < r - i + 1) z[i] = z[i - l];
            else {
                z[i] = max(0, r - i + 1);
                while (i + z[i] <= n - 1 && num[i + z[i]] == num[z[i]]) z[i] ++;
            }
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }
        LL res = n; 
        for (int i = 0; i <= n - 1; i ++ ) res += z[i];
        return res; 
    }
};
~~~