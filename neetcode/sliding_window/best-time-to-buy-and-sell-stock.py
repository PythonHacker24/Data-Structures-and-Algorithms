class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0

        left, right = 0, 1
        maxProfit = 0
        while left < len(prices) and right < len(prices):
            if prices[left] > prices[right]:
                left = right
                right = right + 1
            else:
                profit = prices[right] - prices[left] 
                maxProfit = max(maxProfit, profit)
                if maxProfit < profit:
                    maxProfit = profit
                right += 1

        return maxProfit
