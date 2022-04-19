#### [LCP 52. 二叉搜索树染色](https://leetcode-cn.com/problems/QO5KpG/)
#线段树 #lazy #我就是个天才 
~~~c++
/**
pushdown 懒标记
更新其余值，懒标记更新但不下传
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const int N = 100010;

int n, m;
int w[N];
struct Node {
    int l, r;
    int col, change;
}tr[N * 8];

void pushup(Node &u, Node &l, Node &r) {
    if (l.col == -1 && r.col == -1) u.col = -1;
    else if (l.col == 1 && r.col == 1) u.col = 1;
    else u.col = 0;
}

void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void pushdown(int u) {
    if (tr[u].l == tr[u].r) return; 
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.change == -1) {
        if (left.col != -1) left.col = -1, left.change = -1;
        if (right.col != -1) right.col = -1, right.change = -1;
        root.change = 0;
    } else if (root.change == 1) {
        if (left.col != 1) left.col = 1, left.change = 1;
        if (right.col != 1) right.col = 1, right.change = 1;
        root.change = 0; 
    }
}

void modify(int u, int l, int r, int col) {
    if (tr[u].l >= l && tr[u].r <= r) {
        if (tr[u].col != col) tr[u].col = col, tr[u].change = col; 
    }
    else {    // 一定要分裂
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, col);
        if (r > mid) modify(u << 1 | 1, l, r, col);
        pushup(u);
    }
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, -1, 0};
    else {
        tr[u] = {l, r, 0, 0};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

int query(int u) {
    if (tr[u].l == tr[u].r) return tr[u].col == 1;
    if (tr[u].col == -1) return 0;
    if (tr[u].col == 1) return tr[u].r - tr[u].l + 1;
    return query(u << 1) + query(u << 1 | 1); 
}

vector<int> nums; 
int find(int x) {
    int l = 0, r = nums.size() - 1; 
    while (l < r) {
        int mid = l + r + 1 >> 1; 
        if (nums[mid] <= x) l = mid;
        else r = mid - 1; 
    }
    return l + 1; 
}

class Solution {
public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        nums.clear(); 
        function<void(TreeNode* u)> dfs = [&](TreeNode* u) {
            if (u == nullptr) return; 
            if (u -> left != nullptr) dfs(u -> left);
            nums.push_back(u->val);
            if (u -> right != nullptr) dfs(u -> right); 
        };
        
        dfs(root); 
        
        int n = nums.size(); 
        build(1, 1, n); 
        
        for (auto op: ops) {
            int t = op[0] == 0? -1 : 1, x = find(op[1]), y = find(op[2]);
            modify(1, x, y, t);
        }
        return query(1); 
    }
};
