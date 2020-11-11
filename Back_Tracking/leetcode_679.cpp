//              679. 24 点游戏
//
// 你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。
//
//
// 示例 1:
// 输入: [4, 1, 8, 7]
// 输出: True
// 解释: (8-4) * (7-1) = 24
//
//
// 示例 2:
// 输入: [1, 2, 1, 2]
// 输出: False
//
//
// 注意:
// 除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
// 每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
// 你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。


#include<bits/stdc++.h>
using namespace std;

// Hard


// 暴力回溯法
class Solution {
public:
    static constexpr int TARGET = 24;

    // 误差的允许范围是 : 10的-6次方
    static constexpr double EPSILON = 1e-6;

    // 四种运算符  " + "    " - "    " * "    " / "
    static constexpr int ADD = 0;
    static constexpr int MUTIPLY = 1;
    static constexpr int SUBTRACT = 2;
    static constexpr int DIVIDE = 3;
    
    bool solve(vector<double>& l)
    {
        // 如果是计算得到的没有数字就返回 false
        if(l.size() == 0)
        {
            return false;
        }

        // 如果计算得到的最后数字的误差在 EPSILON 之内就返回 true 否则返回 false
        if(l.size() == 1)
        {
            // fabs()  求浮点数的绝对值
            return fabs(l[0]-TARGET) < EPSILON;
        }

        int size = l.size();
        
        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < size; ++j)
            {
                if(i != j)
                {
                    vector<double> list2 = vector<double>();

                    for(int k = 0; k < size; ++k)
                    {
                        if(k != i && k != j)
                        {
                            // 将没选中的数字加入到数组
                            list2.emplace_back(l[k]);
                        }
                    }

                    for(int k = 0; k < 4; ++k)
                    {
                        // 加法和乘法换位的时候可以避免重复而跳过
                        if(k < 2 && i > j)
                        {
                            continue;
                        }

                        if(k == ADD)
                        {
                            list2.emplace_back(l[i] + l[j]);
                        }
                        else if(k == MUTIPLY)
                        {
                            list2.emplace_back(l[i] * l[j]);
                        }
                        else if(k == SUBTRACT)
                        {
                            list2.emplace_back(l[i]-l[j]);
                        }
                        else if(k == DIVIDE)
                        {
                            if(fabs(l[j]) < EPSILON)
                            {
                                continue;
                            }
                            list2.emplace_back(l[i] / l[j]);
                        }

                        if(solve(list2))
                        {
                            return true;
                        }

                        list2.pop_back();
                    }
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& nums) 
    {
        vector<double> l;

        // 将四个数字转换为 double  并存入一个 double 的数组
        for(const int& n : nums)
        {
            l.emplace_back((double)n);
        }

        return solve(l);
    }
};