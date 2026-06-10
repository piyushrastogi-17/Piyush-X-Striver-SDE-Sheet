# 📌 LeetCode 53: Maximum Subarray — Interview Cheat Sheet

## 🔍 Problem Statement (In Short)
Given an integer array `nums`, find the contiguous subarray which has the largest sum and return its sum.

### ⚠️ Strict Constraints:
* Must handle all-negative arrays cleanly (e.g., `[-2, -1]` must return `-1`).
* Expected target time complexity is linear $O(N)$.

---

## 💡 Core Logic & Strategies



### 1. Brute Force Approach
* **How it works:** Three nested loops. Loop `i` picks the start, loop `j` picks the end, and loop `k` calculates the total sum between them.
* **Time Complexity:** $O(N^3)$
* **Space Complexity:** $O(1)$
* **Status:** **TLE (Time Limit Exceeded)**

### 2. Better Approach
* **How it works:** Two nested loops. Eliminates loop `k` by keeping a rolling sum as loop `j` expands to the right.
* **Time Complexity:** $O(N^2)$
* **Space Complexity:** $O(1)$
* **Status:** **TLE (Time Limit Exceeded)**

### 3. Optimal Strategy (Kadane's Algorithm)
* **How it works:** One single pass loop. Walk left-to-right adding elements to `currentSum`.
  * Track the largest sum in `maxSum`.
  * **The Golden Rule:** If `currentSum` drops below `0`, it will only reduce the sum of subsequent elements. Drop it immediately by resetting `currentSum = 0`.
* **Time Complexity:** $O(N)$
* **Space Complexity:** $O(1)$
* **Status:** **Accepted (Best)**

---

## ⏱️ Complexity Summary (For Interviews)

* **Time Complexity:** **$O(N)$** because we inspect each element exactly once in a single linear pass.
* **Space Complexity:** **$O(1)$** as everything is tracked using scalar variables without utilizing any extra data structures.

---

## 📊 Quick Revision Table

| Strategy | Loop Mechanism | Time Complexity | Space Complexity | Interview Verdict |
| :--- | :--- | :--- | :--- | :--- |
| **Brute Force** | 3 Nested Loops | $O(N^3)$ | $O(1)$ | Unacceptable |
| **Better** | 2 Nested Loops | $O(N^2)$ | $O(1)$ | Sub-optimal |
| **Kadane's (Optimal)** | 1 Single Pass | **$O(N)$** | **$O(1)$** | **Perfect / Expected** |