// 给你一个字符串text ，请你返回满足下述条件的不同非空子字符串的数目：
// 可以写成某个字符串与其自身相连接的形式（即，可以写为 a + a，其中 a 是某个字符串）。
// 例如，abcabc 就是 abc 和它自身连接形成的。
// 
// 示例 1：
// 输入：text = "abcabcabc"
// 输出：3
// 解释：3 个子字符串分别为 "abcabc"，"bcabca" 和 "cabcab" 。
//
// 示例 2：
// 输入：text = "leetcodeleetcode"
// 输出：2
// 解释：2 个子字符串为 "ee" 和 "leetcodeleetcode" 。
// 
// 提示：
// 1 <= text.length <= 2000
// text 只包含小写英文字母。

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<string_view>
using namespace std;
//Difficult

/**
 * Solution 1 : 枚举
 *      我们在 text 中枚举位置 i 和 j，若字符串 text[i:j] 和 text[j:j*2-i] 相等，
 *      那么字符串 text[i:j*2-i] 就是一个满足条件的子串，其中 text[x:y] 表示字符串 text 中以位置 x 开始，位置 y 结束并且不包含位置 y 的子串。
 *      由于题目需要求出不同的子串数目，因此我们还需要使用哈希集合（HashSet）对所有满足条件的子串进行去重操作。
 * 
 * Solution 2 : 滚动哈希 + 前缀和
 *      说明
 *      本方法需要一些关于「滚动哈希」或「Rabin-Karp 算法」的预备知识，其核心是将字符串看成一个 k 进制的整数，其中 k 是字符串中可能出现的字符种类，
 *      本题中字符串只包含小写字母，即 k = 26（也可以取比 k 大的整数，一般来说可以取一个质数，例如 29 或 31）。
 *      这样做的好处是绕开了字符串操作，将字符串看成整数进行比较，并可以在常数时间内将字符串加入哈希集合中。
 *      使用滚动哈希
 *      我们仍然在 text 中枚举位置 i 和 j，并判断字符串 text[i:j] 和 text[j:j*2-i] 是否相等。但与方法一不同的是，我们比较这两个字符串的哈希值，而并非字符串本身。
 *      如果仅使用 Rabin-Karp 算法计算这两个字符串的哈希值，我们仍然需要使用 O(N)O(N) 的时间，与直接比较字符串的时间复杂度相同。那么我们如何在更短的时间内计算出字符串的哈希值呢？
 *      我们可以使用类似前缀和的方法。记 prefix[i] 表示字符串 text[0:i] 的哈希值。特别地，prefix[0] 的值为 0，为空串的哈希值。我们可以在 O(N)O(N) 的时间内计算出数组 prefix 中的所有元素，即：
 *          prefix[i]=prefix[i?1]?k+text[i]
 *      当我们得到了前缀和数组 prefix 之后，如何计算任意字符串 text[i:j] 的哈希值呢？观察 prefix[i] 和 prefix[j] 这两项，它们的表达式为：
 *          prefix[i] = text[0]?k^i?1+text[1]?k^i-2 + ? + text[i?1]
 *          prefix[j] = text[0]?k^j?1+text[1]?k^j-2 + ? + text[j?1]
 *      如果将 prefix[i] 乘以 k^j?i，那么等式两侧会变为：k^j?i?prefix[i]=text[0]?k^j?1+text[1]?k^j?2+?+text[i?1]?k^j?i
 *      将上式与 prefix[j] 的表达式相减，得到：prefix[j]?k^j?i?prefix[i]=text[i]?k^j?i?1 + ?+text[j?1]
 *      与 text[i:j] 的哈希值相等，因此我们可以在 O(1)O(1) 的时间计算出任意字符串 text[i:j] 的哈希值。
 *      在此之前，我们还需要预处理计算出所有 k 的次幂，不然在进行乘法操作时，仍然需要超过 O(1)O(1) 的时间。
 *      注意：上面的所有等式都省略了取模操作（如果你不知道为什么要取模，那么你对「Rabin-Karp 算法」的预备知识还没有掌握透彻），
 *      但在实际的代码编写中不能忽略，并且在取模的意义下，做减法时会产生负数。
 *      通用的写法如下所示，它同时考虑了取模和负数（在 C++ 等语言中，还需要注意乘法可能产生的溢出）：
 *              hash_value(text[i:j])=(prefix[j]?k^j?i?prefix[i]%mod+mod)%mod
 *      回到我们原来的问题，当我们用字符串 text[i:j] 和 text[j:j*2-i] 的哈希值代替其本身判断是否相等后，如果两者相等，
 *      字符串 text[i:j*2-i] 就是一个满足条件的子串。但我们还需要进行去重操作，才能得到最终的答案。
 *      在「判断」这一步中，由于我们只对两个字符串进行比较，因此引入哈希冲突（在下方的注意事项中也有提及）的概率极小。然而在「去重」这一步中，最坏情况下字符串的数量为 O(N^2)O(N 2)，
 *      大量的字符串造成哈希冲突的概率极大。为了减少字符串的数量以降低冲突的概率，我们可以使用 N 个哈希集合，分别存放不同长度的字符串，即第 m 个哈希集合存放长度为 m + 1 的字符串的哈希值。
 *      这样每个哈希集合只对某一固定长度的字符串进行去重操作，并且其中最多只有 N 个字符串，冲突概率非常低。
 *      更多的实现细节请参考后面给出的代码。
 * 
 *      注意事项:
 *  由于 Rabin-Karp 算法会将字符串对应的整数值进行取模，那么：
 *  如果字符串 S1 和 S2 对应的整数值 I1 和 I2 不相等，那么 S1 和 S2 一定不相等；
 *  如果字符串 S1 和 S2 对应的整数值 I1 和 I2 相等，并不代表 S1 和 S2 一定相等；
 *  这与实际应用中使用的哈希算法也是一致的，即先判断两个实例的哈希值是否相等，再判断它们本质上是否相等。
 *  而在竞赛题目中，由于数据量较少，几乎不会产生哈希冲突，因此我们可以直接用 I1 和 I2 的相等代替 S1 和 S2 的相等，减少时间复杂度。
 *  但需要牢记在实际应用中，这样做是不严谨的
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