#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10; 

char g[N][N]; 

int main() {
    int t; 
    cin >> t; 
    while (t -- ) {
        for (int i = 0; i < 9; i ++ ) scanf("%s", g[i]); 
        for (int i = 0; i < 9; i ++ ) {
            for (int j = 0; j < 9; j ++ ) {
                if (g[i][j] == '1') g[i][j] = '9';
            }
        }
        
        for (int i = 0; i < 9; i ++ ) cout << g[i] << endl;
    }
    
    return 0; 
}