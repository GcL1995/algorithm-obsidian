typedef long long LL;

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

LL n, k;

int main() {
    cin >> n >> k;
    
    if (k == 1) {
        cout << n << endl;
    } else {
        LL p = 0, x = 1;
        while (x <= n) {
            p ++;
            x *= 2;
        }
        cout << x - 1 << endl; 
    }
    
    return 0; 
}