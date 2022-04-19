#include <iostream>
#include <cstring>
#include <queue>


using namespace std;

typedef long long LL; 

const int N = 2010; 

int n; 

int main() {
    cin >> n; 
    
    LL res = 0; 
    priority_queue<LL, vector<LL>, greater<LL>> heap;  
    

    for (int i = 1; i <= n; i ++ ) {
        int x; 
        scanf("%d", &x); 
        heap.push(x); 
        res += x; 
        if (res < 0) {
            res -= heap.top(); 
            heap.pop(); 
        }
    }

    printf("%d\n", heap.size()); 
    return 0; 
}