#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, M = 100010;

int n, k;  
int d[N], b[N], c[N], f[M]; 

void init() {
    d[1] = 0; 
    for (int i = 1; i < N; i ++ ) {
        for (int x = 1; x <= i; x ++ ) {
            int j = i + i / x; 
            if (j < N) d[j] = min(d[j], d[i] + 1); 
        }
    }
}

int main() {
    
    memset(d, 0x3f, sizeof d); 
    init(); 
    
    int t; 
    cin >> t; 
    while (t -- ) {
        cin >> n >> k; 
        for (int i = 1; i <= n; i ++ ) scanf("%d", &b[i]); 
        for (int i = 1; i <= n; i ++ ) scanf("%d", &c[i]); 
        
        
        int s = 0; 
        for (int i = 1; i <= n; i ++ ) s += d[b[i]]; 
        k = min(k , s); 
         
        memset(f, 0, sizeof f); 
        for (int i = 1; i <= n; i ++ ) {
            for (int j = k; j - d[b[i]] >= 0; j -- ) {
                f[j] = max(f[j], f[j - d[b[i]]] + c[i]); 
            }
        }
        
        
        int ans = 0; 
        for (int i = 0; i <= k; i ++ ) ans = max(f[i], ans); 
        
        printf("%d\n", ans); 
        
        
    }
    
    return 0; 
}