#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010; 

int n, k; 

int main() {
    int t; 
    cin >> t; 
    
    while (t -- ) {
        cin >> n >> k; 
        string str; 
        cin >> str; 
        
        int pre = - k - 1, ans = 0; 
        for (int i = 0; i < n; i ++ ) {
            if (str[i] == '1') {
                int len = (i - k - 1) - (pre + k + 1) + 1;
                if (len >= 1) ans += (len + k) / (k + 1);
                pre = i;
            }
        }
        int len = n - 1 - (pre + k + 1) + 1; 
        if (len >= 1) ans += (len + k) / (k + 1);
        
        cout << ans << endl;
    }
    return 0; 
}
