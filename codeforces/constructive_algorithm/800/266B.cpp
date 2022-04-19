#include <iostream>

using namespace std;

const int N = 55;

int n, k;
char str[N];

int main() {
    cin >> n >> k;
    
    scanf("%s", str); 
    
    while (k -- ) {
        for (int i = 0; i < n - 1; i ++ ) {
            if (str[i] == 'B' && str[i + 1] == 'G') {
                swap(str[i], str[i + 1]); 
                i ++; 
            }
        }
    }
    
    printf("%s\n", str); 
    
    return 0; 
}