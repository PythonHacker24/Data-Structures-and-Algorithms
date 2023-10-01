class Solution(object):
    def twoSum(self, nums, target):
        output = []
        for i in range(0, len(nums)):
            for t in range(i, len(nums)):
                if i == t:
                    pass
                elif nums[i] + nums[t] == target:
                    output.append(i)
                    output.append(t)
        return output
