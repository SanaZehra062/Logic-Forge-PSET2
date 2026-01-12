# Challenge 2 –  The Balanced Scales Challenge

## Problem Overview
You are given a collection of magical stones, each having a specific weight stored in an integer array.<br>
Your task is to determine whether it is possible to split all the stones into **two separate bags** such that:<br>
- Each bag contains some of the stones<br>
- The total weight of both bags is **exactly equal**<br>

## Problem Statement
You are given an integer array `arr` where:<br>
- `arr[i]` represents the weight of the i-th stone<br>
Determine whether the array can be divided into two subsets such that the **sum of elements in both subsets is the same**.<br>

## Function Requirement
Write a function that:<br>
- Takes an integer array `arr`<br>
- Returns `true` if the stones can be split into two equal-weight bags<br>
- Returns `false` otherwise<br>

**Function Name:** `can_balance_scales(arr)`<br>

## Constraints
- `1 ≤ arr.size ≤ 100`<br>
- `1 ≤ arr[i] ≤ 200`<br>
- The solution must run within the given time limits<br>
- All stones must be used exactly once<br>

## Examples

**Example 1**<br>
`arr = [1, 5, 11, 5]`<br>
Total sum = 22 → Target per bag = 11<br>
Equal split is possible<br>

**Example 2**<br>
`arr = [1, 3, 5]`<br>
Total sum is odd → Equal split is not possible<br>

## Approaches

### 1. Brute Force Approach

**Idea**<br>
For each stone, you have two choices:<br>
- Put the stone in Bag A<br>
- Do not put the stone in Bag A<br>
Try all possible combinations to check if any subset sums to `totalSum / 2`.<br>

**Steps**<br>
- Calculate the total sum of the array<br>
- If the total sum is odd, return false<br>
- Recursively explore all subsets to find a subset with sum equal to half of the total sum<br>

**Time Complexity**<br>
O(2ⁿ)<br>

**Space Complexity**<br>
O(n) due to recursion stack<br>

**Drawback**<br>
This approach is not efficient for large input sizes<br>

### 2. Optimized Approach (Dynamic Programming – Subset Sum)

**Idea**<br>
This problem is a variation of the **Subset Sum Problem**.<br>
Instead of checking all subsets, use dynamic programming to determine which sums are achievable.<br>

**Step-by-Step Explanation**<br>
- Calculate the total sum of all stones<br>
- If the total sum is odd, return false<br>
- Create a boolean DP array where `dp[s]` indicates whether sum `s` is achievable<br>
- Update the DP array iteratively for each stone<br>

**Time Complexity**<br>
O(n × target)<br>

**Space Complexity**<br>
O(target)<br>

## Conclusion
The Balanced Scales Challenge tests your understanding of decision-making and dynamic programming.<br>
While the brute force approach explains the logic clearly, it is inefficient for larger inputs.<br>
The optimized dynamic programming solution efficiently determines whether an equal partition is possible and is recommended for practical use.<br>

