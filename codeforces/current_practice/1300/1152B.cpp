#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef unsigned long long ULL;

int get(int x) {
    for (int i = 20; i >= 0; i -- ) {
        if (x >> i & 1) return i;
    }
    return 0; 
}

int  main() {    
    int x;
    cin >> x;
    
    vector<int> ans; 
    int i;
    for (i = 0; ; i += 2 ) {
        if (x <= 1) break;
        int k = get(x);
        
        int y = (1 << k + 1) - 1;
        if ((y ^ x) + 1 == x) {
            ans.push_back(k); 
            i += 1;
            break;
        }
        else {
            ans.push_back(k + 1);
            x = (y ^ x) + 1;
        }
    }
    
    cout << i << endl;
    if (i == 0) return 0; 
    for (auto v: ans) {
        cout << v << ' ';
    }
    cout << endl; 
    
    
    return 0; 
}