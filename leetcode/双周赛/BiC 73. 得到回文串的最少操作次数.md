 [5237. 得到回文串的最少操作次数](https://leetcode-cn.com/problems/minimum-number-of-moves-to-make-palindrome/)
 #贪心 #回文
 ### c++
 ~~~c++
/*
i.只考虑偶数情况
ii. 如果x在y的左边，只有三种情况..x..y..y..x.. ..x..x..y..y.. ..x..y..x..y,
这三种情况下，均是先移动x到左边为最优
*/
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0;
        int n = s.size();  
        for (int i = 0, j = n - 1; i < j; i ++, j --) {
            bool flag = false; 
            for (int k = j; k > i; k -- ) {
                if (s[k] == s[i]) {
                    while (k < j) {
                        swap(s[k], s[k + 1]);
                        k ++;
                        ans ++;
                    }
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ans += n / 2  - i;
                j ++;
            }
            //cout << i << ' ' << s << endl;
        }
        return ans; 
    }
};
 ~~~
### python
~~~python
class Solution:
    def minMovesToMakePalindrome(self, s: str) -> int:
        ans = 0
        t = list(s)
        n = len(t)
        i, j =0, n - 1
        # swap = lambda a, b: s[a], s[b] = s[b], s[a]
        while i < j:
            k = j
            while k > i:
                if t[k] == t[i]:
                    break
                k -= 1
            if k > i:
                while k < j:
                    t[k], t[k + 1] = t[k + 1], t[k]
                    k += 1
                    ans += 1
                j -= 1
            else:
                ans += int(n / 2) - i
            i += 1
            # print(t)
        return ans
~~~
### java
~~~java
class Solution {
    public int minMovesToMakePalindrome(String s) {
        char[] str = s.toCharArray(); 
        int n = s.length();
        int ans = 0;  
        for (int i = 0, j = n - 1; i < j; i ++, j -- ) {
            int k = j; 
            while (k > i) {
                if (str[k] == str[i]) break;
                k --;
            } 
            if (k > i) {
                while (k < j) {
                    swap(str, k, k + 1);
                    k ++;
                    ans ++;
                }
            }
            else {
                ans += n / 2 - i;
                j ++;
            }
        }
        return ans; 
    }

    void swap(char[] str, int i, int j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}
~~~
### scala
~~~scala
import scala.util.control._
object Solution {
    def minMovesToMakePalindrome(s: String): Int = {
        var str = s.toCharArray()
        def swap(a: Int,b: Int){
            val c = str(a)
            str(a) = str(b)
            str(b) = c
        }

        var ans = 0
        val n = str.size
        var i = 0
        var j = n - 1
        while (i < j) {
            var k = j
            val loop = new Breaks

            loop.breakable{
                while (k > i) {
                    if (str(k) == str(i)) loop.break
                    k -= 1
                }
            }
            if (k > i) {
                while (k < j) {
                    swap(k, k + 1)
                    k += 1
                    ans += 1
                }
                j -= 1
            }
            else {
                ans += n / 2 - i
            }
            i += 1
            // str.foreach(print)
            // println()
        }
        return ans
    }
}
~~~
### go
~~~go
func minMovesToMakePalindrome(s string) int {
    ans := 0
    str := []rune(s)
    n := len(str)
    i := 0
    j := n - 1
    for i < j {
        k := j
        for k > i {
            if str[i] == str[k] {
                break
            }
            k --
        }
        if k > i {
            for k < j {
                swap(str, k, k + 1)
                k += 1
                ans += 1
            }
            j -= 1
        } else {
            ans += n / 2 - i
        }
        i += 1
    }
    return ans 
}

func swap(s []rune, i int, j int) {
    c := s[i]
    s[i] = s[j]
    s[j] = c
} 
~~~

 