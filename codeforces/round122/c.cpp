#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int t; 
    cin >> t; 
    while (t -- ) {
        long long hc, dc, hm, dm;
        int k, w, a;
        cin >> hc >> dc;
        cin >> hm >> dm;
        cin >> k >> w >> a;
        
        bool flag = false; 
        for (int i = 0; i <= k; i ++ ) {
            long long  dc1 = dc + i * w, hc1 = hc + (k - i) * a;
            if ((hm + dc1 - 1) / dc1 <= (hc1 + dm - 1) / dm) {
                flag = true; 
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl; 
        }
    }
    
    return 0; 
}