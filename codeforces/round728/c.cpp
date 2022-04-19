#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t, n, k;

int C(int x) {
    return x ^ (n - 1);
}

int main() {
    cin >> t;
    
    while (t -- ) {
        cin >> n >> k;
        if (k == 0) {
            for (int i = 0; i < n / 2 ; i ++ ) {
                printf("%d %d\n", i, C(i)); 
            }
        }
        else if (k < n - 1) {
            printf("%d %d\n", 0, C(k));
            printf("%d %d\n", n - 1, k); 
            for (int i = 0; i < n / 2; i ++ ) {
                if (i == 0 || i == k || i == C(k)) continue;
                printf("%d %d\n", i, C(i)); 
            }
        }
        else {
            if (n - 3 <= 2) {
                printf("%d\n", -1); 
                continue;
            }
            printf("%d %d\n", 0, 2); 
            printf("%d %d\n", n - 2, n - 1); 
            printf("%d %d\n", n - 3, 1);
            for (int i = 0; i < n / 2; i ++ ) {
                if (i == 0 || i == 2 || i == 1) continue;
                printf("%d %d\n", i, C(i)); 
            }
        }
    }
    
    return 0; 
}