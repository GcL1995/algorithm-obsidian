#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;



int main() {
    int t; 
    cin >> t;
    
    while (t -- ) {
        string str; 
        cin >> str; 
        int n = str.size(); 
        vector<int> f(n + 1), g(n + 1); 
        
        int res = 0; 
        for (int i = 1; i <= n; i ++ ) {
            if (str[i - 1] == '0') {
                g[i] = g[i - 1] + 1;
                f[i] = f[i - 1];
            } 
            else {
                g[i] = g[i - 1]; 
                f[i] = f[i - 1] + 1;
            }
            
            if (i != 1 && g[i] != f[i]) {
                res = min(g[i], f[i]);
            }
        }
       
        f[n] = 0, g[n] = 0;
        for (int i = n - 1; i >= 0; i -- ) {
            if (str[i] == '0') {
                g[i] = g[i + 1] + 1;
                f[i] = f[i + 1];
            }
            else {
                g[i] = g[i + 1];
                f[i] = f[i + 1] + 1;
            }
            if (i != n - 1 && f[i] != g[i]) {
                res = max(res, min(f[i], g[i])); 
            }
        } 
        printf("%d\n", res); 
        
    }
    return 0; 
}