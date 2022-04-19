#### [6036. 构造字符串的总得分和](https://leetcode-cn.com/problems/sum-of-scores-of-built-strings/)
##### 法一 字符串哈希
~~~c++
typedef unsigned long long ULL;
typedef long long LL;

const int N = 100010, P = 131; 

int n, m; 
ULL h[N], p[N];
char str[N];

ULL get(int l, int r) {
    if (l > r) return 0;
    return h[r] - h[l - 1] * p[r - l + 1]; 
}

void init(int n) {
    p[0] = 1; 
    for (int i = 1; i <= n; i ++ ) {
        p[i] = p[i - 1] * P; 
        h[i] = h[i - 1] * P + str[i]; 
    }
}


class Solution {
public:
    long long sumScores(string s) {
        int n = s.size(); 
        for (int i = 0; i < s.size(); i ++ ) str[i + 1] = s[i];
        
        init(n);
        
        LL res = 0; 
        for (int i = n; i >= 1; i -- ) {
            int l = 0, r = (n - i) + 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (get(1, mid) == get(i, i + mid - 1)) l = mid;
                else r = mid - 1;
            }
            //printf("%d\n", l); 
            
            res += l;
        }
        return res; 
    }
};
~~~

##### 扩展KMP
#扩展KMP 
###### c++
~~~c++
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
###### java
~~~java
class Solution {
    public long sumScores(String s) {
        int n = s.length();
        int[] z = new int[n];
        z[0] = 0; 

        for (int i = 1, l = 0, r = 0; i < n; i ++ ) {
            if (i <= r && z[i - l] < r - i + 1) z[i] = z[i - l];
            else {
                z[i] = Math.max(0, r - i + 1); 
                while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i])) z[i] ++;
            }
            if (i + z[i] - 1 > r ) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        long ans = n; 
        for (int x: z) ans += x;
        return ans; 
    }
}
~~~
###### scala
~~~scala
object Solution {
    def sumScores(s: String): Long = {
        val n = s.length()
        val z = new Array[Int](n)
        var l = 0
        var r = 0
        for (i <- 1 until n) {
            if (i <= r && z(i - l) < r - i + 1) z(i) = z(i - l)
            else {
                z(i) = Math.max(0, r - i + 1)
                while (i + z(i) < n && s(i + z(i)) == s(z(i))) z(i) += 1
            }
            if (i + z(i) - 1 > r) {
                l = i
                r = i + z(i) - 1
            }
        }
        var ans: Long = n
        for (x <- z) ans += x
        ans
    }
}
~~~
###### go
~~~go
func sumScores(s string) int64 {
    var n = len(s)
    var z = make([]int, n)

    for i, l, r := 1, 0, 0; i < n; i += 1 {
        if i <= r && z[i - l] < r - i + 1 {
            z[i] = z[i - l]
        } else {
            z[i] = max(0, r - i + 1)
            for i + z[i] < n && s[i + z[i]] == s[z[i]] {
                z[i] += 1
            }
            if i + z[i] - 1 > r {
                l, r = i, i + z[i] - 1
            }
        }
    }
    var ans = int64(n)
    for _, x := range(z) {
        ans += int64(x)
    }
    return ans
}

func max(a int, b int) int {
    if a >= b {
        return a
    }
    return b
}
~~~
###### python
~~~python
class Solution:
    def sumScores(self, s: str) -> int:
        n = len(s)
        z = [0 for _ in range(n)] 

        l, r = 0, 0
        for i in range(1, n):
            if i <= r and z[i - l] < r - i + 1 :
                z[i] = z[i - l]
            else:
                z[i] = max(0, r - i + 1)
                while i + z[i] < n and s[i + z[i]] == s[z[i]]:
                    z[i] += 1
            if i + z[i] - 1 > r: 
                l, r = i, i + z[i] - 1
        ans = n
        for x in z:
            ans += x
        return ans

~~~

