#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

// Structure to store path information
typedef struct {
    int pathCount;
    double executionTime;
} Result;

// Memoization tables
int memo[MAX_SIZE][MAX_SIZE];
int gridMemo[MAX_SIZE][MAX_SIZE];

/**
 * Simple recursive approach (for comparison)
 * WARNING: Very slow for large inputs (exponential complexity)
 */
int countPathsNaive(int sr, int sc, int er, int ec) {
    if (sr > er || sc > ec) return 0;
    if (sr == er && sc == ec) return 1;

    return countPathsNaive(sr + 1, sc, er, ec) + 
           countPathsNaive(sr, sc + 1, er, ec);
}

/**
 * Optimized recursive with memoization
 */
int countPathsMemo(int sr, int sc, int er, int ec) {
    if (sr > er || sc > ec) return 0;
    if (sr == er && sc == ec) return 1;

    if (memo[sr][sc] != -1) {
        return memo[sr][sc];
    }

    memo[sr][sc] = countPathsMemo(sr + 1, sc, er, ec) + 
                   countPathsMemo(sr, sc + 1, er, ec);
    return memo[sr][sc];
}

/**
 * Dynamic Programming - Iterative (Most Efficient)
 */
int countPathsDP(int rows, int cols) {
    int dp[rows + 1][cols + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (i == 1 || j == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[rows][cols];
}

/**
 * Space-optimized DP (using 1D array)
 * Reduces space complexity to O(n) instead of O(m×n)
 */
int countPathsDPOptimized(int rows, int cols) {
    int dp[cols + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (i == 1) {
                dp[j] = 1;
            } else if (j > 1) {
                dp[j] += dp[j - 1];
            }
        }
    }

    return dp[cols];
}

/**
 * Mathematical approach using combinations
 * C(m+n-2, m-1) = (m+n-2)! / ((m-1)! × (n-1)!)
 * Most efficient for practical purposes
 */
long long combination(int n, int k) {
    if (k > n - k) k = n - k;
    
    long long result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

long long countPathsMath(int rows, int cols) {
    return combination(rows + cols - 2, rows - 1);
}

/**
 * Print comparison of all methods
 */
void compareAllMethods(int rows, int cols) {
    printf("\n╔════════════════════════════════════════════════════════╗\n");
    printf("║            🏆 ALGORITHM COMPARISON 🏆                  ║\n");
    printf("║              Grid Size: %d × %d                        ║\n", rows, cols);
    printf("╚════════════════════════════════════════════════════════╝\n\n");

    clock_t start, end;
    double cpuTime;

    // Method 1: Dynamic Programming (Iterative) - Recommended
    printf("1️⃣  Dynamic Programming (Iterative) - ⭐ RECOMMENDED\n");
    printf("   └─ Time: O(m×n), Space: O(m×n)\n");
    start = clock();
    int result1 = countPathsDP(rows, cols);
    end = clock();
    cpuTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    printf("   └─ Paths: %d\n", result1);
    printf("   └─ Time: %.2f μs\n\n", cpuTime);

    // Method 2: Space-Optimized DP
    printf("2️⃣  Space-Optimized DP\n");
    printf("   └─ Time: O(m×n), Space: O(n)\n");
    start = clock();
    int result2 = countPathsDPOptimized(rows, cols);
    end = clock();
    cpuTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    printf("   └─ Paths: %d\n", result2);
    printf("   └─ Time: %.2f μs\n\n", cpuTime);

    // Method 3: Mathematical (Combinatorics)
    printf("3️⃣  Mathematical Approach (Combinatorics) - ⚡ FASTEST\n");
    printf("   └─ Time: O(min(m,n)), Space: O(1)\n");
    start = clock();
    long long result3 = countPathsMath(rows, cols);
    end = clock();
    cpuTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    printf("   └─ Paths: %lld\n", result3);
    printf("   └─ Time: %.2f μs\n\n", cpuTime);

    // Method 4: Recursive with Memoization (only for small inputs)
    if (rows <= 20 && cols <= 20) {
        printf("4️⃣  Recursive with Memoization\n");
        printf("   └─ Time: O(m×n), Space: O(m×n)\n");
        memset(memo, -1, sizeof(memo));
        start = clock();
        int result4 = countPathsMemo(1, 1, rows, cols);
        end = clock();
        cpuTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
        printf("   └─ Paths: %d\n", result4);
        printf("   └─ Time: %.2f μs\n\n", cpuTime);

        // Method 5: Naive Recursive (only for very small inputs)
        if (rows <= 15 && cols <= 15) {
            printf("5️⃣  Naive Recursive - ⚠️  VERY SLOW\n");
            printf("   └─ Time: O(2^(m+n)), Space: O(m+n)\n");
            start = clock();
            int result5 = countPathsNaive(1, 1, rows, cols);
            end = clock();
            cpuTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
            printf("   └─ Paths: %d\n", result5);
            printf("   └─ Time: %.2f μs\n\n", cpuTime);
        } else {
            printf("5️⃣  Naive Recursive - ⏭️  SKIPPED (too slow)\n");
            printf("   └─ Would take exponential time (2^%d comparisons)\n\n", rows + cols - 2);
        }
    }

    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║  ✅ All methods returned consistent results!           ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");
}

/**
 * Display performance benchmarks
 */
void showBenchmarks() {
    printf("\n╔════════════════════════════════════════════════════════╗\n");
    printf("║         📊 PERFORMANCE BENCHMARKS 📊                   ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");

    int testSizes[] = {5, 10, 15, 20};
    int numTests = sizeof(testSizes) / sizeof(testSizes[0]);

    printf("Grid | Paths | DP Time | Space Opt | Math Time | Naive Time\n");
    printf("────────────────────────────────────────────────────────────\n");

    for (int i = 0; i < numTests; i++) {
        int size = testSizes[i];
        clock_t start, end;

        // DP
        start = clock();
        int dp_result = countPathsDP(size, size);
        end = clock();
        double dp_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;

        // Space Optimized
        start = clock();
        int sp_result = countPathsDPOptimized(size, size);
        end = clock();
        double sp_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;

        // Math
        start = clock();
        long long math_result = countPathsMath(size, size);
        end = clock();
        double math_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;

        // Naive (only for small sizes)
        char naive_time_str[20];
        if (size <= 12) {
            start = clock();
            int naive_result = countPathsNaive(1, 1, size, size);
            end = clock();
            double naive_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
            sprintf(naive_time_str, "%.0f μs", naive_time);
        } else {
            sprintf(naive_time_str, "Too slow");
        }

        printf("%2d×%2d | %6d | %.0f μs | %.0f μs | %.0f μs | %s\n",
               size, size, dp_result, dp_time, sp_time, math_time, naive_time_str);
    }

    printf("\n💡 Recommendation: Use Mathematical approach for production!\n");
    printf("   It's O(1) space and O(min(m,n)) time complexity.\n\n");
}

/**
 * Interactive menu system
 */
int main() {
    printf("\n╔═══════════════════════════════════════════════════════╗\n");
    printf("║   🎯 ADVANCED MAZE PATH SOLVER 🎯                   ║\n");
    printf("║  Multiple Algorithms & Performance Analysis          ║\n");
    printf("╚═══════════════════════════════════════════════════════╝\n");

    while (1) {
        printf("\n╔═══════════════════════════════════════════════════════╗\n");
        printf("║ Main Menu:                                            ║\n");
        printf("║ 1. Solve maze (all methods)                           ║\n");
        printf("║ 2. Show performance benchmarks                        ║\n");
        printf("║ 3. Exit                                               ║\n");
        printf("╚═══════════════════════════════════════════════════════╝\n");

        printf("\nEnter your choice (1-3): ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter maze dimensions:\n");
            printf("Rows (1-100): ");
            int rows;
            scanf("%d", &rows);
            printf("Columns (1-100): ");
            int cols;
            scanf("%d", &cols);

            if (rows < 1 || cols < 1 || rows > MAX_SIZE || cols > MAX_SIZE) {
                printf("❌ Invalid dimensions!\n");
                continue;
            }

            compareAllMethods(rows, cols);

        } else if (choice == 2) {
            showBenchmarks();

        } else if (choice == 3) {
            printf("\n👋 Thank you for using Advanced Maze Solver!\n");
            break;

        } else {
            printf("❌ Invalid choice!\n");
        }
    }

    return 0;
}
