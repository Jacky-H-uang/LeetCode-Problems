// 在一组 N 个人（编号为 0, 1, 2, ..., N-1）中，每个人都有不同数目的钱，以及不同程度的安静（quietness）。
// 为了方便起见，我们将编号为 x 的人简称为 "person x "。
// 如果能够肯定 person x 比 person y 更有钱的话，我们会说 richer[i] = [x, y] 。注意 richer 可能只是有效观察的一个子集。
// 另外，如果 person x 的安静程度为 q ，我们会说 quiet[x] = q 。
// 现在，返回答案 answer ，其中 answer[x] = y 的前提是，在所有拥有的钱不少于 person x 的人中，person y 是最安静的人（也就是安静值 quiet[y] 最小的人）。
//
// 示例：
// 输入：richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
// 输出：[5,5,2,5,4,5,6,7]
// 解释： 
// answer[0] = 5，
// person 5 比 person 3 有更多的钱，person 3 比 person 1 有更多的钱，person 1 比 person 0 有更多的钱。
// 唯一较为安静（有较低的安静值 quiet[x]）的人是 person 7，
// 但是目前还不清楚他是否比 person 0 更有钱。
//
// answer[7] = 7，
// 在所有拥有的钱肯定不少于 person 7 的人中(这可能包括 person 3，4，5，6 以及 7)，
// 最安静(有较低安静值 quiet[x])的人是 person 7。
//
// 其他的答案也可以用类似的推理来解释。
//
// 提示：
//
// 1 <= quiet.length = N <= 500
// 0 <= quiet[i] < N，所有 quiet[i] 都不相同。
// 0 <= richer.length <= N * (N-1) / 2
// 0 <= richer[i][j] < N
// richer[i][0] != richer[i][1]
// richer[i] 都是不同的。
// 对 richer 的观察在逻辑上是一致的。

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

//Medium

class Solution1 {               //hashmap + 广度优先搜索       
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) 
    {
        int N = quiet.size();
        vector<int> answer(N, 0);
        unordered_map<int, vector<int>> hashMap;//hashMap[i]记录着所有比i富有的人
        //第一步：将richer信息转换为hashMap信息
        for (const auto &item : richer)
        {
            hashMap[item[1]].push_back(item[0]);
        }
        //第二步：开始寻找答案
        for (int i = N - 1; i >= 0; --i)
        {
            answer[i] = i;//最安静的人初始化为自己
            queue<int> myQue;
            vector<int> visited(N, 0);//标记访问过的人
            //首先将直接比person i富有的人放入myQue
            for (auto const &richerPerson : hashMap[i])
            {
                //更新最安静的人
                if (quiet[answer[i]] > quiet[richerPerson])
                {
                    answer[i] = richerPerson;
                }
                //放入队列
                if (!visited[richerPerson])
                {
                    visited[richerPerson] = 1;
                    myQue.push(richerPerson);
                }
            }
            //接着寻找间接比person i更富有的人（比person i富有的人j 还富有的人）
            while (!myQue.empty())
            {
                int front = myQue.front();
                myQue.pop();
                //在直接比person front富有的人中更新最安静的人
                for (auto const &richerPerson : hashMap[front])
                {
                    //更新最安静的人
                    if (quiet[answer[i]] > quiet[richerPerson])
                    {
                        answer[i] = richerPerson;
                    }
                    //放入队列
                    if (!visited[richerPerson])
                    {
                        visited[richerPerson] = 1;
                        myQue.push(richerPerson);
                    }
                }
            }
        }
        return answer;
    }
};


class Solution2 {               //hashmap + 广度优先搜索
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) 
    {
              
    }
};