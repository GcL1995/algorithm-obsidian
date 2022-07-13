#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 300010, INF = 1e9; 

int n, q; 
LL w[N], f[N][2]; 

int main() {
    int t; 
    cin >> t;
    while (t -- ) {
        cin >> n >> q; 
        for (int i = 1; i <= n; i ++ ) cin >> w[i]; 
        f[0][0] = -INF, f[0][1] = 0; 
        for (int i = 1; i <= n; i ++ ) {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + w[i]); 
            f[i][1] = max(f[i - 1][0] - w[i], f[i - 1][1]);
        }
        cout << f[n][0] << endl; 
    }
    return 0; 
}