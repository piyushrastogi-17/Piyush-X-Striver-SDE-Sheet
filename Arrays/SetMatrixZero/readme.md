# 📌 Set Matrix Zeroes - Quick Revision Notes

A clean, professional markdown cheat sheet for the **Set Matrix Zeroes** problem, covering all three major approaches with their complexities.

---

##  Core Concept

The goal is to modify an $N \times M$ matrix such that if any cell contains `0`, its entire row and column are updated to `0`. The challenge lies in doing this without letting newly added zeros interfere with your scans.

---

##  Approaches Breakdown

### 1. Brute-Force Approach (Temporary Markers)
* **Logic:** Scan the matrix sequentially. When a `0` is found, avoid updating the entire row/column to `0` immediately (as this creates a chain reaction). Instead, change all non-zero elements in that row and column to a temporary marker like `-1`. After scanning the whole matrix, run a final pass to turn all `-1` markers into `0`.
* **Drawback:** This approach fails if the matrix can naturally contain negative values (like `-1`) as valid initial data.
* **Time Complexity:** $O(N \times M \times (N + M))$ — Inefficient due to repeated row/column traversals for every zero found.
* **Space Complexity:** $O(1)$ — Done entirely in-place without auxiliary structures.

### 2. Better Approach (Using Hash Arrays)
* **Logic:** Use two separate tracker arrays: a row array of size $N$ and a column array of size $M$, initialized to false. 
  1. **First Pass:** Traverse the matrix. If `matrix[i][j] == 0`, mark `row_array[i] = true` and `col_array[j] = true`.
  2. **Second Pass:** Traverse the matrix again. If either `row_array[i]` or `col_array[j]` is true, update `matrix[i][j] = 0`.
* **Time Complexity:** $O(N \times M)$ — Optimized because the matrix is scanned exactly twice.
* **Space Complexity:** $O(N + M)$ — Requires extra memory allocation for the two tracking arrays.

### 3. Optimal Approach (In-Place Tracking)
* **Logic:** Eliminate extra memory by utilizing the **first row** and **first column** of the matrix itself to act as the tracking arrays.
  1. Use a single variable `col0` to track if the first column needs to be zeroed out. (The first row's status is tracked inherently by `matrix[0][0]`).
  2. Scan the matrix from `(0,0)`. If `matrix[i][j] == 0`, mark its row header `matrix[i][0] = 0` and column header `matrix[0][j] = 0` (setting `col0 = 0` if it's in the first column).
  3. Iterate through the inner matrix cells (from index `1,1` to `N,M`) and zero them out based on the row/column headers.
  4. Finally, update the first row and first column based on `matrix[0][0]` and `col0`.
* **Time Complexity:** $O(N \times M)$ — Optimal scanning runtime.
* **Space Complexity:** $O(1)$ — True constant space with no extra data structures.

---

## 📊 Quick Revision Table

| Approach | Time Complexity | Space Complexity | Best Used For |
| :--- | :--- | :--- | :--- |
| **Brute Force** | $O(N \times M \times (N + M))$ | $O(1)$ | Small grids without negative integers. |
| **Better** | $O(N \times M)$ | $O(N + M)$ | When code simplicity is preferred over strict space limits. |
| **Optimal** | $O(N \times M)$ | $O(1)$ | **Standard Interview Winner.** Maximum efficiency. |