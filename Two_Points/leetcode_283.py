# //                                      283. 移动零
# //
# // 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
# //
# // 示例:
# // 输入: [0,1,0,3,12]
# // 输出: [1,3,12,0,0]
# // 说明:
# // 必须在原数组上操作，不能拷贝额外的数组。
# // 尽量减少操作次数。





# Easy

class Solution:
    def moveZeroes(self, nums):
        n = len(nums)
        i = j = 0
        while i < n:
            if nums[i] != 0:
                nums[i] , nums[j] = nums[j] , nums[i]
                j += 1
            i += 1


if __name__ == '__main__':
    a = Solution()
    arr = [0,1,0,3,12]

    a.moveZeroes(arr)

    for val in arr:
        print(val)