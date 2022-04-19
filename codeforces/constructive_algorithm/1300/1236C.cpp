#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 310; 

int g[N][N]; 

using namespace std;

int n; 

int main() {
    cin >> n; 
    for (int i = 0; i < n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            int x;
            if (i % 2 == 0) x = n * i + j;
            else x = n * (i + 1) + 1 - j;
            g[i][j] = x;
        }
    }
    
    for (int j = 1; j <= n; j ++ ) {
        for (int i = 0; i < n; i ++ ) {
            cout << g[i][j] << ' ';
        }
        cout << endl; 
    }
    
    return 0; 
}