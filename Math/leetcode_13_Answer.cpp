#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        map<char,int> luomab;
        luomab.insert(map<char,int>::value_type('I',1));
        luomab.insert(map<char,int>::value_type('V',5));
        luomab.insert(map<char,int>::value_type('X',10));
        luomab.insert(map<char,int>::value_type('L',50));
        luomab.insert(map<char,int>::value_type('C',100));
        luomab.insert(map<char,int>::value_type('D',500));
        luomab.insert(map<char,int>::value_type('M',1000));
        for(int i=0;i<s.length();i++)
        {
            if(luomab[s[i]] < luomab[s[i+1]])               //string 的最后一位是 '\0' 所以不会担心越界
            {
                result -= luomab[s[i]];
            }
            else
            {
                result += luomab[s[i]];
            }
        }
        return result;
    }
};

int main()
{
    string a = "I";
    Solution s;
    int r = s.romanToInt(a);
    cout<<r<<endl;
    system("pause");
    return 0;
}