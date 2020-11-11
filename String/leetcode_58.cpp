// 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
//
// 如果不存在最后一个单词，请返回 0 。
//
// 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
//
//  
// 示例:
// 输入: "Hello World"
// 输出: 5

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//Easy
class Solution1 {                                           //正序遍历
public:
    int lengthOfLastWord(string s) 
    {
        int len = s.size();
        int p1 = 0;
        int p2 = 0;
        if(len == 0)
        {
            return 0;
        }
        for(int i=0;i<len;i++)
        {
            if(s[i] == ' ' && s[i+1] != ' ' && s[i+1])
            {
                p1 = i;
            }
            if(s[i] != ' ')
            {
                p2 = i;
            }
        }
        if(p1 == 0 && s[p1] != ' ')
        {
            return p2+1-p1;
        }
        return p2-p1;
    }
};

class Solution2 {                                           //逆序遍历
public:
    int lengthOfLastWord(string s) 
    {
        int len = s.size();
        int p1 = 0;
        int p2 = 0;
        int flag = 0;
        for(int i=len;i>0;i--)
        {
            if( flag == 0 && s[i-1] != ' ')
            {
                p2 = i;
                flag++;
            }
            if(flag == 1 && s[i-1] == ' ')
            {
                p1 = i;
                break;
            }
        }
        return p2-p1;
    }
};
int main()
{
    string a = " day "; 
    Solution2 s;
    int r = s.lengthOfLastWord(a);
    cout<<r<<endl;
    system("pause");
    return 0;
}