## 打表
~~~c++
/*
通过声明静态变量，调用静态函数(同时是lambda函数)方式
*/
const int mx = 100001;
vector<int> divisors[mx];

int init = []() { // 预处理每个数的所有因子，时间复杂度 O(MlogM)，M=1e5
    for (int i = 1; i < mx; ++i)
        for (int j = i; j < mx; j += i)
            divisors[j].push_back(i);
    return 0;
}();
~~~

## lambda
~~~c++
function<vector<LL>(vector<vector<PII>>&, int)> dijkstra = [&](vector<vector<PII>> &ne, int start){
	vector<LL> dist(n, 1e10); 
	vector<bool> st(n, false); 
	priority_queue<PLI, vector<PLI>, greater<PLI>> heap; 
	
	dist[start] = 0; 
	heap.push({0, start}); 

	while (heap.size()) {
		auto t = heap.top(); 
		heap.pop(); 
		LL distance = t.x;
		int ver = t.y;

		if (st[ver]) continue; 

		st[ver] = true;
		for (auto &u: ne[ver]) {
			int b = u.x, c = u.y; 

			if (dist[b] > dist[ver] + c) {
				dist[b] = dist[ver] + c;
				heap.push({dist[b], b}); 
			}
		}
	}
	return dist; 
};
~~~

## 优先队列
### 自定义函数
~~~c++
auto cmp = [&](const pair<int, int>& x, const pair<int, int>& y) {
	return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
~~~

### 重载运算符一
~~~c++
template <typename T>
class cmp {
public:
    bool operator()(T a, T b) {
        return w[a.x] * w[b.y] > w[a.y] * w[b.x];
    }
};
priority_queue<PII, vector<PII>, ::cmp<PII>> heap;
~~~
### 重载运算符二
~~~c++
struct PIS {
    int x;
    string y;
};
bool operator < (PIS a, PIS b) {
    return a.x == b.x? a.y < b.y: a.x > b.x;
}

bool operator > (PIS a, PIS b) {
    return a.x == b.x? a.y > b.y: a.x < b.x;
}
priority_queue<PIS, vector<PIS>, greater<PIS>> heap;
~~~
### 相关题目
[[LC 786. 第 K 个最小的素数分数]]