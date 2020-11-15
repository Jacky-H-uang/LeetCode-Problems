
# 前缀和 + 后缀和

class Solution(object):
    def minOperations(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """

        if len(nums) == 1:
            if x == nums[0]:    return 1
            else:               return -1    

        n = len(nums)
        prefix = [0] * (n+1)
        suffix = [0] * (n+1)
        for i in range(1,n+1):
            prefix[i] = prefix[i-1] + nums[i-1]
        for i in range(n-1,-1,-1):
            suffix[i] = suffix[i+1] + nums[i]
            
        ans = -1
        i = 0
        j = n

        if prefix[n] < x:   return -1
        if prefix[n] == x:  return n
        while prefix[i+1] <= x:    i += 1
        if prefix[i] == x :       ans = i

        while i >= 0:
            while j >= 0:
                if prefix[i] + suffix[j] > x  : break
                if prefix[i] + suffix[j] == x : 
                    if ans == -1 or ans > i + n - j: ans = i + n - j
                j = j - 1

            i -= 1


        return ans