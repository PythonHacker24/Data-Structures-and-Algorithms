class Solution:
    def partitionArray(self, nums: List[int], k: int) -> bool:
        length = len(nums)

        if length % k != 0:
            return False

        nGroups = length / k
        table = {}
        for num in nums:
            if num not in table:
                table[num] = 1
            else:
                table[num] += 1

        for value in table.values():
            if value > nGroups:
                return False

        return True
