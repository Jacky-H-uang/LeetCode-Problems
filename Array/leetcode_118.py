#                                               118. 杨辉三角
#
# 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
# 在杨辉三角中，每个数是它左上方和右上方的数的和。
#
# 示例:
# 输入: 5
# 输出:
# [
#      [1],
#     [1,1],
#    [1,2,1],
#   [1,3,3,1],
#  [1,4,6,4,1]
# ]



# Easy

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = list()
        if numRows < 1:       return []
        if numRows == 1:      return [[1]]

        ans = self.generate(numRows-1)

        arr = list()
        arr.append(1)
        for i in range(1,numRows-1):
            arr.append(ans[numRows-2][i-1] + ans[numRows-2][i])
        arr.append(1)

        ans.append(arr)

        return ans