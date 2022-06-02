#### [10011. 以组为单位订音乐会的门票](https://leetcode.cn/problems/booking-concert-tickets-in-groups/)
#线段树 
> 题目大意：
> 一共n排座位，每排m个位置
> 给出两种询问
> 第一种问前maxRows排，给出最小的一排的连续k个空位
> 第二种问前maxRows排，是否有k个空位，如果有，优先占最小排的最小座位号
> 
> 提示一：只需要维护n排的remain， 因为一个排只可能占用左边连续的一个空间。
> 提示二：可以使用线段树来维护一个最大remain，同时为了第二种询问，维护一个remain和
> 提示三：query_gather查找一个比要求的连续长度大的第一个remain位置
> 提示四：query_scatter查找前maxRow排的所有空余作为和
> 提示五：query_gather 修改最为简单，只需要找到那一排， 然后循环pushup父节点
> 提示六：query_scatter 修改只需要二分修改，优先修改更小的排即可
~~~c++
const int N = 50010;

int n, m;
int w[N];
struct Node {
    int l, r;
    int remain;
    long sum;
}tr[N * 4];

void pushup(Node &u, Node &l, Node &r) {
    u.remain = max(l.remain, r.remain);
    u.sum = l.sum + r.sum; 
}

void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, m, m};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int k) {
    if (tr[u].l == tr[u].r) {
        tr[u].remain -= k;
        tr[u].sum -= k;
    }else {
        if (tr[u << 1].sum < k) {
            modify(u << 1 | 1, k - tr[u << 1].sum);
            modify(u << 1, tr[u << 1].sum);
        } else {
            modify(u << 1, k);
        }
        pushup(u);
    }
}

int query_gather(int u, int val) {
    if (tr[u].remain < val) return 0;
    if (tr[u].l == tr[u].r) return u;
    else {
        if (tr[u << 1].remain >= val) return query_gather(u << 1, val); 
        else return query_gather(u << 1 | 1, val);
    }
}

bool query_scatter(int u, int val, int maxRow) {
    if (tr[u].r <= maxRow) return tr[u].sum >= val;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (maxRow <= mid) return query_scatter(u << 1, val, maxRow);
        else if (tr[u << 1].sum >= val) return true;
        else return query_scatter(u << 1 | 1, val - tr[u << 1].sum, maxRow); 
    }
}
class BookMyShow {
public:
    BookMyShow(int _n, int _m) {
        n = _n, m = _m; 
        build(1, 1, n); 
    }
    
    vector<int> gather(int k, int maxRow) {
        int u = query_gather(1, k);
        Node &res = tr[u];
        vector<int> ans; 
        if (res.remain >= k && res.l <= maxRow + 1) {
            ans.push_back(tr[u].l - 1);
            ans.push_back(m - res.remain);
            res.remain -= k;
            res.sum -= k;
            
            u >>= 1;
            while (u) {
                pushup(u);
                u >>= 1;
            }
            
        }
        return ans; 
    }
    
    bool scatter(int k, int maxRow) {
        bool ans = query_scatter(1, k, maxRow + 1);
        if (ans) modify(1, k); 
        return ans; 
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
~~~