
# Medium



# 遇事不决直接 Python （特别是这些需要二进制，十进制之间的转换这类的）
class Solution:
    def concatenatedBinary(self, n: int) -> int:
            res=0
            for m in range(1,n+1):
                bits = int(log(m,2))+1
                res = (res * pow(2,bits) + m) % 1000000007
            return res