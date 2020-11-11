// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。
//
// 示例 1:
// 输入: "()"
// 输出: true
//
// 示例 2:
// 输入: "()[]{}"
// 输出: true
//
// 示例 3:
// 输入: "(]"
// 输出: false
//
// 示例 4:
// 输入: "([)]"
// 输出: false
//
// 示例 5:
// 输入: "{[]}"
// 输出: true

#include<iostream>
#include<string>
#include<map>
#include<stack>
using namespace std;

//Easy
class Solution {
public:
    bool isValid(string s) 
    {
        map<char,char> mp;
        mp.insert(pair<char,char>('[',']'));
        mp.insert(pair<char,char>('{','}'));
        mp.insert(pair<char,char>('(',')'));
        stack<char> st;
        if(s.empty())
        {
            return true;
        }
        int len = s.size();
        int i = 1;
        st.push(s[0]);
        while (i<len)
        {
            if(mp[st.top()] == s[i])
            {
                st.pop();
                i++;
                if(st.empty() && i<len)
                {
                    st.push(s[i]);
                    i++;
                }
            }
            else
            {
                st.push(s[i]);
                i++;
            }
        }
        return st.empty(); 
    }
};

int main()
{
    Solution s;
    string a = "[]{}()";
    bool r = s.isValid(a);
    if(r)
    {
        cout<<"True!"<<endl;
    }
    else
    {
        cout<<"False!"<<endl;
    }
    system("pause");
    return 0;
}