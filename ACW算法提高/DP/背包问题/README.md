[TOC]
# 背包九讲
[背包九讲](https://www.cnblogs.com/jbelial/articles/2116074.html)
## 1.01背包
$$
\begin{aligned}
&f[i][j] = max(f[i - 1][j - v[i]] + w[i]) \\
&st.\; j >= v[i]
\end{aligned}
$$
### 维度优化
~~~c++
for (int i = 1; i <= n; i ++ ) {
	for (int j = V; j >= v[i]; j -- ) 
		f[j] = max(f[j], f[j - v[i]] + w[i]); 
}
~~~
## 2.完全背包问题
$$
\begin{aligned}
f[i][j] = max(f[i - 1][j - k * v[i]] + k * w[i])\\
st. \; j >= k * v[i]
\end{aligned}
$$
### 维度优化
~~~c++
for (int i = 1; i <= n; i ++ ) {
	for (int j = v[i]; j <= V; j ++ ） 
		f[j] = max(f[j], f[j - v[i]] + w[i]); 
}
~~~
## 3.多重背包问题
## 4.混合三种背包问题
## 5.二维费用的背包问题
## 6.分组背包问题
## 7.有依赖的背包问题
## 8.泛化物品
## 9.背包问题问法的变化
