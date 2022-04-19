#include <iostream>
#include <cstring>

using namespace std; 

const int N = 2010; 

int t; 
int cnt[26];
char str[N];

int main() {
    cin >> t;
    while (t -- ) {
        int n, x, y;
        cin >> n >> x >> y; 
        int k = 0; 
        
        memset(cnt, 0, sizeof cnt); 
        
        int hh = 0, tt = -1; 
        for (int i = 0; i < n; i ++ ) {
            if (i >= x) {
                if (-- cnt[str[i - x] - 'a'] == 0) k --; 
                hh ++;
            }
            for (int j = 0; j < 26; j ++ ) {
                if (k < y && cnt[j] == 0) {
                    cnt[j] ++;
                    k ++;
                    str[i] = 'a' + j;
                    break;
                }
                
                if (k == y && cnt[j] >= 1) {
                    cnt[j] ++;
                    str[i] = 'a' + j;
                    break;
                }
        
            }

        }

        str[n] = '\0';
        printf("%s\n", str); 

    }
    return 0; 
}