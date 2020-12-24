//                                      365. 水壶问题
// 有两个容量分别为 x升 和 y升 的水壶以及无限多的水。
// 请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
// 如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。
//
// 你允许：
// 装满任意一个水壶
// 清空任意一个水壶
// 从一个水壶向另外一个水壶倒水，直到装满或者倒空
//
// 示例 1: (From the famous "Die Hard" example)
// 输入: x = 3, y = 5, z = 4
// 输出: True
// 示例 2:
// 输入: x = 2, y = 6, z = 5
// 输出: False



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 欧几里德算法来求最大公约数
    int gcd(int p, int q) {
        if (q == 0)     return p;
        int r = p % q;
        return gcd(q,r);
    }

    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z) {
            return false;
        }
        if(x == 0 || y == 0) {
            return z == 0 || x + y == z;
        }
        // 找到 x 和 y 的最大公约数看是否能被 z 整除
        int min_num = gcd(x,y);

        return z % min_num == 0;
    }
};