#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110; 

int t;
int a[N], b[N]; 

int main() {
    cin >> t; 
    while (t -- ) {
        int n; 
        cin >> n; 
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]); 
        for (int i = 1; i <= n; i ++ ) scanf("%d", &b[i]); 
        
        for (int i = 1; i <= n; i ++ ) {
            if (a[i] < b[i]) {
                int t = a[i]; 
                a[i] = b[i]; 
                b[i] = t; 
            }
        }
        
        sort(a + 1, a + n + 1); 
        sort(b + 1, b + n + 1); 
        printf("%d\n", a[n] * b[n]); 
    }
    
    return 0; 
}