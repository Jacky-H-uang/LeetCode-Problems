// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
// 说明：本题中，我们将空字符串定义为有效的回文串。
//
// 示例 1:
// 输入: "A man, a plan, a canal: Panama"
// 输出: true
//
// 示例 2:
// 输入: "race a car"
// 输出: false



#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//Easy

class Solution {
public:
    bool isPalindrome(string s) 
    {
        
        string copy;
        transform(s.begin(),s.end(),s.begin(),::toupper);
        for(int i=0;i<s.size();i++)
        {
            if((s[i] >= '0' && s[i] <= '9') || (s[i]>='A' && s[i]<='Z'))
            {
                copy.push_back(s[i]);
            }
        }
        string temp = copy;
        reverse(copy.begin(),copy.end());
        if(temp == copy)
        {
            return true;
        }
        else
        {
            return false;
        }
        return true;
    }
};



int main()
{
    Solution s;
    string a = "race a car";
    if(s.isPalindrome(a))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    system("pause");
    return 0;
}