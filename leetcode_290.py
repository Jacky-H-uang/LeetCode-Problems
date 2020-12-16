#                                       290. 单词规律
#
# 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
# 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
#
# 示例1:
# 输入: pattern = "abba", str = "dog cat cat dog"
# 输出: true
#
# 示例 2:
# 输入:pattern = "abba", str = "dog cat cat fish"
# 输出: false
#
# 示例 3:
# 输入: pattern = "aaaa", str = "dog cat cat dog"
# 输出: false
#
# 示例 4:
# 输入: pattern = "abba", str = "dog dog dog dog"
# 输出: false
# 说明:
# 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。


# Medium

class Solution:
    def wordPattern(self, pattern, s) -> bool:
        strList = s.split(' ')
        patternList = list(pattern)

        if len(pattern) != len(strList):        # 长度不相等直接返回 False        
            return False
        
        st = dict()
        for i in range(len(pattern)):
            try:
                if st[pattern[i]] != strList[i]:
                    return False
            except:
                # 如果在 s 在 values 里面 但是 pattern 不在 values 里面就返回 False
                if strList[i] in st.values():
                    return False
                st[pattern[i]] = strList[i]
        
        return True