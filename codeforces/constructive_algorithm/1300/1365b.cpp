#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510; 

int n; 
int a[N], b[N]; 

int main() {
    int t; 
    cin >> t;
    
    while (t -- ) {
        cin >> n; 
        for (int i = 0; i < n; i ++ ) cin >> a[i];
        for (int i = 0; i < n; i ++ ) cin >> b[i]; 
        
        bool flag = true;
        for (int i = 0; i < n - 1; i ++ ) {
            if (a[i] > a[i + 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
            continue;
        }
        
        int zeros = 0, ones = 0; 
        for (int i = 0; i < n; i ++ ) {
            if (b[i]) ones ++;
            else zeros ++;
        }
        if (zeros && ones) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0; 
}