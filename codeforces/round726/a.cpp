#include <iostream>
#include <unordered_map>

using namespace std; 

const int N = 55;

char g[N][N];

int main() {
    int t; 
    cin >> t; 
    while (t -- ) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        for (int i = 0; i < n; i ++ ) scanf("%s", g[i]); 
        
        if (g[r - 1][c - 1] == 'B') {
            printf("%d\n", 0);
            continue;
        }
        
        int flag = 0;
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                if (g[i][j] == 'B') {
                    flag = 1;
                    if (i == r - 1 || j == c - 1) {
                        flag = 2; 
                        break;
                    }
                } 
            }
            if (flag == 2) break;
        }
        if (flag == 2) {
            printf("%d\n", 1); 
        } else if (flag == 1) {
            printf("%d\n", 2);
        } else {
            printf("%d\n", -1);
        }
        
    }
    
    return 0; 
}