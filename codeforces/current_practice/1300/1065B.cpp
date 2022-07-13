#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;


LL n, m; 

int main() {
    cin >> n >> m; 
    
    LL _min = max(n - 2 * m, (LL)0);
    LL l = 0, r = n;
    while (l < r) {
        LL mid = l + r + 1 >> 1;
        if (mid * (mid - 1) / 2 < m) l = mid;
        else r = mid - 1;
    }
    
    LL _max;
    if (m == 0) _max = n;
    else _max = max((LL)0, n - l - 1); 
    
    cout << _min << ' ' << _max; 
    cout << endl; 
    
    return 0; 
    
}