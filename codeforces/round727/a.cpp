#include <iostream>
#include <algorithm>

using namespace std; 

typedef pair<int, int> PII;

const int N = 110;

PII a[N];

int main() {
    int t; 
    cin >> t;
    while (t -- ) {
        int n, k; 
        scanf("%d%d", &n, &k); 
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i].first); 
        for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i].second); 
        
        sort(a + 1, a + n + 1); 
        int res = k, i = 1; 
        while (i <= n && res >= a[i].first) {
            res += a[i].second;
            i ++;
        }
        printf("%d\n", res); 
    }
    
    return 0; 
    
}