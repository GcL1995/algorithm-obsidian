#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std; 

int main() {
    int t; 
    cin >> t; 
    
    while (t -- ) {
        int n; 
        bool flag = false;
        cin >> n; 
        unordered_set<string> S, S2;
        for (int i = 0; i < n; i ++ ) {
            string str;
            cin >> str; 
            if (str.size() == 1) flag = true;
            else if (str.size() == 2) {
                S.insert(str); 
                S2.insert(str); 
                
                reverse(str.begin(), str.end());  
                if (S2.find(str) != S.end()) flag = true;
            }
            else {
                S.insert(str); 
                S2.insert(str.substr(0, 2)); 
                
                reverse(str.begin(), str.end()); 
                
                if (S.find(str) != S.end()) flag = true;
                
                if (S.find(str.substr(0, 2)) != S.end()) flag = true;
                

            }
        }
        
        if (flag) printf("%s\n", "YES"); 
        else printf("%s\n", "NO"); 

    }
    
    return 0; 
}