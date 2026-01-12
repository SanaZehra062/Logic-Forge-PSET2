# Challenge 3 – The Mirror Quest: Finding the Longest Reflection

## Problem Overview
You are given a string of characters representing ancient runes.<br>
Your task is to determine the length of the **Longest Palindromic Subsequence** present in the string.<br>
A palindrome reads the same forward and backward.<br>
A subsequence does not need to be contiguous but must preserve the original order of characters.<br>

## Problem Statement
You are given a string `s` consisting of lowercase English letters.<br>
Determine the length of the longest subsequence of `s` that forms a palindrome.<br>

## Function Requirement
Write a function that:<br>
- Takes a string `s`<br>
- Returns an integer representing the length of the longest palindromic subsequence<br>

**Function Name:** `find_longest_mirror_length(s)`<br>

## Constraints
- `1 ≤ s.length ≤ 1000`<br>
- The string contains only lowercase English letters<br>
- The output should be the length, not the subsequence itself<br>

## Examples

**Example 1**<br>
`"bbabcbcab"`<br>
One possible longest palindromic subsequence is `babcbab`<br>
Length = 7<br>

## Approaches

### 1. Brute Force Approach

**Idea**<br>
Use recursion to explore all possible subsequences.<br>
- If the first and last characters match, include both<br>
- Otherwise, try removing one character at a time and take the maximum result<br>

**Time Complexity**<br>
O(2ⁿ)<br>

**Space Complexity**<br>
O(n) due to recursion stack<br>

**Drawback**<br>
Extremely slow for long strings and not suitable for large inputs<br>

### 2. Optimized Approach (Dynamic Programming)

**Idea**<br>
Use a 2D dynamic programming table where:<br>
`dp[i][j]` stores the length of the longest palindromic subsequence between indices `i` and `j`.<br>

**Step-by-Step Explanation**<br>
- Initialize all single characters as palindromes of length 1<br>
- Build solutions for longer substrings using smaller subproblems<br>
- Use previously computed results to avoid recomputation<br>

**Time Complexity**<br>
O(n²)<br>

**Space Complexity**<br>
O(n²)<br>

## Conclusion
This challenge highlights the importance of dynamic programming for optimization.<br>
While the brute force approach helps understand the logic, it is impractical for large strings.<br>
The optimized solution efficiently computes the result within acceptable time and space limits.<br>

