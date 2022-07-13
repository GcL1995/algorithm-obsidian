#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010; 

int primes[N], cnt;
bool st[N]; 
int color[N]; 

void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) {
            primes[cnt ++] = i;
            color[i] = cnt;
        }
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[primes[j] * i] = true;
            color[primes[j] * i] = j + 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    int n; 
    cin >> n; 
    
    get_primes(n); 
    for (int i = 2; i <= n; i ++ ) cout << color[i] << ' ';
    cout << endl; 
    
    return 0; 
}
