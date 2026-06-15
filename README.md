# 🎯 Maze Problem Solver

A high-performance solution to count unique paths in an m×n grid where you can only move **right** or **down**.

## 📋 Features

- **Dynamic Programming Optimization** - O(m×n) time complexity vs exponential recursive approach
- **Memoization** - Caches intermediate results for efficient recursion
- **Visualization** - ASCII art maze display with start (S) and end (E) markers
- **Input Validation** - Robust error handling for user inputs
- **Menu-Driven Interface** - Easy-to-use interactive experience
- **Dual Algorithm Comparison** - Compare recursive and iterative approaches

## 🚀 Quick Start

### Compile
```bash
gcc -o maze maze_solver_optimized.c
```

### Run
```bash
./maze
```

### Example
```
📏 Enter number of rows (1-100): 3
📏 Enter number of columns (1-100): 3

╔═══╦═══╦═══╗
║ S ║   ║   ║
╠═══╬═══╬═══╣
║   ║   ║   ║
╠═══╬═══╬═══╣
║   ║   ║ E ║
╚═══╩═══╩═══╝

✅ Number of unique paths: 6
```

## 🧮 Algorithm Explanation

### Problem
Given an m×n grid, count the number of unique paths from top-left (1,1) to bottom-right (m,n) where you can only move **right** or **down**.

### Solution Approaches

#### 1️⃣ **Recursive with Memoization**
```
T(m,n) = T(m-1,n) + T(m,n-1)
Base: T(1,1) = 1
```
- Time: O(m×n)
- Space: O(m×n)

#### 2️⃣ **Dynamic Programming (Iterative) - Recommended**
```
dp[i][j] = dp[i-1][j] + dp[i][j-1]
```
- Time: O(m×n)
- Space: O(m×n)
- Faster due to no recursion overhead

### Mathematical Formula
For an m×n grid, the number of paths = **C(m+n-2, m-1)** = (m+n-2)! / ((m-1)! × (n-1)!)

**Examples:**
- 2×2 grid: 2 paths
- 3×3 grid: 6 paths
- 4×4 grid: 20 paths
- 5×5 grid: 70 paths

## 📊 Complexity Analysis

| Metric | Naive Recursion | With Memoization | DP Iterative |
|--------|-----------------|------------------|--------------|
| Time   | O(2^(m+n))      | O(m×n)           | O(m×n)       |
| Space  | O(m+n)          | O(m×n)           | O(m×n)       |
| Speed  | ❌ Very Slow    | ✅ Fast          | ✅✅ Fastest  |

## 📁 File Structure

```
Maze-Problem-solver/
├── maze_solver_optimized.c      # Main optimized solution ⭐
├── maze_solver_advanced.c       # Advanced with benchmarks
├── MAZE Problem solver.c         # Original solution (reference)
├── Makefile                      # Build automation
└── README.md                     # This file
```

## 🔧 Customization

### Change Maximum Grid Size
Edit line 7 in `maze_solver_optimized.c`:
```c
#define MAX_SIZE 100  // Change this value
```

### Change Starting Position
The grid is indexed from (1,1) in the current implementation. To change:
1. Modify the `countPaths()` function call
2. Update the `displayMaze()` visualization accordingly

## 💡 Use Cases

- **Interview Preparation** - Classic dynamic programming problem
- **Algorithm Learning** - Master DP optimization techniques
- **Path Finding** - Foundation for more complex maze problems
- **Robot Movement** - Calculate possible routes for grid-based robots

## 🎓 Learning Outcomes

After studying this code, you'll understand:
- ✅ Recursive problem solving
- ✅ Memoization technique
- ✅ Dynamic Programming approach
- ✅ Bottom-up DP construction
- ✅ Time-space tradeoffs
- ✅ Input validation
- ✅ Clean code practices

## 🔮 Future Enhancements

- [ ] Save maze configurations to file
- [ ] Visualize all possible paths
- [ ] Support obstacles/blocked cells
- [ ] Add 4-directional movement (left, right, up, down)
- [ ] Implement with diagonal movements
- [ ] GUI version using graphics library
- [ ] Multi-threaded pathfinding
- [ ] WebAssembly version

## 📝 Original Problem vs Enhanced Solution

### Before ❌
- Exponential time complexity (inefficient)
- No input validation
- Poor user experience
- Limited visualization

### After ✅
- O(m×n) optimized algorithms
- Robust error handling
- Interactive menu interface
- ASCII maze visualization
- Dual algorithm implementation
- Comprehensive documentation

## 🤝 Contributing

Feel free to:
- Report issues
- Suggest improvements
- Add new features
- Optimize further

## 📜 License

This project is open source and available under the MIT License.

---

**Made with ❤️ for algorithm enthusiasts** 🚀
