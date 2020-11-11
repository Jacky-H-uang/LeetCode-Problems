// ����һ���ַ���text �����㷵���������������Ĳ�ͬ�ǿ����ַ�������Ŀ��
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
#include<unordered_set>
#include<string_view>
using namespace std;
//Difficult

/**
 * Solution 1 : ö��
 *      ������ text ��ö��λ�� i �� j�����ַ��� text[i:j] �� text[j:j*2-i] ��ȣ�
 *      ��ô�ַ��� text[i:j*2-i] ����һ�������������Ӵ������� text[x:y] ��ʾ�ַ��� text ����λ�� x ��ʼ��λ�� y �������Ҳ�����λ�� y ���Ӵ���
 *      ������Ŀ��Ҫ�����ͬ���Ӵ���Ŀ��������ǻ���Ҫʹ�ù�ϣ���ϣ�HashSet�������������������Ӵ�����ȥ�ز�����
 * 
 * Solution 2 : ������ϣ + ǰ׺��
 *      ˵��
 *      ��������ҪһЩ���ڡ�������ϣ����Rabin-Karp �㷨����Ԥ��֪ʶ��������ǽ��ַ�������һ�� k ���Ƶ����������� k ���ַ����п��ܳ��ֵ��ַ����࣬
 *      �������ַ���ֻ����Сд��ĸ���� k = 26��Ҳ����ȡ�� k ���������һ����˵����ȡһ������������ 29 �� 31����
 *      �������ĺô����ƿ����ַ������������ַ��������������бȽϣ��������ڳ���ʱ���ڽ��ַ��������ϣ�����С�
 *      ʹ�ù�����ϣ
 *      ������Ȼ�� text ��ö��λ�� i �� j�����ж��ַ��� text[i:j] �� text[j:j*2-i] �Ƿ���ȡ����뷽��һ��ͬ���ǣ����ǱȽ��������ַ����Ĺ�ϣֵ���������ַ�������
 *      �����ʹ�� Rabin-Karp �㷨�����������ַ����Ĺ�ϣֵ��������Ȼ��Ҫʹ�� O(N)O(N) ��ʱ�䣬��ֱ�ӱȽ��ַ�����ʱ�临�Ӷ���ͬ����ô��������ڸ��̵�ʱ���ڼ�����ַ����Ĺ�ϣֵ�أ�
 *      ���ǿ���ʹ������ǰ׺�͵ķ������� prefix[i] ��ʾ�ַ��� text[0:i] �Ĺ�ϣֵ���ر�أ�prefix[0] ��ֵΪ 0��Ϊ�մ��Ĺ�ϣֵ�����ǿ����� O(N)O(N) ��ʱ���ڼ�������� prefix �е�����Ԫ�أ�����
 *          prefix[i]=prefix[i?1]?k+text[i]
 *      �����ǵõ���ǰ׺������ prefix ֮����μ��������ַ��� text[i:j] �Ĺ�ϣֵ�أ��۲� prefix[i] �� prefix[j] ��������ǵı��ʽΪ��
 *          prefix[i] = text[0]?k^i?1+text[1]?k^i-2 + ? + text[i?1]
 *          prefix[j] = text[0]?k^j?1+text[1]?k^j-2 + ? + text[j?1]
 *      ����� prefix[i] ���� k^j?i����ô��ʽ������Ϊ��k^j?i?prefix[i]=text[0]?k^j?1+text[1]?k^j?2+?+text[i?1]?k^j?i
 *      ����ʽ�� prefix[j] �ı��ʽ������õ���prefix[j]?k^j?i?prefix[i]=text[i]?k^j?i?1 + ?+text[j?1]
 *      �� text[i:j] �Ĺ�ϣֵ��ȣ�������ǿ����� O(1)O(1) ��ʱ�����������ַ��� text[i:j] �Ĺ�ϣֵ��
 *      �ڴ�֮ǰ�����ǻ���ҪԤ������������ k �Ĵ��ݣ���Ȼ�ڽ��г˷�����ʱ����Ȼ��Ҫ���� O(1)O(1) ��ʱ�䡣
 *      ע�⣺��������е�ʽ��ʡ����ȡģ����������㲻֪��ΪʲôҪȡģ����ô��ԡ�Rabin-Karp �㷨����Ԥ��֪ʶ��û������͸������
 *      ����ʵ�ʵĴ����д�в��ܺ��ԣ�������ȡģ�������£�������ʱ�����������
 *      ͨ�õ�д��������ʾ����ͬʱ������ȡģ�͸������� C++ �������У�����Ҫע��˷����ܲ������������
 *              hash_value(text[i:j])=(prefix[j]?k^j?i?prefix[i]%mod+mod)%mod
 *      �ص�����ԭ�������⣬���������ַ��� text[i:j] �� text[j:j*2-i] �Ĺ�ϣֵ�����䱾���ж��Ƿ���Ⱥ����������ȣ�
 *      �ַ��� text[i:j*2-i] ����һ�������������Ӵ��������ǻ���Ҫ����ȥ�ز��������ܵõ����յĴ𰸡�
 *      �ڡ��жϡ���һ���У���������ֻ�������ַ������бȽϣ���������ϣ��ͻ�����·���ע��������Ҳ���ἰ���ĸ��ʼ�С��Ȼ���ڡ�ȥ�ء���һ���У��������ַ���������Ϊ O(N^2)O(N 2)��
 *      �������ַ�����ɹ�ϣ��ͻ�ĸ��ʼ���Ϊ�˼����ַ����������Խ��ͳ�ͻ�ĸ��ʣ����ǿ���ʹ�� N ����ϣ���ϣ��ֱ��Ų�ͬ���ȵ��ַ��������� m ����ϣ���ϴ�ų���Ϊ m + 1 ���ַ����Ĺ�ϣֵ��
 *      ����ÿ����ϣ����ֻ��ĳһ�̶����ȵ��ַ�������ȥ�ز����������������ֻ�� N ���ַ�������ͻ���ʷǳ��͡�
 *      �����ʵ��ϸ����ο���������Ĵ��롣
 * 
 *      ע������:
 *  ���� Rabin-Karp �㷨�Ὣ�ַ�����Ӧ������ֵ����ȡģ����ô��
 *  ����ַ��� S1 �� S2 ��Ӧ������ֵ I1 �� I2 ����ȣ���ô S1 �� S2 һ������ȣ�
 *  ����ַ��� S1 �� S2 ��Ӧ������ֵ I1 �� I2 ��ȣ��������� S1 �� S2 һ����ȣ�
 *  ����ʵ��Ӧ����ʹ�õĹ�ϣ�㷨Ҳ��һ�µģ������ж�����ʵ���Ĺ�ϣֵ�Ƿ���ȣ����ж����Ǳ������Ƿ���ȡ�
 *  ���ھ�����Ŀ�У��������������٣��������������ϣ��ͻ��������ǿ���ֱ���� I1 �� I2 ����ȴ��� S1 �� S2 ����ȣ�����ʱ�临�Ӷȡ�
 *  ����Ҫ�μ���ʵ��Ӧ���У��������ǲ��Ͻ���
 */
class Solution1 {
public:
    int distinctEchoSubstrings(string text) 
    {
        int n = text.size();
        unordered_set<string_view> seen;
        string_view text_v(text);
        int ans = 0;
        for (int i = 0; i < n; ++i) 
        {
            for (int j = i + 1; j < n; ++j) 
            {
                int l = j - i;
                if (j * 2 - i <= n && text_v.substr(i, l) == text_v.substr(j, l) && !seen.count(text_v.substr(i, l))) 
                {
                    ++ans;
                    seen.insert(text_v.substr(i, l));
                }
            }
        }
        return ans;
    }
};

int main()
{
    string t = "tkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnra";
    Solution1 s;
    int r = s.distinctEchoSubstrings(t);
    cout<<r<<endl;
    system("pause");
    return 0;
}