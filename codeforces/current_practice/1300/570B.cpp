#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m; 

int main() {
    cin >> n >> m; 
    if (n - m > m - 1) cout << m + 1 << endl;
    else cout << max(1, m - 1) << endl;
    
    return 0; 
}