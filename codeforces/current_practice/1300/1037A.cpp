#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n; 

int  main() {
    cin >> n; 
    
    int p = 1, i = 0;
    while (p < n) i ++, n -= p, p *= 2;
    cout << i + 1 << endl;
    
    return 0; 
}