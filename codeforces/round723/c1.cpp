#include <iostream>
#include <cstring>


using namespace std;

typedef long long LL; 

const int N = 2010, INF = 1e9; 

int n; 
int w[N];
LL f[N][N]; 

void print() {
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            printf("%d ", f[i][j]); 
        }
        printf("\n"); 
    }
}

int main() {
    cin >> n; 
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]); 
    
    memset(f, 128, sizeof f); 
    f[0][0] = 0; 
    

    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= i; j ++ ) {
            f[i][j] = max(f[i][j], f[i - 1][j]);
            if (j > 0 && f[i - 1][j - 1] >= -w[i]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + w[i]);  
        }
    }
    
    //print(); 
    
    int res = 0; 
    for (int i = 1; i <= n; i ++ ) {
        if (f[n][i] >= 0) res = i;
    }
        
    printf("%d\n", res); 
    return 0; 
}