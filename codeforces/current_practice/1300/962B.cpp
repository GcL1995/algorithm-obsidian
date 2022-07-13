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

string str;
int n, a, b;

int  main() {    
    cin >> n; 
    cin >> a >> b;
    cin >> str;
    
    int m = str.size(), pre = -1, res = 0; 
    for (int i = 0; i < m;) {
        if (str[i] == '*') {
            pre = i;
            i ++;
            continue;
        }    
        int j = i;
        while (j + 1 < n && str[j + 1] == '.') j ++;
        int k = j - pre;
        
        if (a < b) swap(a, b);
        while (a > 0 && b > 0 && k > 1) {
            a --, b --, k -= 2, res += 2;
        }
        while (a > 0 && k > 0)  {
            a --, k -= 2, res += 1;
        }
        
        i = j + 1;
    }
    
    cout << res << endl;
    
    return 0; 
}