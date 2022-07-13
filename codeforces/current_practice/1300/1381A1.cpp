#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010; 

int n; 
string a, b; 
int op[3 * N]; 

void change(string &a, int k) {
    string c = a; 
    for (int i = 0; i < k; i ++ ) {
        if (c[k - i - 1] == '1') a[i] = '0';
        else a[i] = '1';
    }
} 

int main() {
    int t; 
    cin >> t; 
    
    while (t -- ) {
        cin >> n;
        cin >> a;
        cin >> b; 
        
        int k = 0; 
        for (int i = n - 1; i >= 0; i -- ) {
            if (a[i] != b[i]) {
                if (a[0] != b[i]) {
                    op[k ++] = i + 1;
                    change(a, i + 1); 
                }
                else {
                    op[k ++] = 1, op[k ++ ] = i + 1; 
                    change(a, 1), change(a, i + 1); 
                }
            }
        }
        cout << k << ' '; 
        for (int i = 0; i < k; i ++ ) cout << op[i] << ' '; 
        cout << endl; 
    }
    return 0; 
}
