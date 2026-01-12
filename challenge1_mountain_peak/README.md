# Challenge 1 –  The Mountain Peak Challenge

## Problem Overview
You are an explorer standing at the base of an ancient mountain with **n stone steps** leading to a hidden temple.<br>
To save energy, you follow a fixed climbing rhythm:<br>
- You may take **one step** at a time<br>
- Or you may take **two steps** at a time<br>
Your task is to calculate how many **unique combinations of moves** allow you to land exactly on the **nth step**.<br>

## Problem Statement
You are given an integer `n` representing the total number of steps in the mountain.<br>
Create a solution that determines the total number of distinct ways to reach the top if:<br>
- Each move consists of either **1 step or 2 steps**<br>

## Function Requirement
Write a function that:<br>
- Takes an integer `n`<br>
- Returns an integer representing the total number of unique ways to reach the summit<br>

**Function Name:** `count_ways_to_summit(n)`<br>

## Constraints
- `1 ≤ n ≤ 45`<br>
- The solution must work efficiently for `n = 45`<br>
- A purely recursive approach may exceed time limits<br>
- Extra space usage should be minimal (preferably O(1))<br>
- All results fit within a 32-bit integer<br>

## Examples

**Example 1**<br>
For `n = 3`:<br>
Possible combinations:<br>
- 1 + 1 + 1<br>
- 1 + 2<br>
- 2 + 1<br>
Total ways = 3<br>

## Approaches

### 1. Brute Force Approach

**Idea**<br>
To reach step `n`, the last move could have been:<br>
- From step `n-1` by taking 1 step<br>
- From step `n-2` by taking 2 steps<br>

This leads to the recurrence relation:<br>
`ways(n) = ways(n-1) + ways(n-2)`<br>

**Steps**<br>
- Define base cases for `n = 1` and `n = 2`<br>
- Recursively compute the number of ways for smaller steps<br>

**Time Complexity**<br>
O(2ⁿ)<br>

**Space Complexity**<br>
O(n) due to recursion stack<br>

**Drawback**<br>
Becomes extremely slow for larger values of `n`<br>

### 2. Optimized Approach (Prefix Fibonacci Logic)

**Idea**<br>
This problem follows a **Fibonacci-style pattern**.<br>
Instead of recursion, store only the last two computed values and build the result iteratively.<br>

**Step-by-Step Explanation**<br>
- Initialize two variables for the first two steps<br>
- Iterate from step 3 up to `n`<br>
- At each step, compute the sum of the previous two values<br>

**Time Complexity**<br>
O(n)<br>

**Space Complexity**<br>
O(1) extra space<br>

## Conclusion
The Mountain Peak Challenge is a classic dynamic programming problem.<br>
While the brute force approach helps in understanding the logic, it is inefficient for large inputs.<br>
The optimized iterative approach is fast, memory-efficient, and suitable for real-world and interview scenarios.<br>
