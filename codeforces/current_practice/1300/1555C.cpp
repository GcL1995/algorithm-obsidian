#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010; 

int n; 
int w[2][N];
LL g[N], f[N]; 

int main() {
    int t; 
    cin >> t; 
    while (t -- ) {
        cin >> n; 
        for (int i = 1; i <= n; i ++ ) cin >> w[0][i]; 
        for (int i = 1; i <= n; i ++ ) cin >> w[1][i]; 
        for (int i = 1; i <= n; i ++ ) f[i] = f[i - 1] + w[0][i]; 
        for (int i = 1; i <= n; i ++ ) g[i] = g[i - 1] + w[1][i]; 
        
        LL ans = 1e18; 
        for (int i = 1; i <= n; i ++ ) {
            ans = min(ans, max(g[i - 1] - g[0], f[n] - f[i]));
        }
        cout << ans << endl; 
    }
    
    return 0; 
}