class Solution:
    def search(self, nums: List[int], target: int) -> int:
        lptr, rptr = 0, len(nums) - 1

        while lptr <= rptr:
            midptr = int((lptr + rptr) / 2)
            if target > nums[midptr]:
                lptr = midptr + 1
            elif target < nums[midptr]:
                rptr = midptr - 1
            else:
                return midptr
        return -1
