#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
int a[N];
int color[N][N];

int main() {
    int n, k; 
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) cin >> a[i]; 
    int _min = *min_element(a, a + n), _max = *max_element(a, a + n); 
    if (_max - _min > k) cout << "NO" << endl; 
    else {
        cout << "YES" << endl; 
        for (int i = 0; i < n; i ++ ) {
            for (int j = 1; j <= a[i]; j ++ ) {
                if (j <= _min) cout << 1 << " "; 
                else cout << j - _min << " ";
            }
            cout << endl; 
        }
    }
    return 0; 
}