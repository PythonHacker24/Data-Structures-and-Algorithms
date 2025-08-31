class Solution:
    def isPalindrome(self, s: str) -> bool:
        fls = "".join(ch.lower() for ch in s if ch.isalnum())
        for i in range(int(len(fls) / 2)):
            if fls[i] != fls[len(fls) - 1 - i]:
                return False
        return True
