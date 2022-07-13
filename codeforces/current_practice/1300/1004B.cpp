#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int n, k; 

int main() {
    cin >> n >> k; 
    for (int i = 0; i < n; i ++ ) {
        if (i % 2) cout << "1";
        else cout << "0";
    }
    cout << endl; 
    
    return 0; 
    
}