// ����һ���ַ��� text �����㷵���������������Ĳ�ͬ�ǿ����ַ�������Ŀ��
// ����д��ĳ���ַ����������������ӵ���ʽ����������дΪ a + a������ a ��ĳ���ַ�������
// ���磬abcabc ���� abc �������������γɵġ�
// 
// ʾ�� 1��
// ���룺text = "abcabcabc"
// �����3
// ���ͣ�3 �����ַ����ֱ�Ϊ "abcabc"��"bcabca" �� "cabcab" ��
//
// ʾ�� 2��
// ���룺text = "leetcodeleetcode"
// �����2
// ���ͣ�2 �����ַ���Ϊ "ee" �� "leetcodeleetcode" ��
// 
// ��ʾ��
// 1 <= text.length <= 2000
// text ֻ����СдӢ����ĸ��

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//Difficult

// Time Excueeded
class Solution {
public:
    int distinctEchoSubstrings(string text) 
    {
        int len = text.size();
        vector<string> str;
        vector<string>::iterator it;
        int count = 0;
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                if(j-i > (len-i)/2)
                {
                    break;
                }
                it = find(str.begin(),str.end(),text.substr(i,j-i));
                if(text.substr(i,j-i) == text.substr(j,j-i) && it == str.end() || str.empty())
                {
                    str.push_back(text.substr(i,j-i));
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    string t = "tkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnra";
    Solution s;
    int r = s.distinctEchoSubstrings(t);
    cout<<r<<endl;
    system("pause");
    return 0;
}