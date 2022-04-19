#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010; 

int n; 
int w[N], g[N]; 

int main() {
    int t; 
    cin >> t; 
    
    while (t -- ) {
        cin >> n; 
        for (int i = 0; i < n; i ++ ) cin >> w[i]; 
        copy(w, w + n, g); 
        sort(g, g + n);
        
        bool flag = true;
        for (int i = 0; i < n; i ++ ) {
            if (w[i] != g[i] && w[i] % g[0]) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0; 
}