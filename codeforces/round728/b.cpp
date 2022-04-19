#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010; 

int t;
int n; 
int w[N]; 

int main() {
    cin >> t;
    while (t -- ) {
        cin >> n; 
        for (int i = n; i >= 1; i -- ) scanf("%d", &w[i]); 
        
        int res = 0;
        for (int i = 1; i <= n;) {
            int j = i;
            while (j + 1<= n && w[j + 1] == w[1]) j ++;
            
            if (j < n) res ++;
            //printf("%d %d\n", i, j); 
            i = 2 * j;
        }
        
        printf("%d\n", res); 
    }
    return 0; 
}