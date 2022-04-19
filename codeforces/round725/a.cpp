#include <iostream>

using namespace std; 

const int N = 110; 

int t; 
int a[N];

int main() {
    cin >> t; 
    
    while (t -- ) {
        int n, l;
        cin >> n >> l;
        
        for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]); 

        
        int res = 0; 
        for (int i = 0; i < l; i ++ ) {
            int cnt = 0; 
            for (int j = 0; j < n; j ++ ) {
                cnt += (a[j] >> i) & 1;
            }
            //printf("%d %d\n", i, cnt); 
            if (cnt > n / 2) res += 1 << i;
        }
        
        printf("%d\n", res); 
    }
    
    return 0; 
}