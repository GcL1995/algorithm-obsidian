#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010; 

int t, n, k;

int w[N], s[N], g[N]; 

int main() {
    cin >> t; 
    while (t -- ) {
        cin >> n >> k; 
        for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]); 
        
        for (int i = 1; i <= n; i ++ ) g[i] = w[i];
        sort(g + 1, g + n + 1); 
        
        
        int x = 0, y = 1 << 30; 
        for (int i = 1; i <= n - (k + n + 1) / 2 + 1; i ++ ) {
            int a = g[i], b = g[i + (k + n + 1) / 2 - 1]; 
            if (b - a < y - x) y = b, x = a;
        }
        printf("%d %d\n", x, y); 
        
        for (int i = 1; i <= n; i ++ ) {
            if (w[i] >= x && w[i] <= y) s[i] = s[i - 1] + 1;
            else s[i] = s[i - 1] - 1;
        }
        int pre = 1, curr = 0;
        for (int i = 1; i <= n; i ++) {
            if (curr == k - 1) break;
            if (s[i] > s[pre - 1]) {
                printf("%d %d\n", pre, i); 
                pre = i + 1;
                curr ++;
            }
        }
        printf("%d %d\n", pre, n); 
    }
    return 0; 
}

