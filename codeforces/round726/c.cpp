#include <iostream>
#include <cstring>

using namespace std; 

const int N = 100010; 

int n; 
int h[N], e[2 * N], w[2 * N], ne[2 * N], idx; 
int d[N]; 

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++; 
}

void dfs(int fa, int u, int v) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i]; 
        if (j == fa) continue;
        
        w[i] = v;
        if (i % 2) w[i - 1] = v;
        else w[i + 1] = v;
        dfs(u, j, 5 - v); 
    }
}

int main() {
    int t; 
    cin >> t; 
    
    while (t -- ) {
        memset(h, -1, sizeof h); 
        memset(d, 0, sizeof d); 
        idx = 0; 
        scanf("%d", &n); 
        
        bool flag = false;
        for (int i = 1; i <= n - 1; i ++ ) {
            int a, b; 
            
            scanf("%d%d", &a, &b); 
            add(a, b); 
            add(b, a); 
            
            //printf("%d %d\n", a, b); 
            
            d[a] ++;
            d[b] ++;
            if (d[a] >= 3 || d[b] >= 3) {
                flag = true;
            }
        }
        
        if (flag) {
            printf("-1\n"); 
            continue;
        }
        
        int j = 0; 
        for (int i = 1; i <= n; i ++ ) {
            if (d[i] == 1) {
                j = i; 
                break; 
            }
        }
        
        dfs(0, j, 2); 
        for (int i = 1; i <= n - 1; i ++ ) {
            printf("%d ", w[i * 2 - 1]);
        }
        printf("\n"); 
    }
    return 0; 
}