# Challenge 5 – The Master Scheduler's Dilemma

## Problem Overview
You are managing a conference room with multiple booking requests.<br>
Some requests overlap, and you can only host one meeting at a time.<br>
Determine the **minimum number of bookings to cancel** so that the remaining schedule has no overlaps.<br>

## Problem Statement
Given a list of intervals `intervals` where each interval is `[start_time, end_time]`:<br>
- Compute the minimum number of intervals that must be removed to eliminate all overlaps<br>
- Back-to-back meetings (end == start) are allowed<br>

## Function Requirement
Write a function that:<br>
- Takes a 2D integer array `intervals`<br>
- Returns an integer representing the minimum number of bookings to cancel<br>

**Function Name:** `min_cancelled_bookings(intervals)`<br>

## Constraints
- `1 ≤ intervals.length ≤ 10^5`<br>
- `-5*10^4 ≤ start_i < end_i ≤ 5*10^4`<br>
- Solution should run in O(n log n) time<br>

## Examples

**Example 1**<br>
`intervals = [[1,2],[2,3],[3,4],[1,3]]`<br>
Remove [1,3]<br>
Minimum cancellations = 1<br>

**Example 2**<br>
`intervals = [[1,3],[1,3],[1,3]]`<br>
Remove 2 intervals<br>
Minimum cancellations = 2<br>

**Example 3**<br>
`intervals = [[1,2],[5,10],[18,35]]`<br>
No overlap<br>
Minimum cancellations = 0<br>

## Approaches

### 1. Brute Force Approach

**Idea**<br>
Try all subsets of intervals recursively:<br>
- Check which subset has no overlaps<br>
- Track minimum intervals removed<br>

**Time Complexity**<br>
O(2ⁿ) — impractical for large inputs<br>

**Space Complexity**<br>
O(n) recursion stack<br>

**Drawback**<br>
Extremely slow for large datasets<br>

### 2. Optimized Approach (Greedy)

**Idea**<br>
- Sort intervals by **end time**<br>
- Always keep the interval that ends earliest<br>
- If next interval overlaps, count it as removal<br>
- Repeat until all intervals processed<br>

**Time Complexity**<br>
O(n log n) — due to sorting<br>

**Space Complexity**<br>
O(1) extra space<br>

## Conclusion
This challenge demonstrates the power of **greedy algorithms** for interval scheduling problems.<br>
Brute force is conceptually clear but inefficient.<br>
The greedy solution efficiently finds the minimum cancellations for large numbers of intervals.<br>

