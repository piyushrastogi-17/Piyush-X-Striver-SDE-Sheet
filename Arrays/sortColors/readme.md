# 📌 LeetCode 75: Sort Colors — Updated Reference

## 💡 Strategy Comparisons

### 1. Brute Force (Selection Sort)
* **How it works:** Uses two nested loops to scan the array, find the smallest remaining element, and swap it into its correct position step-by-step.
* **Time Complexity:** $O(N^2)$
* **Space Complexity:** $O(1)$
* **Status:** **Rejected** (Too slow for large inputs).

### 2. Better Approach (Your Counting Sort)
* **How it works:** A two-pass scan. First pass counts the total frequencies of `0`s, `1`s, and `2`s. Second pass overwrites the original array sequentially based on those counts.
* **Time Complexity:** $O(N)$
* **Space Complexity:** $O(1)$
* **Status:** **Accepted**

### 3. Optimal Approach (Dutch National Flag)
* **How it works:** A single-pass scan using three pointers (`low`, `mid`, `high`) to dynamically swap elements into their correct zones as you read them.
* **Time Complexity:** $O(N)$
* **Space Complexity:** $O(1)$
* **Status:** **Accepted (Most Expected)**