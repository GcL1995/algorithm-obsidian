#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010; 

int n; 

int main() {
    int t; 
    cin >> t;
    
    
    while (t -- ) {
        cin >> n; 
        int a, b, c = 0; 
        for (int i = 0; i < n; i ++ ) {
            cin >> a;
            b = 0; 
            for (int j = 0; j < 30; j ++ ) {
                if (c >> j & 1 && !(a >> j & 1)) {
                    b += 1 << j;
                }
            }
            cout << b << ' ';
            c = b ^ a;
        }
        cout << endl;
    }
    return 0; 
}