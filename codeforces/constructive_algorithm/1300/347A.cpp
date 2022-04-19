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
    for (int i = 0; i < n; i ++ ) cin >> a[i]; 
    sort(a, a + n); 
    cout << a[n - 1] << endl;
    for (int i = 1; i < n - 1; i ++ ) cout << a[i] << ' ';
    cout << a[0] << endl;
    
    return 0; 
}