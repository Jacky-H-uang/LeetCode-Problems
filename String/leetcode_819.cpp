/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 *
 * https://leetcode-cn.com/problems/most-common-word/description/
 *
 * algorithms
 * Easy (39.93%)
 * Likes:    58
 * Dislikes: 0
 * Total Accepted:    10.4K
 * Total Submissions: 26K
 * Testcase Example:  '"Bob hit a ball, the hit BALL flew far after it was hit."\n["hit"]'
 *
 * 给定一个段落 (paragraph) 和一个禁用单词列表 (banned)。返回出现次数最多，同时不在禁用列表中的单词。
 * 
 * 题目保证至少有一个词不在禁用列表中，而且答案唯一。
 * 
 * 禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: 
 * paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
 * banned = ["hit"]
 * 输出: "ball"
 * 解释: 
 * "hit" 出现了3次，但它是一个禁用的单词。
 * "ball" 出现了2次 (同时没有其他单词出现2次)，所以它是段落里出现次数最多的，且不在禁用列表中的单词。 
 * 注意，所有这些单词在段落里不区分大小写，标点符号需要忽略（即使是紧挨着单词也忽略， 比如 "ball,"）， 
 * "hit"不是最终的答案，虽然它出现次数更多，但它在禁用单词列表中。
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= 段落长度 <= 1000
 * 0 <= 禁用单词个数 <= 100
 * 1 <= 禁用单词长度 <= 10
 * 答案是唯一的, 且都是小写字母 (即使在 paragraph 里是大写的，即使是一些特定的名词，答案都是小写的。)
 * paragraph 只包含字母、空格和下列标点符号!?',;.
 * 不存在没有连字符或者带有连字符的单词。
 * 单词里只包含字母，不会出现省略号或者其他标点符号。
 * 
 * 
 */

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


// @lc code=start

// 实现一个散列表 hashtable
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        transform(paragraph.begin(),paragraph.end(),paragraph.begin(),::tolower);
        string a = "";
        unordered_map<string,int> count;
        unordered_map<string,int> count_banned;
        for(int i=0;i<banned.size();i++)
        {
            count_banned[banned[i]]++;    
        }
        for(int i=0;i<paragraph.size();i++)
        {
            if(paragraph[i] == ' ' || paragraph[i] == '.' || paragraph[i] == '?' || paragraph[i] == '!' || paragraph[i] == ';'|| paragraph[i] ==',' || paragraph[i]== '\'')
            {
                if(a == "")
                {
                    continue;
                }
                count[a]++;
                a = "";
                continue;
            }
            a += paragraph[i];
            if(i +1==paragraph.size())
            {
                count[a]++;
            }
        }
        int times = 0;
        string r;
        unordered_map<string,int>::iterator it;
        for(it = count.begin();it!=count.end();it++)
        {
            if(count_banned[it->first] == 1)
            {
                continue;
            }
            if(it->second > times)
            {
                times = it->second;
                r = it->first;
            }
        }
        return r;
    }
};
// @lc code=end


int main()
{
    string a = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> v = {"hit"};
    Solution s;
    cout<<s.mostCommonWord(a,v)<<endl;
    system("pause");
    return 0;
}