#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

LL n, m; 

int main() {
    cin >> n >> m; 
    LL k = n / m, r = n % m; 
    LL _min = m * k * (k - 1) / 2 + k * r;
    LL _max = (n - m + 1) * (n - m) / 2;
    printf("%lld %lld\n", _min, _max); 
    
    return 0; 
}