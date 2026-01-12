# Challenge 7 – Koko’s Banana Buffet

## Problem Overview
Koko the monkey has found several piles of bananas and wants to eat them all before the guards return.  
She must choose a constant eating speed `s` (bananas per hour).  
Your task is to determine the minimum possible speed at which Koko can eat so that all bananas are finished within `k` hours.



## Problem Statement
You are given:
- An integer array `piles` where `piles[i]` represents the number of bananas in the i-th pile
- An integer `k` representing the total hours available

### Eating Rules
- In one hour, Koko eats `s` bananas from a single pile
- If a pile has fewer than `s` bananas, she eats all of them and waits until the next hour

Return the minimum integer speed `s` such that all piles are eaten within `k` hours.



## Function Requirement
**Function Name:**  
`calculate_minimum_speed(piles, k)`

**Input:**  
- `piles`: integer array  
- `k`: integer

**Output:**  
- Minimum integer eating speed `s`



## Constraints
- `1 ≤ piles.size ≤ 10^4`
- `1 ≤ piles[i] ≤ 10^9`
- `piles.size ≤ k ≤ 10^9`
- The solution must be efficient and avoid checking every possible speed


## Approaches

### 1. Brute Force Approach
**Idea:**
- Try every possible eating speed from `1` to `max(piles)`
- For each speed, calculate the total hours required
- Return the first speed that finishes within `k` hours

**Time Complexity:**  
`O(maxPile × n)`

**Space Complexity:**  
`O(1)`

**Drawback:**  
Too slow for large pile sizes



### 2. Optimized Approach (Binary Search)
**Idea:**
- Apply Binary Search on the speed range `[1, maxPile]`
- For each mid speed, compute required hours
- Narrow the range to find the minimum valid speed

**Time Complexity:**  
`O(n × log(maxPile))`

**Space Complexity:**  
`O(1)`



## Conclusion
Binary Search efficiently finds the minimum eating speed required for Koko to finish all piles on time.  
The brute force approach is simple but impractical for large inputs.
