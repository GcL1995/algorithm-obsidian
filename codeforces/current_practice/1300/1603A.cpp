#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 25; 

int n; 

int main() {
    int t; 
    cin >> t; 
    while (t -- ) {
        cin >> n; 
        
        bool can = true;
        for (int i = 1; i <= n; i ++ ) {
            int x; 
            cin >> x; 
            bool flag = false;
            for (int j = 2; j <= i + 1; j ++ ) {
                if (x % j) {
                    flag = true;
                    break;
                }
            }
            if (!flag) can &= false;
        }
        if (can) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0; 
}