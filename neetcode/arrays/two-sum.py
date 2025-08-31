class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i, value in enumerate(nums):
            complement = target - value
            if complement in hashmap:
                return [hashmap[complement], i]
            hashmap[value] = i
        return None
