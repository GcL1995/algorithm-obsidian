#include <iostream>
#include <algorithm>

using namespace std; 

typedef pair<int, int> PII;

const int N = 300010, M = 30 * 300010; 

struct Node {
    int l, r, v;
    int prefix, level;
    int fa; 
} tr[M]; 

int n, m; 
int idx; 
PII g[N]; 
int f[N];

int res; 

void pushup(int u) {
    tr[u].v = max(tr[tr[u].l].v, tr[tr[u].r].v);
}


void insert(int x) {
    int p = 0; 
    for (int i = 29; i >= 0; i -- ) {
        int u = (x >> i) & 1;
        if (u == 0) {
            if (!tr[p].l) {
                tr[p].l = ++ idx; 
                tr[idx].fa = p; 
                tr[idx].prefix = tr[p].prefix;
                tr[idx].level = i;
            }
            p = tr[p].l;
        }
        else {
            if (!tr[p].r) {
                tr[p].r = ++ idx;
                tr[idx].fa = p; 
                tr[idx].prefix = tr[p].prefix + (1 << i); 
                tr[idx].level = i;
            }
            p = tr[p].r;
        }
    }
}

void dfs(int u, int x) {
    if (tr[u].v <= res) return;
    
    int level = tr[u].level;
    if ((tr[u].prefix ^ (x >> level << level)) >= m) {
        res = max(res, tr[u].v); 
        return; 
    }
    
    if ((tr[u].prefix ^ (x >> level << level)) < m - (1 << (level + 1))) return; 
    
    if (tr[u].l) dfs(tr[u].l, x);
    if (tr[u].r) dfs(tr[u].r, x); 
}


int main() {
    cin >> n >> m; 
    if (m == 0) {
        printf("%d\n", n); 
        for (int i = 1; i <= n; i ++ ) printf("%d ", i); 
        return 0; 
    }
    
    for (int i = 1; i <= n; i ++ ) scanf("%d", &g[i].first);
    for (int i = 1; i <= n; i ++ ) g[i].second = i; 
    sort(g + 1, g + n + 1); 
    
    
    tr[0].level = 30; 
    for (int i = 1; i <= n; i ++ ) {
        insert(g[i].first); 
        
        
        res = 0; 
        dfs(0, g[i].first); 
        
        
        
        f[i] = res + 1;
        tr[idx].v = res + 1;
        
        int j = idx;
        while (j) {
            pushup(tr[j].fa);
            j = tr[j].fa;
        }

        pushup(tr[idx].fa); 
         
    }
    
    int ans = 0, j; 
    for (int i = 1; i <= n; i ++ ) {
        if (f[i] > ans) {
            ans = f[i], j = i;
        }
    }
    if (ans == 1) {
        printf("%d", -1);
        return 0; 
    }
    
    printf("%d\n", ans); 
    int pre = 1 << 30; 
    for (int i = j;i >= 1; i -- ) {
        if ((pre ^ g[i].first) >= m && f[i] == ans) {
            printf("%d ", g[i].second);
            pre = g[i].first; 
            ans --; 
        }
    }
    return 0; 
}

