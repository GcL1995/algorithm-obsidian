## 破环成链
#破环成链
~~~c++
// 出现环，可通过破环成链的方法简化代码
// 一维 环到链  
// 二维 矩阵滚动 --> 滑动
~~~
### 相关题目
[[CF 1660E. Matrix and Shifts]]
## 数学
### 最大公约数
~~~c++
// a * b 被c整除 等价于 b 是 a / gcd(a, c) 的倍数
// gcd(n, n + 1) = 1
~~~

### 按位与
> 与运算始终变小
> 与运算的可能范围最多等于1的位数

### 按位或
> 或运算始终变大
> 或运算的可能范围最多等于0的位数
### 按位异或
> a <= b <= c, 则 a^c >= b ^ c 
#### 相关题目
[[D. Maximum Product Strikes Back]]

### 组合数公式
> c(a, 1) + c(a, 3) + ... + c(a, a - k) = 2^(a - 1) (k = (a + 1) % 2)
> 证明：
> 因为c(a, i) = c(a - 1, i) + c(a - 1, i - 1)
> 所以 如果 k = 1, c(a, 1) + c(a, 3) + ... + c(a, a - k) = c(a - 1, 0) + c(a - 1, 1) + c(a - 1, 2) + c(a - 1, 3) + ... + c(a - 1, a -k - 1) + c(a - 1, a - k) = 2^(n - 1) (c(a - 1, a) = 0)
> 
>


