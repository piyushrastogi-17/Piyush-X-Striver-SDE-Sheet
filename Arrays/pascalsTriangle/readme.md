# Pascal's Triangle - Complete Revision Notes

## Problem Statement

Pascal's Triangle is a triangular arrangement of numbers where:

* First and last element of every row is `1`.
* Every middle element is the sum of the two elements directly above it.

Example:

```text
        1
      1   1
    1   2   1
  1   3   3   1
1   4   6   4   1
```

---

# Type 1: Find Element at Given Position (r, c)

### Problem

Given row `r` and column `c`, find the element present at that position.

Example:

```text
Row = 5
Col = 3

Answer = 6
```

---

## Observation

Any element in Pascal's Triangle is:

C(r-1, c-1)

Example:

```text
Row = 5
Col = 3

C(4,2) = 6
```

---

## Formula

```text
nCr = n! / (r! * (n-r)!)
```

Optimized computation:

```cpp
ans = ans * (n-i);
ans = ans / (i+1);
```

---

## Approach

1. Convert position into nCr.
2. Compute nCr efficiently.
3. Return answer.

---

## Time Complexity

```text
O(c)
```

## Space Complexity

```text
O(1)
```

---

# Type 2: Print Nth Row

### Problem

Given row number N, print the complete row.

Example:

```text
N = 5

1 4 6 4 1
```

---

## Observation

Every element of a row can be generated from the previous one.

If current element is:

```text
C(n,r)
```

then next element is:

```text
C(n,r+1)
=
C(n,r) * (n-r)/(r+1)
```

Thus no factorial calculation is needed.

---

## Approach

1. Start with first element = 1.
2. Generate next element using previous element.
3. Store all elements.

---

## Code Logic

```cpp
ans = ans * (n-i);
ans = ans / i;
```

---

## Time Complexity

```text
O(N)
```

## Space Complexity

```text
O(N)
```

---

# Type 3: Print Entire Pascal Triangle

### Problem

Given N, print first N rows.

Example:

```text
N = 5

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
```

---

## Observation

Type 3 is simply an extension of Type 2.

Generate every row independently and push it into the answer.

---

## Approach

For every row:

1. Generate row using Type 2 logic.
2. Store row.
3. Repeat until N rows are generated.

---

## Pseudocode

```cpp
for(i = 1 to N)
{
    row = generateRow(i);
    answer.push_back(row);
}
```

---

## Time Complexity

```text
1 + 2 + 3 + ... + N

= O(N²)
```

## Space Complexity

```text
O(N²)
```

because all rows are stored.

---

# Interview Takeaways

### Type 1

Find a specific element.

```text
Answer = C(r-1,c-1)
```

Time:

```text
O(c)
```

---

### Type 2

Print a single row.

Use:

```text
next = current * (n-r)/(r+1)
```

Time:

```text
O(N)
```

---

### Type 3

Print complete triangle.

Generate every row using Type 2.

Time:

```text
O(N²)
```

---

# One-Line Revision

```text
Type 1 → Find element → nCr

Type 2 → Print row → Generate next element from previous

Type 3 → Print triangle → Repeatedly generate rows
```
