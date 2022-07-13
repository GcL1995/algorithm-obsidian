#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010; 

int n, m; 
bool st[N];

int main() {
    cin >> n >> m;
    while (m --) {
        int x, y; 
        cin >> x >> y; 
        st[x] = st[y] = true;
    }

    cout << n - 1 << endl; 
    
    for (int i = 1; i <= n; i ++ ) {
        if (!st[i]) {
            for (int j = 1; j <= n; j ++ ) {
                if (j == i) continue;
                cout << i << ' ' << j << endl; 
            }
            break;
        }
    }
    return 0; 
}