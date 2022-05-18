[D. Maximum Product Strikes Back](https://codeforces.com/contest/1660/problem/D)
#双指针
> 题目大意：
> 给定一个数组a， -2<=a[i]<=2
> 求a的子数组的乘积最大值
~~~c++
/*
i. 最小是1
ii. 最终的区间负数个数必须是偶数， 乘积大小只和2的数目有关
iii. 可以通过0将区间分为若干块
*/
//
// Created by Administrator on 2022/3/30.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef unsigned long long ULL;

const int N = 200010;
int a[N];

int main() {
    int t;
    cin >> t;
    while (t -- ) {
        int n;
        cin >> n;

        vector<int> zeros;
        for (int i = 1; i <= n; i ++ ) {
            cin >> a[i];
            if (a[i] == 0) zeros.push_back(i);
        }
        zeros.push_back(n + 1);

        int _max = 0;
        PII ans = {n, 0};

        int pre = 0;
        for (auto curr: zeros) {
            int cnt = 0;
            int pos = 0;
            for (int i = pre + 1; i < curr; i ++ ) {
                if (abs(a[i]) == 2) cnt ++;
                if (a[i] < 0) pos = 1 - pos;
            }
            //printf("%d\n", s)
            if (cnt > _max && pos == 0) ans = {pre, n - curr + 1}, _max = cnt;
            else if (cnt > _max && pos == 1) {
                int tcnt = cnt;
                for (int i = pre + 1; i < curr; i ++ ) {
                    if (abs(a[i]) == 2) tcnt --;
                    if (a[i] < 0 && tcnt > _max) ans = {i, n - curr + 1}, _max = tcnt;
                    if (a[i] < 0) break;
                }
                tcnt = cnt;
                for (int i = curr -1; i > pre; i -- ) {
                    if (abs(a[i]) == 2) tcnt --;
                    if (a[i] < 0 && tcnt > _max) ans = {pre, n - i + 1}, _max = tcnt;
                    if (a[i] < 0) break;
                }
            }
            pre = curr;
        }

        cout << ans.x << ' ' << ans.y << endl;

    }
    return 0;
}
~~~