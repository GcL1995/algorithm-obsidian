#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PLI;

int main() {
    int t; 
    cin >> t;
    
    while (t -- ) {
        LL n;
        cin >> n;
        LL x = n; 
        vector<PLI> primes;
        for (LL i = 2; i <= x / i; i ++ ) {
            int cnt = 0; 
            while (x % i == 0) {
                x /= i;
                cnt ++;
            }
            if (cnt > 0) primes.push_back({i, cnt}); 
        }
        if (x > 1) primes.push_back({x, 1});
        
        sort(primes.begin(), primes.end(), [&](auto &x, auto &y){return x.second > y.second;}); 
        int k = primes[0].second;
        cout << k << endl; 
        for (int i = 0; i < k - 1; i ++ ) {
            cout << primes[0].first << ' '; 
            n /= primes[0].first;
        }
        cout << n << endl; 
    }
    return 0; 
}