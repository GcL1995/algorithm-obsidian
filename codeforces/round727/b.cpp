#include <iostream>

using namespace std; 

int main() {
    int t; 
    cin >> t;
    while (t -- ) {
        int l, r, k; 
        scanf("%d%d%d", &l, &r, &k); 
        
        if (l == 1 && r == 1) {
            printf("%s\n", "NO");
            continue;
        }
        
        if (l == r) {
            printf("%s\n", "YES");
            continue;
        }
        
        int odd = ((r - l) + 1 - ((l % 2) == 0) - ((r % 2) == 0) + 1) / 2;
        //printf("%d\n", odd); 
        if (odd <= k) {
            printf("%s\n", "YES");
        } 
        else {
            printf("%s\n", "NO"); 
        }
    }
    
    return 0; 
    
}