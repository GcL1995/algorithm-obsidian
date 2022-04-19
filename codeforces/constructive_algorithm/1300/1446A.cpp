#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 200010; 

int n;
LL W;
int w[N]; 

int main() {
    int t; 
    cin >> t; 
    while (t -- ) {
        cin >> n >> W;
        for (int i = 1; i <= n; i ++ ) cin >> w[i];
        LL s = 0;
        int cnt = 0;
        bool flag = false; 
        for (int i = 1; i <= n; i ++ ) {
            if (w[i] >= (W + 1) / 2 && w[i] <= W) {
                cout << 1 << endl;
                cout << i << endl; 
                flag = true; 
                break;
            }
            
            if (w[i] < W) {
                s += w[i];
                cnt ++;
            }
            if (s >= (W + 1) / 2 && s <= W) {
                flag = true; 
                cout << cnt << endl; 
                for (int j = 1; j <= i; j ++ ) {
                    if (w[j] < W) cout << j << ' ';
                }
                cout << endl; 
                break;
            }
        }
        if (!flag) cout << -1 << endl; 
    }
    return 0; 
}