#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int t, n; 

int main() {
    cin >> t;
    
    while(t -- ) {
        cin >> n;
        int k = 0; 
        while (1 << k + 1 <= n - 1) k ++; 
        for (int i = (1 << k) - 1; i >= 0; i -- ) cout << i << ' '; 
        for (int i = 1 << k; i <= n - 1; i ++ ) cout << i << ' '; 
        cout << endl; 
    }
    return 0; 
}