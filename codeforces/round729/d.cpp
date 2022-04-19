#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 200010, M = 30; 

int n; 
int g[N]; 
int f[N][M];

int gcd(int a, int b)  // 欧几里得算法
{
    return b ? gcd(b, a % b) : a;
}


void init() {
    for (int j = 0; j < M; j ++ ) {
        for (int i = 1; i + (1 << j) - 1 <= n; i ++ ) {
            if (!j) f[i][j] = g[i]; 
            else f[i][j] = gcd(f[i][j - 1], f[i + (1 << j - 1)][j -1]);
        }
    }
}

int get(int l, int r) {
    int k = log(r - l + 1) / log(2);
    return gcd(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
    cin >> n; 
    for (int i = 1; i <= n; i ++ ) scanf("%d", &g[i]); 

    init(); 
     
    
    int maxr = 0, st = 1, res = 0; 
    for (int i = 1; i <= n; i ++ ) {
        while (st < i && get(st, i) < i - st + 1) st ++;
        if (get(st, i) == i - st + 1) {
            if (st > maxr) {
                res ++;
                maxr = i; 
            }
        }
        cout << res << ' '; 
    }
    return 0; 
}