# Dynamic Programming (1D)

## 🧠 What is 1D DP?

1D DP means:
- State depends only on previous states
- Stored in a 1D array or few variables

---

## 🔥 Core Patterns

### 1. Fibonacci Pattern
- dp[i] = dp[i-1] + dp[i-2]

Problems:
- Climbing Stairs
- Min Cost Climbing Stairs

---

### 2. Pick / Skip (Decision DP)
- dp[i] = max(take, skip)

Problems:
- House Robber
- House Robber II

---

### 3. Kadane / Running State
- Maintain best ending at current index

Problems:
- Maximum Subarray
- Maximum Product Subarray

---

### 4. Count Ways
- dp[i] = number of ways

Problems:
- Decode Ways

---

### 5. Unbounded Knapsack (Min / Count)
- dp[i] depends on dp[i - coin]

Problems:
- Coin Change (min coins)
- Coin Change II (number of ways)

---

### 6. LIS Pattern
- Increasing sequence tracking

Problems:
- Longest Increasing Subsequence
- Russian Doll Envelopes

---

## 🧠 Key Tricks

- Reverse loop → avoid reuse (0/1 Knapsack)
- Track min + max → for product problems
- Use binary search → optimize LIS to O(n log n)
- Convert 2D → 1D when possible

---

## ⚠️ Common Mistakes

- Wrong base case
- Using forward loop when backward needed
- Confusing count vs min problems
- Ignoring edge cases (0, empty)

---

## 🚀 Problems Covered

| Problem | Pattern |
|--------|--------|
| Climbing Stairs | Fibonacci |
| Min Cost Climbing Stairs | Fibonacci Variant |
| House Robber | Pick / Skip |
| House Robber II | Circular DP |
| Maximum Product Subarray | Kadane Variant |
| Decode Ways | Count Ways |
| Coin Change | Unbounded Knapsack |
| Longest Increasing Subsequence | LIS |
| Russian Doll Envelopes | LIS + Sorting |

---

## 🏁 Final Note

If you master these patterns, you can solve:
👉 70% of DP interview questions