#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t, a, b; 

int main() {
    cin >> t; 
    
    while (t -- ) {
        cin >> a >> b; 
        
        int res = b - a; 
        for (int i = a; i < b; i ++ ) {
            int v = 0; 
            for (int j = 19; j >= 0; j -- ) {
                if ((b >> j) & 1) {
                    v += 1 << j; 
                }
                else {
                    if ((i >> j) & 1) {
                        v += 1 << j;
                        break;
                    } 
                }
            }
            res = min(res, 1 - a - b + (i | v) + i); 
        }
        cout << res << endl; 
    }
    return 0; 
}