class Solution(object):
	def isPalindrome(self, x):
		x_str = str(x)
		# if len(x_str) <= 1:
		# 	return True
		for i in range(0, len(x_str) - 1):
			if x_str[i] != x_str[len(x_str) - 1 - i] and i != len(x_str) - 1 - i:
				return False
			else:
				pass
		return True

 
