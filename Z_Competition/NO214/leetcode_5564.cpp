#include<bits/stdc++.h>
using namespace std;

// Hard


// Segement Tree
class SegTree {
private:
    int n;
    vector<int> segnode;

private:
    void update_(int id, int l, int r, int x) {
        if (l > x || r < x)     return;

        ++segnode[id];
        
        if (l == r)             return;

        int mid = (l + r) >> 1;
        update_(id * 2 + 1, l, mid, x);
        update_(id * 2 + 2, mid + 1, r, x);
    }

    int query_(int id, int l, int r, int ql, int qr) const 
    {
        if (l > qr || r < ql)       return 0;

        if (ql <= l && r <= qr)     return segnode[id];

        int mid = (l + r) >> 1;
        return query_(id * 2 + 1, l, mid, ql, qr) + query_(id * 2 + 2, mid + 1, r, ql, qr);
    }

public:
    SegTree(int _n): n(_n), segnode(_n * 4) {}

    void update(int x) {
        update_(0, 1, n, x);
    }

    int query(int left, int right) const {
        return query_(0, 1, n, left, right);
    }
};


class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int createSortedArray(vector<int>& instructions) 
    {
        int ub = *max_element(instructions.begin(), instructions.end());
        SegTree tree(ub);
        long long ans = 0;
        for (int i = 0; i < instructions.size(); ++i) 
        {
            int x = instructions[i];
            int smaller = tree.query(1, x - 1);
            int larger = tree.query(x + 1, ub);
            ans += min(smaller, larger);
            tree.update(x);
        }
        return ans % mod;
    }
};