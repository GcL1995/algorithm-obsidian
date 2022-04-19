#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, x;

int main() {
    cin >> n >> m >> x;
    string s = "";
    int pre;
    if (n >= m) {
        s += '0';
        n --;
        pre = 0;
    } else {
        s += '1';
        m --;
        pre = 1;
    }
    
    while (x > 1) {
        pre = 1 - pre;
        if (pre == 0) n --;
        else m --;
        s += '0' + pre;
        x --;
    }
    
    if (pre == 0) {
        while (n -- ) s += '0';
        while (m -- ) s += '1';
    } else {
        while (m -- ) s += '1';
        while (n -- ) s += '0';
    }
    
    cout << s << endl; 
    
    return 0; 
}