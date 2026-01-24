class Solution(object):
    def minPairSum(self, nums):
        l = len(nums)
        nums = sorted(nums)
        i = 0
        j = l-1
        maxi = 0
        while i < j:
            sum = nums[i] + nums[j]
            if maxi < sum:
                maxi = sum
            i += 1
            j -= 1
        return maxi
        