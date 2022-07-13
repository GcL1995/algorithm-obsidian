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


const int N = 100010, INF = 1e9;

int t;

int  main() {    
    cin >> t;
    while (t -- ) {
        int a, b, c, d; 
        cin >> a >> b >> c >> d; 
        
        bool positive;
        if ((a + b) % 2) positive = false;
        else positive = true;
        
        bool big = false;
        if (a || d) big = true;
        
        bool small = false;
        if (b || c) small = true;
        
        if (!positive && big) cout << "Ya ";
        else cout << "Tidak ";
        
        if (!positive && small) cout << "Ya ";
        else cout << "Tidak ";
        
        if (positive && small) cout << "Ya ";
        else cout << "Tidak ";
        
        if (positive && big) cout << "Ya ";
        else cout << "Tidak ";
        
        cout << endl; 
    }
    
    return 0; 
}