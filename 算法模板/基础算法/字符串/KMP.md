# KMP
> i. ne数组
> 	与下图不同，通常我会习惯patter数组下标从1开始，
>     ne[j] = i表示 pattern[1 ~ i] == pattern[j - i + 1 ~ j]
> 	ne[2] = 1 表示 pattern[0] == pattern[2]
> 	ne[6] = 3 表示 pattern[0-2] == pattern[4 - 6]
![[Pasted image 20220419143814.png]]

> ii. ne数组求得之后，遍历target数组
![[Pasted image 20220419144647.png]]
#### [AcWing 831. KMP字符串](https://www.acwing.com/activity/content/problem/content/869/)
~~~c++
/*
i. 使用自动机模型
ii. ne[i] = j 表示 s[1~j] == s[(i - j + 1) ~ i]
*/
#include <iostream>

using namespace std; 

const int N = 100010, M = 1000010; 

int n, m; 
int ne[N]; 
char p[N], s[M]; 

int main() {
    cin >> n >> p + 1 >> m >> s + 1;
    
    for (int i = 2, j = 0; i <= n; i ++ ) {
        while (j && p[i] != p[j + 1]) j = ne[j]; 
        if (p[i] == p[j + 1]) j ++; 
        ne[i] = j; 
    }
    
    for (int i = 1, j = 0; i <= m; i ++ ) {
        while (j && s[i] != p[j + 1]) j = ne[j]; 
        if (s[i] == p[j + 1]) j ++; 
        
        if (j == n) {
            printf("%d ", i - n); 
            j = ne[j]; 
        }
    }
    return 0; 
}
~~~
