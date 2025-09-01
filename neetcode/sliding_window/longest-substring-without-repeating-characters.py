class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        L = 0
        visited = []
        maxSize = 0

        for R in range(len(s)):
            if s[R] not in visited:
                size = R - L + 1
                maxSize = max(maxSize, size)
                visited.append(s[R])
            else:
                dup_index = visited.index(s[R])
                visited = visited[dup_index + 1:]
                visited.append(s[R])
                L = R - len(visited) + 1
        
        return maxSize
