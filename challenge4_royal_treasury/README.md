# Challenge 4 – The Royal Treasury

## Problem Overview
You are the Royal Treasurer and must pay a specific amount using coins of various denominations.<br>
You have an infinite supply of each coin type.<br>
Determine how many **unique combinations** of coins can be used to make the exact payment.<br>

## Problem Statement
Given an integer array `coins` representing coin denominations and an integer `total_sum`:<br>
- Find the total number of unique ways to combine the coins to reach `total_sum`<br>
- You can use each coin as many times as needed<br>

## Function Requirement
Write a function that:<br>
- Takes an integer array `coins` and an integer `total_sum`<br>
- Returns an integer representing the number of unique combinations<br>

**Function Name:** `count_payment_combinations(coins, total_sum)`<br>

## Constraints
- `1 ≤ coins.size ≤ 1000`<br>
- `1 ≤ coins[i] ≤ 1000`<br>
- `1 ≤ total_sum ≤ 1000`<br>
- Aim for an efficient solution that avoids recounting combinations<br>

## Examples

**Example 1**<br>
`coins = [1, 2, 3], total_sum = 4`<br>
Possible combinations:<br>
- {1,1,1,1}, {1,1,2}, {2,2}, {1,3}<br>
Total ways = 4<br>

**Example 2**<br>
`coins = [2, 5, 3, 6], total_sum = 10`<br>
Total ways = 5<br>

**Example 3**<br>
`coins = [4], total_sum = 5`<br>
Total ways = 0 (cannot make sum 5 using only 4-piece coins)<br>

## Approaches

### 1. Brute Force Approach

**Idea**<br>
Use recursion to try all possible combinations:<br>
- Include the current coin → reduce remaining sum<br>
- Exclude the current coin → move to next denomination<br>

**Time Complexity**<br>
O(2ⁿ × sum)<br>

**Space Complexity**<br>
O(n) recursion stack<br>

**Drawback**<br>
Extremely slow for large inputs and not feasible for the given constraints<br>

### 2. Optimized Approach (Dynamic Programming)

**Idea**<br>
Use a DP array to store the number of ways to form each sum up to `total_sum`:<br>
- `dp[s]` stores number of ways to form sum `s`<br>
- For each coin, iterate through sums from `coin` to `total_sum` and update `dp[s] += dp[s - coin]`<br>

**Time Complexity**<br>
O(n × total_sum)<br>

**Space Complexity**<br>
O(total_sum)<br>

## Conclusion
This challenge demonstrates the **unbounded coin change problem**.<br>
- Brute force recursion is clear but inefficient<br>
- Optimized dynamic programming efficiently computes the number of combinations for large inputs<br>

