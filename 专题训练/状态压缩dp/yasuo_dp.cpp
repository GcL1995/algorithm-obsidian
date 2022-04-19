#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL; 

const int N = 25, mod = 1e9 + 7;

int n; 
int g[N][N];
LL f[1 << N]; 


int main() {
    cin >> n; 
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) cin >> g[i][j]; 
    }
    
    f[0] = 1;
    for (int i = 0; i < 1 << n; i ++ ) {
        int c = 0; 
        for (int j = 0; j < n; j ++ ) c += i >> j & 1;
        for (int j = 0; j < n; j ++ ) {
            if (i >> j & 1) continue;
            if (g[j][c]) f[i | 1 << j] = (f[i | 1 << j] + f[i]) % mod;
        }
    }
    
    cout << f[(1 << n) - 1] << endl;
    
    return 0; 
}