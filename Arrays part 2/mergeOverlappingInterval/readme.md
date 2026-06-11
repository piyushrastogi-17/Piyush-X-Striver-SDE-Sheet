# LeetCode 56: Merge Intervals

## Problem Statement
* Given an array of intervals, merge all overlapping intervals and return an array of the non-overlapping intervals.

---

## 1. Brute Force Approach

### Description
* Sort the intervals by their start times.
* Use nested loops to compare each interval with all subsequent intervals.
* If an overlap is found, stretch the current interval's end boundary to encompass the overlapping one.
* Skip intervals that have already been merged into previous groups.

### Complexity Analysis
* **Time Complexity:** O(N^2) – Due to checking every remaining pair iteratively in the nested loop when intervals overlap.
* **Space Complexity:** O(1) – No extra storage used besides the mandatory output array.

---

## 2. Better Approach (Using Temp Interval)

### Description
* Sort the intervals by their start times.
* Initialize a standalone `tempInterval` variable with the first interval to track the current active working state.
* Perform a single linear scan through the remaining intervals.
* If the next interval overlaps, update the end of `tempInterval`. If it does not, push `tempInterval` to the output and reset it to the current interval.

### Complexity Analysis
* **Time Complexity:** O(N log N) – Dominated by the initial sorting step; the linear scan takes O(N) time.
* **Space Complexity:** O(1) – Uses a single temporary variable for tracking state.

---

## 3. Best / Optimal Approach (Direct In-Place Evaluation)

### Description
* Sort the intervals by their start times.
* Iterate through the sorted intervals and evaluate them directly against the output array.
* If the output array is empty or the current interval's start is greater than the last merged interval's end, push it directly into the output.
* Otherwise, an overlap exists; directly mutate the end of the last interval in the output array to the maximum value.

### Complexity Analysis
* **Time Complexity:** O(N log N) – Requires O(N log N) for sorting and a strict linear traversal of O(N) for merging.
* **Space Complexity:** O(1) – Modifies the structure dynamically without allocating temporary objects or extra auxiliary buffers.

---

## Summary Table

| Strategy | Sorting | Loop Architecture | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- | :--- | :--- |
| **Brute Force** | Yes | Nested Loops | O(N^2) | O(1) |
| **Better** | Yes | Single Pass + Temp Object | O(N log N) | O(1) |
| **Best / Optimal** | Yes | Single Pass (In-Place) | O(N log N) | O(1) |