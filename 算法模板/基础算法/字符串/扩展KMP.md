# 扩展KMP
[oiwiki 参考资料](https://oi-wiki.org/string/z-func/)
#### [2223. 构造字符串的总得分和](https://leetcode-cn.com/problems/sum-of-scores-of-built-strings/)
#扩展KMP #模板题
~~~c++
/*
i. 运用自动机的思想寻找限制条件下的状态转移函数，使得可以借助之前的状态来加速计算新的状态。
ii. 关键是算法的过程中我们维护右端点最靠右的匹配段。
严谨的定义是，遍历到当前点，假设为x， 此时 l, r 表示 对于所有的l <= x 最大的满足匹配段的r
iii. 则可以利用该段进行z[x + 1]的计算
*/
typedef long long LL; 
class Solution {
public:
    long long sumScores(string s) {
        int n = s.size(); 
        vector<int> z(n);

        for (int i = 1, l = 0, r = 0; i < n; i ++ ) {
            if (i <= r && z[i - l] < r - i + 1) z[i] = z[i - l];
            else {
                z[i] = max(0, r - i + 1);
                while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i] ++;
            } 
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }
        LL ans = n; 
        for (auto x: z) ans += x;
        return ans; 
    }
};
~~~