# 区间DP
#### [282. 石子合并](https://www.acwing.com/problem/content/284/)
#DP #区间DP #模板题
~~~c++
/*
i. 区间DP的遍历顺序是根据区间大小来的
ii. 区间DP的状态定义，是根据区间左右端点来的
*/
import java.util.Scanner;

public class Main {
    static final int N = 310,INF = 1<<30;
    static int[] s = new int[N];
    static int[][] f = new int[N][N];
    static int n;
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        for (int i = 1; i <=n ; i++) {
            s[i] = scanner.nextInt();
            s[i] += s[i-1];
        }
        for (int len = 2; len <=n ; len++) {
            for (int i = 1; i+len-1<=n; i++) {
                int l = i, r = i+len-1;
                f[l][r] = INF;
                for (int j = l; j <r ; j++) {
                    f[l][r] = Math.min(f[l][r],f[l][j]+f[j+1][r]+s[r]-s[l-1]);
                }
            }
        }
        System.out.println(f[1][n]);
    }
}
~~~

## 相关题目
[[LC 1547. 切棍子的最小成本]]
[[LC 1039.多边形三角剖分的最低得分]]