#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

const int N = 100010; 

int main() {
    int t; 
    cin >> t;
    
    while (t -- ) {
        int n, m; 
        scanf("%d%d", &n, &m); 
        vector<int> g;
        for (int i = 0; i < n; i ++ ) 
            for (int j = 0; j < m; j ++ ) 
                g.push_back(max(i, n - i - 1) + max(j, m - j - 1)); 
        
        sort(g.begin(), g.end()); 

        for (int i = 0; i < n * m; i ++ ) {
            printf("%d ", g[i]); 
        }
        printf("\n"); 
    }
    
    return 0; 
}