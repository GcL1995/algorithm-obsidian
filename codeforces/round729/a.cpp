#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int main() {
    int t; 
    cin >> t; 
    while (t -- ) {
        int n;
        string str; 
        
        cin >> n; 
        cin >> str; 
        int ones = 0; 
        for (char c: str) {
            if (c == '1') ones ++;
        }
        
        bool flag;
        if (n == 1) flag = true;
        else if (n == 2 && ones == 1) flag = true;
        else flag = false;
        
        if (!flag) printf("%s\n", "NO"); 
        else printf("%s\n", "YES"); 
    }
    
    return 0; 
    
}