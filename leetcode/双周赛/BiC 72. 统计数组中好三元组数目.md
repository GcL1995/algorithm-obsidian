# D
#### [5999. 统计数组中好三元组数目](https://leetcode-cn.com/problems/count-good-triplets-in-an-array/)
#树状数组 
~~~c++
typedef long long LL;
const int N = 100010; 
int tr[N]; 

/*
思路：
nums1中从左到右遍历，
对于位置i, 找到在nums2中的对应位置j
找到nums1[0~i - 1]和 nums2[0 ~ j - 1]的交集的大小 (通过树状数组可以求得)
找到nums1[i + 1 ~ n - 1] 和 nums2[j + 1 ~ n - 1]的交集大小 
可以通过总数 - 1 - nums1[i]左边数字个数 - nums2[j] 左边数字个数 + 两者的交集
(n - 1 - i - j + t)
相乘求和

问题转化为如何通过树状数组在logn的时间复杂度内求得 nums1[0~i - 1]和 nums2[0 ~ j - 1]的交集的大小，这个思路就是从左到右遍历的过程中，在nums2相应位置加1，变为求区间和的问题，那么就可以通过树状数组来求解了。
*/
class Solution {
public:
    int n; 
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        memset(tr, 0, sizeof tr);
        n = nums1.size(); 
        vector<int> pos(n, 0);
        for (int i = 0; i < n; i ++ ) pos[nums2[i]] = i;

        LL ans = 0; 
        for (int i = 0; i < n; i ++ ) {
            int j = pos[nums1[i]];
            int t = sum(j + 1);
            
            LL curr = (LL)t * (n - 1 - i - j + t); 
            //printf("%d %d %d %d\n", i, p, t, curr); 
            ans += curr;
            add(j + 1, 1); 
        } 
        return ans; 
    }

    int lowbit(int x) {
        return x & (-x);
    }

    void add(int x, int c) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }

    int sum(int x) {
        int ans = 0; 
        for (int i = x; i > 0; i -= lowbit(i)) ans += tr[i]; 
        return ans; 
    }
};
~~~