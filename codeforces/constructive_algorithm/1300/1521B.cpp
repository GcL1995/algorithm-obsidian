#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010; 

int n; 
int w[N]; 

int main() {
    int t; 
    cin >> t; 

    while (t -- ) {
        cin >> n; 
        for (int i = 1; i <= n; i ++ ) cin >> w[i];
        
        int pos = 0, _min; 
        for (int i = 1; i <= n; i ++ ) {
            if (pos == 0 || w[i] < w[pos]) _min = w[i], pos = i; 
        }
          
        cout << n - 1 << endl; 
        
        for (int i = 1; i <= n; i ++ ) {
            if (i < pos) printf("%d %d %d %d\n", i, pos, _min + abs(pos - i), _min);  
            if (i > pos) printf("%d %d %d %d\n", pos, i, _min, _min + abs(pos - i)); 
        }
    }
    return 0; 
}