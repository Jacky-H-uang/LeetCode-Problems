// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""。
//
// 示例 1:
// 输入: ["flower","flow","flight"]
// 输出: "fl"
//
// 示例 2:
// 输入: ["dog","racecar","car"]
// 输出: ""
// 解释: 输入不存在公共前缀。
//
// 说明:
// 所有输入只包含小写字母 a-z 
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Easy
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int l = strs.size();
        if(l<=0)
        {
            return "";
        }
        int len = strs[0].size();
        int flag = 1;
        string result = "";
        int j = 0;
        while(j<len)
        {
            for(int i=1;i<l;i++)
            {
                if(strs[0][j] != strs[i][j])
                {
                    flag = -1;
                    break;
                }
            }
            if(flag == 1)
            {   
                result += strs[0][j];
            }
            
            if(flag == -1)
            {
                break;
            }
            j++;
        }
        return result;
    }
};

int main()
{
    vector<string> v ={"aca","cba"};
    Solution s;
    string r = s.longestCommonPrefix(v);
    cout<<r<<endl;
    system("pause");
    return 0;
}