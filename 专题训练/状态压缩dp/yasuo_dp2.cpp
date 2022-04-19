#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> PII; 
typedef long long LL; 

const int N = 20; 

int n, m; 
unordered_map<int, vector<PII>> condi; 
LL f[1 << N]; 

bool check(int i, int c) {
    for (auto [y, z]: condi[c + 1]) {
        int cnt = 0; 
        for (int j = 0; j < y; j ++ ) {
            cnt += i >> j & 1;
        }
        if (cnt > z) return false; 
    }
    return true; 
}

int main() {
    cin >> n >> m; 
    for (int i = 0; i < m; i ++ ) {
        int x, y, z;
        cin >> x >> y >> z;
        condi[x].push_back({y, z}); 
    }
    
    f[0] = 1;
    for (int i = 0; i < 1 << n; i ++ ) {
        int c = 0; 
        for (int j = 0; j < n; j ++ ) c += i >> j & 1;
        
        for (int j = 0; j < n; j ++ ) {
            if (i >> j & 1) continue;
            if (check(i | 1 << j, c)) f[i | 1 << j] += f[i];
        }
    }
    cout << f[(1 << n) - 1] << endl; 
    
    return 0; 
}