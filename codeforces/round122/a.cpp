#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int main() {
    int t; 
    cin >> t;
    
    while (t -- ) {
        int x; 
        cin >> x; 
        if (x % 7 == 0) {
            printf("%d\n", x); 
            continue;
        }
        
        int a = x / 100, b = x / 10 % 10, c = x % 10;
        //printf("%d %d %d\n", a, b, c); 
        int res = 1; 
        for (int i = 1; i < 10; i ++ ) {
            if (a != 0) res = i * 100 + b * 10 + c;
            if (res % 7 == 0) break;
            if (a != 0 || b != 0) res = a * 100 + i * 10 + c;
            if (res % 7 == 0) break;
            res = a * 100 + b * 10 + i;
            if (res % 7 == 0) break;
        }
        
        if (res % 7 == 0) {
            printf("%d\n", res);
            continue;
        }
        for (int i = 1; i < 10; i ++ ) {
            for (int j = 1; j < 10; j ++ ) {
                if (a != 0) res = i * 100 + j * 10 + c;
                if (res % 7 == 0) break;
                if (a != 0 || b!= 0) res = a * 100 + i * 10 + j;
                if (res % 7 == 0) break;
                res = i * 100 + b * 10 + j;
                if (res % 7 == 0) break;
            }
            if (res % 7 == 0) break;
        }
        if (res % 7 == 0) {
            printf("%d\n", res); 
            continue;
        }
        printf("%d\n", 777); 
        
    }
    return 0; 
}