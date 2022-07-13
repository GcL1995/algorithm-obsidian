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

const int N = 110; 

int n; 
int a[N]; 

int  main() {    
    cin >> n;  
    
    if (n % 2 == 0) {
        if (n % 4 == 0) cout << 0 << endl; 
        else cout << 1 << endl; 
        cout << n / 2 << ' '; 
        int cnt = 0, i = 1; 
        while (cnt < n / 2) {
            if (n / 2 - cnt > 1) {
                cout << i << ' ' << n + 1 - i << ' ';
                cnt += 2;
                i ++;
            } else {
                cout << (n / 2) << endl;
                break;
            }
        }
    }
    else {
        if ((n - 1) % 4 == 0) cout << 1 << endl; 
        else cout << 0 << endl; 
        
        cout << n / 2 + 1 << ' '; 
        cout << 1 << ' '; 
        int cnt = 0, i = 2; 
        while (cnt < n / 2) {
            if (n / 2 - cnt > 1) {
                cout << i << ' ' << n + 2 - i << ' ';
                cnt += 2;
                i ++;
            } else {
                cout << (n - 1) / 2 + 1 << endl;
                break; 
            }
        }
    }
    
    return 0; 
}