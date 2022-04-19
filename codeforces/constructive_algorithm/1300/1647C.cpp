#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 110; 

int n, m; 
char a[N][N]; 
vector<int> ans[N * N];

int main() {
    int t; 
    cin >> t; 
    while (t -- ) {
        cin >> n >> m;
        //printf("%d %d\n", n, m); 
        for (int i = 1; i <= n; i ++ ) {
            string s;
            cin >> s;
            for (int j = 1; j <= m; j ++ ) a[i][j] = s[j - 1];
        }
        
        if (a[1][1] == '1') cout << "-1" << endl;
        else {
            int k = 0; 
            for (int i = n; i >= 1; i -- ) {
                for (int j = m; j >= 1; j -- ) {
                    if (a[i][j] == '1') {
                        if (j == 1) ans[k ++] = {i - 1,  j,  i, j}; 
                        else ans[k ++] = {i, j - 1, i, j}; 
                    }
                }
            }
            cout << k << endl;
            for (int i = 0; i < k; i ++ ) printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]); 
        }
    }
    return 0; 
}
