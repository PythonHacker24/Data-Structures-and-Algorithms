class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        hashmap = {}
        for index, value in enumerate(s):
            if value not in hashmap:
                hashmap[value] = 1
            else:
                hashmap[value] += 1

        for index, value in enumerate(t):
            if value not in hashmap or hashmap[value] == 0:
                return False
            else:
                hashmap[value] -= 1

        return True
