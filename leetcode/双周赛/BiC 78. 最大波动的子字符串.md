#### [2272. 最大波动的子字符串](https://leetcode.cn/problems/substring-with-largest-variance/)
#DP 
> 题目大意：
> 	求子字符串的最大波动值
> 	字符串波动 = 出现最多的字符的出现次数 - 出现最小的字符的出现次数
> 	子字符串是一个字符串的一段连续字符序列
> 	
> 提示一：
> 	暴力法如何求解？优化暴力可以吗？左右端点有多少种选择？
> 提示二：
> 	似乎是个DP问题？考虑状态定义，以f[i]表示以0~i的字符串的所有子串最大波动值？或者更常用的技巧，f[i]表示i结尾的所有子字符串的最大波动值？还是不行我们必须记录所有字符的状态，这样才能做更新，否则更新无从谈起。
> 提示三：
> 	好的，现在既然要做状态所有字符的状态，当然可以考虑再加两个维度。不过一个天才的人，可以考虑新的一种思考方式，那就是*暴力枚举，出现最多的字符和出现最少的字符* 这样等价于上述考虑所有字符的状态。
> 提示四：
> 	如果当前区间枚举的两个字符不是最多和最少的呢？求最大不影响。
> 提示五：
> 	好的问题转化为求任意区间两个字符之间的出现差值的最大值， 而且我们要o(n)求解
> 提示六：
> 	现在将字符串转化为01-1三种字符的字符串，等价于求子数组的最大值，当然我们要求这个子数组必须包含一个-1
> 提示七：
> 	还记得最大子数组和问题是怎么定义状态的和状态如何转移的吗？当然是状态定义为以当前结尾的子数组的最大和。
> 提示八：
> 	如何考虑包含-1的子数组呢？
> 	我们考虑添加一个新的状态，*以当前字符结尾的包含-1的子数组的最大和*， 没有这个字符怎么办，常用的处理方式赋值为-INF
> 提示九：
> 	这样状态如何更新呢？
>     *max按照最大子数组和问题照常更新
>     *maxWithB 更新其实也很简单，当前位置是b，那么直接用max代替就行，当前位置不是b，那么就必须要用前一个位置的maxWithB更新
	
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
const int INF = 1e9; 
class Solution {
public:
    int largestVariance(string s) {
        int n = s.size(); 
        int res = 0; 
        for (int x = 'a'; x <= 'z'; x ++ ) {
            for (int y = 'a'; y <= 'z'; y ++ ) {
                if (x == y) continue;
                int ans = 0, diff = 0, diffb = -INF;
                for (int i = 0; i < n; i ++ ) {
                    int c = s[i];
                    if (x == c) {
                        diffb = diffb + 1;
                        diff = max(1, diff + 1);
                    } else if (y == c) {
                        diff = max(-1, diff - 1);
                        diffb = diff;
                    } else {
                        diff = max(0, diff);
                    }
                    ans = max(ans, diffb);
                }
                res = max(res, ans);
            }
        }
        return res; 
    }
};
~~~