#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 150010; 

int t; 
int a[N]; 

int main() {
    cin >> t;
    unordered_map<int, vector<int>> s;
    while (t -- ) {
        int n;
        cin >> n; 
        s.clear();
        
        for (int i = 0; i < n; i ++ ) {
            int x; 
            scanf("%d", &x); 
            s[x].push_back(i); 
        }
        
        int res = -1; 
        for (auto& [x, a]: s) {
            int len = a.size(); 
            if (len > 1) {
                for (int i = 0; i < len - 1; i ++ ) {
                    //printf("%d %d %d\n", a[i], a[i + 1], len); 
                    res = max(res, a[i] + n - a[i + 1]);
                }
            }
        }
        printf("%d\n", res); 
    }
    return 0; 
}