#include <iostream>
#include <cstring>

using namespace std; 

const int N = 510;

int n, l, m; 
int a[N], b[N];
int f[N][N];

int main() {
    cin >> n >> l >> m; 
    
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]); 
    a[n] = l;
    for (int i = 0; i < n; i ++ ) scanf("%d", &b[i]); 
    
    memset(f, 0x3f, sizeof f); 
    
    f[0][0] = 0; 
    
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= m && j < i; j ++ ) {

            for (int k = i - 1; k >= 0; k -- ) {
                int u = j - (i - k - 1);
                if (u < 0) break;
                f[i][j] = min(f[i][j], f[k][u] + b[k] * (a[i] - a[k]));
                //printf("%d %d %d %d %d %d %d\n", i, j, k, b[k], a[i] - a[u], f[k][u], f[i][j]); 
                
            }
            
        }
    }
    
    int res = 1e9; 
    for (int i = 0; i <= m; i ++ ) res = min(f[n][i], res);
    
    printf("%d", res); 
    
    return 0; 
}

