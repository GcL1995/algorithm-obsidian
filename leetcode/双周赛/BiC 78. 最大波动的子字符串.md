#### [2272. 最大波动的子字符串](https://leetcode.cn/problems/substring-with-largest-variance/)
#DP 
> 题目大意：
> 	求子字符串的最大波动值
> 	字符串波动 = 出现最多的字符的出现次数 - 出现最小的字符的出现次数
> 	子字符串是一个字符串的一段连续字符序列
~~~c++
/*
i. 枚举出现最多的字符x和出现最少的字符y
ii. 转换为数组f, s[i] = x, f[i] = 1, s[i] = y, f[i] = -1, else f[i] = 0
	问题转换为至少包含一个-1的最大子数组和
iii. diff[i]表示以i为结尾的子数组的最大和
	 diffb[i] 表示以i为结尾的包含-1的子数组的最大和
	 易知， diff[i] >= diffb[i]
iv. 状态转移方程：
	f[i] == 1
	diff[i] = max(1, diff[i - 1] + 1);
	diffb[i] = diffb[i - 1] + 1;
	f[i] == -1:
	diff[i] = max(-1, diff[i - 1] - 1);
	diffb[i] = diff[i]
	f[i] == 0:
	diff[i] = max(0, diff[i - 1])
	diff[i] = diffb[i - 1]

*/
const int INF = 1e9; 

class Solution {

public:

    int largestVariance(string s) {

        int n = s.size(); 

        int res = 0; 

        for (int x = 'a'; x <= 'z'; x ++ ) {

            for (int y = 'a'; y <= 'z'; y ++ ) {

                if (x == y) continue;

                int ans = 0, diff = 0, diffb = -INF;

                for (int i = 0; i < n; i ++ ) {

                    int c = s[i];

                    if (x == c) {

                        diffb = diffb + 1;

                        diff = max(1, diff + 1);

                    } else if (y == c) {

                        diff = max(-1, diff - 1);

                        diffb = diff;

                    } else {

                        diff = max(0, diff);

                    }

                    ans = max(ans, diffb);

                }

                res = max(res, ans);

            }

        }

        return res; 

    }

};
~~~