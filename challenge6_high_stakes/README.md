# Challenge 6 – The High-Stakes Freelancer

## Problem Overview
You are a freelancer with multiple jobs, each taking 1 hour and offering a profit.<br>
Each job has a deadline by which it must be completed.<br>
Determine a schedule to **maximize total profit** and **count of jobs completed**.<br>

## Problem Statement
Given two arrays `deadlines` and `profits`:<br>
- `deadlines[i]` = latest hour job i can be completed<br>
- `profits[i]` = profit for job i<br>
- Each job takes exactly 1 hour and only one job can be done at a time<br>
Compute:
- Total number of jobs completed
- Maximum total profit earned<br>

## Function Requirement
Write a function that:<br>
- Takes two integer arrays `deadlines` and `profits`<br>
- Returns a list `[totalJobsCompleted, maxProfit]`<br>

**Function Name:** `maximize_freelance_profit(deadlines, profits)`<br>

## Constraints
- `1 ≤ N ≤ 10^5` (number of jobs)<br>
- `1 ≤ deadlines[i] ≤ 10^5`<br>
- `1 ≤ profits[i] ≤ 10^4`<br>
- Solution should handle large inputs efficiently (O(N log N))<br>

## Examples

**Example 1**<br>
`deadlines = [4,1,1,1], profits = [20,10,40,30]`<br>
Pick jobs with profits 40 and 20<br>
Output = [2, 60]<br>

**Example 2**<br>
`deadlines = [2,1,2,1,1], profits = [100,19,27,25,15]`<br>
Pick jobs with profits 100 and 27<br>
Output = [2, 127]<br>

## Approaches

### 1. Brute Force Approach

**Idea**<br>
- Try all permutations of jobs<br>
- Assign each job to the latest available slot ≤ deadline<br>
- Track maximum profit<br>

**Time Complexity**<br>
O(N × maxDeadline) — impractical for large N<br>

**Space Complexity**<br>
O(maxDeadline)<br>

**Drawback**<br>
Extremely slow for N = 10^5<br>

### 2. Optimized Approach (Greedy + DSU)

**Idea**<br>
- Sort jobs in descending order of profit<br>
- Assign each job to the latest available slot ≤ deadline<br>
- Use Disjoint Set / parent array to efficiently find free slots<br>

**Time Complexity**<br>
O(N log N) — sorting dominates<br>

**Space Complexity**<br>
O(maxDeadline)<br>

## Conclusion
This challenge demonstrates **job scheduling with deadlines for maximum profit**.<br>
Greedy strategy combined with DSU ensures efficient assignment of jobs even for very large datasets.<br>

