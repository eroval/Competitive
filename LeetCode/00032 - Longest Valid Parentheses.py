#1
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        left_par = 0
        right_par = 0
        longest_string = 0
        
        for i in range (0, len(s)):
            if(s[i]=='('):
                left_par+=1
            else:
                right_par+=1
            if left_par==right_par:
                longest_string = max(longest_string, 2*right_par)
            elif right_par>=left_par:
                left_par = 0
                right_par = 0
                
        left_par = 0
        right_par = 0
        
        for i in range (len(s)-1, 0, -1):
            if(s[i]=='('):
                left_par+=1
            else:
                right_par+=1
            
            if left_par==right_par:
                longest_string = max(longest_string, 2*left_par)
            elif left_par>=right_par:
                left_par = 0
                right_par = 0
        
        return longest_string

#2
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        dp = [0]*(len(s)+1)
        stack = []
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                if stack:
                    p = stack.pop()
                    dp[i + 1] = dp[p] + i - p + 1
        return max(dp)
        
