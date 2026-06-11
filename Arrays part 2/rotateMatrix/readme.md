# Rotate Matrix (90 Degrees) — Quick Interview Guide

A concise reference sheet for rotating a square ($N \times N$) matrix in technical interviews.

---

## 1. Brute Force Approach (Clockwise)

### Approach
* Allocate a brand-new temporary matrix of the same size.
* Map elements directly to their rotated positions: the **first row** of the input becomes the **last column** of the temporary matrix, the second row becomes the second-to-last column, and so forth.
* Copy the values from the temporary matrix back into the original matrix.

### Complexity Analysis
* **Time Complexity:** $\mathcal{O}(N^2)$ — You must loop through every single element in the grid exactly once to place it in the new matrix.
* **Space Complexity:** $\mathcal{O}(N^2)$ — Memory allocation scales with the size of the input grid because a full secondary matrix is required.

---

## 2. Better/Optimal Approach (Clockwise Rotation)

### Approach
This approach performs the rotation **in-place** (without allocating a secondary matrix) using two consecutive matrix modifications:
1. **Transpose the Matrix:** Swap elements across the main diagonal ($matrix[i][j]$ with $matrix[j][i]$). This transforms all horizontal rows into vertical columns. *(Note: The inner loop must start at $j = i + 1$ to avoid swapping elements back to their original state).*
2. **Reverse Each Row:** Flip every row horizontally from left to right. This repositions the columns into the correct clockwise layout.

### Complexity Analysis
* **Time Complexity:** $\mathcal{O}(N^2)$
  * Transposition loops through roughly half the grid $\left(\frac{N^2}{2}\right)$.
  * Reversing each row takes $\left(\frac{N^2}{2}\right)$ basic steps.
  * Total running time remains strictly quadratic.
* **Space Complexity:** $\mathcal{O}(1)$ — No extra arrays are created. Changes are written directly to the input matrix.

---

## 3. Better/Optimal Approach (Anticlockwise Rotation)

### Approach
This approach performs a counter-clockwise rotation **in-place** by altering the secondary axis transformation:
1. **Transpose the Matrix:** Mirror the grid along its main diagonal ($matrix[i][j] \leftrightarrow matrix[j][i]$), exactly like the clockwise setup. Rows become columns.
2. **Reverse Columns (Swap Rows):** Instead of flipping individual rows horizontally, flip the matrix vertically. Swap the entire top row with the bottom row, the second row with the second-to-last row, moving toward the middle.

### Complexity Analysis
* **Time Complexity:** $\mathcal{O}(N^2)$
  * Transposition operates on $\frac{N^2}{2}$ elements.
  * Swapping row vectors vertically takes $\frac{N}{2}$ swaps, where each swap shifts a row of length $N$ (equating to $\frac{N^2}{2}$ individual element reassignments).
  * Total operations scale quadratically.
* **Space Complexity:** $\mathcal{O}(1)$ — Edits are completed strictly inside the input framework using constant auxiliary variables.

---

## Interview Cheat-Sheet Reminders

* **In-Place Trick:** If an interviewer specifies an in-place constraint, you can almost always solve it by using a **Transpose** combined with a **Reversal** (either horizontal row reversal or vertical row swapping).
* **The Index Trap:** When explaining matrix transposition, always stress that the nested loop bounds are restricted ($j$ starts at $i + 1$). If you loop through the entire grid ($j = 0$ to $N$), elements get double-swapped and the matrix remains unchanged.