#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std; 


int main() {
    int t; 
    cin >> t;
    
    while (t -- ) {
        unordered_map<int, queue<int>> f; 
        int n;
        scanf("%d", &n); 
        for (int i = 1; i <= n; i ++ ) {
            int x;
            scanf("%d", &x); 
            f[x].push(i); 
        }
        
        int i = 0; 
        vector<int> res; 
        
        while (f[0].size()) {
            int j = -1; 
            while (j + 1 <= n + 1 && f[j + 1].size()) {
                j ++;
                i = max(i, f[j].front());
            }
            
            res.push_back(j + 1);
            
            for (int k = 0; k <= j; k ++ ) {
                while (f[k].size() && f[k].front() <= i) f[k].pop(); 
            }
             
        }
        printf("%d\n", res.size() + (n - i)); 
        for (auto t: res) printf("%d ", t);
        for (int j = 0; j < n - i; j ++ ) printf("%d ", 0);  
        printf("\n"); 
    }
    
    return 0; 
    
}