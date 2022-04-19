#### [6023. 用地毯覆盖后的最少白色砖块](https://leetcode-cn.com/problems/minimum-white-tiles-after-covering-with-carpets/)
#DP 
##### c++
~~~c++
/*
i. 考虑线性DP
ii. f[i][j] 表示 前i个地板 j个毯子 剩下的最少白砖数量
iii. 转移方程 
当前地板为黑色，
str[i] = '0' f[i][j] = f[i - 1][j]
当前地板为白色，分为两种情况，第一种当前砖块被覆盖，第二种当前砖块不被覆盖
str[i] = '1' f[i][j] = f[max(0, i - l)][j - 1]
*/
const int N = 1010;
int f[N][N]; 
 
class Solution {
public:
    int minimumWhiteTiles(string str, int m, int l) {
        int n = str.size();
        str = " " + str;

        for (int i = 1; i <= n; i ++ ) {
            for (int j = 0; j <= m; j ++ ) {
                if (j == 0) {
                    f[i][j] = f[i - 1][j] + str[i] - '0';
                    continue;
                }
                if (str[i] == '0') f[i][j] = f[i - 1][j]; 
                else f[i][j] = min(f[max(0, i - l)][j - 1], f[i - 1][j] + 1);
            }
        }
        return f[n][m]; 
    }
};
~~~
##### python
~~~python
class Solution:
    def minimumWhiteTiles(self, floor: str, m: int, l: int) -> int:
        n = len(floor)
        floor = ' ' + floor
        f = [[0] * (m + 1) for _ in range(n + 2)]
        for i in range(1, n + 1):
            for j in range(m + 1):
                if j == 0:
                    f[i][j] = f[i - 1][j] + int(floor[i])
                elif floor[i] == '0':
                    f[i][j] = f[i - 1][j]
                else:
                    f[i][j] = min(f[i - 1][j] + 1, f[max(0, i - l)][j - 1])
                #print("i = %s, j = %s, f[i][j] = %s" % (i, j, f[i][j]))
        return f[n][m]


~~~

##### java
~~~java
class Solution {
    
    public int minimumWhiteTiles(String str, int m, int l) {
        var n = str.length(); 
        var f = new int[n + 1][m + 1];
        str = " " + str;
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 0; j <= m; j ++ ) {
                if (j == 0) {
                    f[i][j] = f[i - 1][j] + str.charAt(i) - '0';
                    continue;
                }
                
                if (str.charAt(i) == '0') f[i][j] = f[i - 1][j];
                else f[i][j] = Math.min(f[i - 1][j] + 1, f[Math.max(0, i - l)][j - 1]);
            }
        }
        return f[n][m]; 
    }
}
~~~
##### go 
~~~go
func minimumWhiteTiles(str string, m int, l int) int {
    n := len(str)
    str = " " + str

    f := make([][]int, n + 1)
    f[0] = make([]int, m + 1)

    for i := 1; i <= n; i ++ {
        f[i] = make([]int, m + 1)
        for j := 0; j <= m; j ++ {
            if j == 0 {
                f[i][j] = f[i - 1][j] + int(str[i]) - int('0')
                continue
            }
            if str[i] == '0' {
                f[i][j] = f[i - 1][j]
            } else {
                f[i][j] = min(f[i - 1][j] + 1, f[max(0, i - l)][j - 1])
            }
        }
    }
    //print(f)
    return f[n][m] 
}
func print(f [][]int) {
    for _, num := range f {
        for _, v := range num {
            fmt.Printf("%d ", v)
        }
        fmt.Println()
    }
}
func max(a int, b int) int {
    if a >= b {
        return a
    }
    return b
}

func min(a int, b int ) int {
    if a <= b {
        return a
    }
    return b
}
~~~

##### scala
~~~scala
object Solution {
    def minimumWhiteTiles(floor: String, m: Int, l: Int): Int = {
        var n = floor.size
        var str = " " + floor
        var cs = str.toCharArray()

        var f = new Array[Array[Int]](n + 1)
        for (i <- 0 to n) {
            f(i) = new Array[Int](m + 1)
        }

        for (i <- 1 to n) {
            for (j <- 0 to m) {
                if (j == 0) f(i)(j) = f(i - 1)(j) + cs(i) - '0'
                else if (cs(i) == '0') f(i)(j) = f(i - 1)(j)
                else f(i)(j) = Math.min(f(i - 1)(j) + 1, f(Math.max(0, i - l))(j - 1))
            }
        }
        // f.foreach(a => {
        //     a.foreach(print)
        //     println()
        // })
        return f(n)(m)
    }
}
~~~
