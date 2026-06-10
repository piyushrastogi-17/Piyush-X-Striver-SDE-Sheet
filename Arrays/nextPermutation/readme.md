# 📌 LeetCode 31: Next Permutation — Interview Cheat Sheet

## 🔍 Problem Statement (In Short)
Rearrange an array of numbers into its **lexicographically next greater permutation** (the next higher number combination in dictionary order).

### ⚠️ Strict Constraints:
* **In-place:** You cannot copy the elements into a second temporary array.
* **Space Complexity:** Only constant extra memory $O(1)$ is allowed.
* **Edge Case:** If the array is already at its largest possible value (completely sorted in descending order like `[3, 2, 1]`), reset it to the smallest possible order by reversing it to `[1, 2, 3]`.

---

## 💡 Core Logic (The 3-Step Strategy)
Scan the array from right to left (backward) and follow these 3 clear steps:



### 1. Find the Break-Point (The Pivot)
* Walk backward from the end of the array.
* Stop at the first element that is **smaller** than the element right next to it ($nums[i] < nums[i + 1]$).
* This element is called the **pivot**.
* *Example:* In `[1, 3, 5, 4, 2]`, walking backward shows `2 < 4 < 5`. The increasing streak breaks at `3` because `3 < 5`. Our pivot is `3`.

### 2. Find the Substitute & Swap
* Look at the numbers to the right of the pivot. We need to find the next highest number to replace our pivot.
* Walk backward from the end of the array again.
* Find the first number that is **strictly greater** than our pivot. This is the **successor**.
* **Swap** the pivot and the successor.
* *Example:* The first number greater than `3` from the back is `4`. Swapping `3` and `4` changes the array to `[1, 4, 5, 3, 2]`.

### 3. Reverse the Suffix
* All elements to the right of our old pivot position are currently in descending order (`[5, 3, 2]`). This makes the number unnecessarily large.
* **Reverse** all elements to the right of the old pivot position to turn them into ascending order (making this tail section as small as possible).
* *Example:* `[5, 3, 2]` reversed becomes `[2, 3, 5]`.
* **Final Result:** `[1, 4, 2, 3, 5]`.

> **Note (Edge Case):** If you scan backward in Step 1 and never find a pivot (meaning the entire array is descending, like `[3, 2, 1]`), skip Step 2 and simply **reverse the entire array**.

---

## ⏱️ Complexity Analysis (For Interviews)

* **Time Complexity:** **$O(N)$**
  * We scan the array backward at most twice ($O(N)$).
  * Reversing the suffix section takes linear time ($O(N)$).
  * Total time is linear ($O(N)$), which is highly optimal and passes all LeetCode constraints.

* **Space Complexity:** **$O(1)$**
  * All swaps and modifications are done directly inside the original array. No extra arrays, hash maps, or sets are used.

---

## 📊 Quick Revision Table

| Metrics | Brute Force Approach | Optimal Strategy (Narayana Pandita) |
| :--- | :--- | :--- |
| **How it works** | Generate all permutations, sort them, and pick the next index. | Scan digits from right to left and swap key elements in-place. |
| **Time Complexity** | $O(N \cdot N!)$ *(Causes Time Limit Exceeded / TLE)* | **$O(N)$** *(Linear Time - Accepted)* |
| **Space Complexity**| $O(N \cdot N!)$ *(To store all combinations)* | **$O(1)$** *(Constant Space - Best)* |