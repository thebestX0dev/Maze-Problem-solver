#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Memoization table for dynamic programming
int memo[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

/**
 * Optimized maze path counter using Dynamic Programming
 * Counts unique paths from (sr, sc) to (er, ec)
 * Can only move right or down
 * 
 * @param sr: start row
 * @param sc: start column
 * @param er: end row
 * @param ec: end column
 * @return: number of unique paths
 */
int countPaths(int sr, int sc, int er, int ec) {
    // Validate input
    if (sr > er || sc > ec) {
        return 0;
    }

    // Base case: reached destination
    if (sr == er && sc == ec) {
        return 1;
    }

    // Check memoization table
    if (memo[sr][sc] != -1) {
        return memo[sr][sc];
    }

    int paths = 0;

    // Move right
    if (sc < ec) {
        paths += countPaths(sr, sc + 1, er, ec);
    }

    // Move down
    if (sr < er) {
        paths += countPaths(sr + 1, sc, er, ec);
    }

    // Store result in memo table
    memo[sr][sc] = paths;
    return paths;
}

/**
 * Dynamic Programming approach (iterative, more efficient)
 * Builds solution from bottom-up
 */
int countPathsDP(int rows, int cols) {
    int dp[rows + 1][cols + 1];
    memset(dp, 0, sizeof(dp));

    // Initialize: there's only one way to reach any cell in first row or column
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (i == 1 || j == 1) {
                dp[i][j] = 1;
            } else {
                // Current cell = paths from above + paths from left
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[rows][cols];
}

/**
 * Display the maze grid
 */
void displayMaze(int rows, int cols) {
    printf("\n╔");
    for (int i = 0; i < cols; i++) printf("═══╦");
    printf("\b╗\n");

    for (int i = 1; i <= rows; i++) {
        printf("║");
        for (int j = 1; j <= cols; j++) {
            if (i == 1 && j == 1) {
                printf(" S ║"); // S for Start
            } else if (i == rows && j == cols) {
                printf(" E ║"); // E for End
            } else {
                printf("   ║");
            }
        }
        printf("\n");
        if (i < rows) {
            printf("╠");
            for (int j = 0; j < cols; j++) printf("═══╬");
            printf("\b╣\n");
        }
    }

    printf("╚");
    for (int i = 0; i < cols; i++) printf("═══╩");
    printf("\b╝\n");
}

/**
 * Get positive integer input with validation
 */
int getPositiveInput(const char *prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1) {
            while (getchar() != '\n');
            printf("❌ Invalid input! Please enter a valid integer.\n");
            continue;
        }
        if (value < 1) {
            printf("❌ Please enter a positive number (≥ 1).\n");
            continue;
        }
        if (value > MAX_SIZE) {
            printf("❌ Maximum size is %d.\n", MAX_SIZE);
            continue;
        }
        break;
    }
    return value;
}

/**
 * Main function with menu-driven interface
 */
int main() {
    printf("╔═══════════════════════════════════════╗\n");
    printf("║     🎯 MAZE PATH COUNTER SOLVER 🎯    ║\n");
    printf("║  Count unique paths in an m×n grid    ║\n");
    printf("║     (Move only Right or Down)         ║\n");
    printf("╚═══════════════════════════════════════╝\n\n");

    while (1) {
        // Initialize memoization table
        memset(memo, -1, sizeof(memo));

        // Get dimensions
        int rows = getPositiveInput("📏 Enter number of rows (1-100): ");
        int cols = getPositiveInput("📏 Enter number of columns (1-100): ");

        // Display maze visualization
        displayMaze(rows, cols);

        // Method 1: Recursive with Memoization
        printf("\n⏱️  Method 1: Recursive with Memoization\n");
        int paths1 = countPaths(1, 1, rows, cols);
        printf("✅ Number of unique paths: %d\n", paths1);

        // Method 2: Dynamic Programming (Iterative)
        printf("\n⏱️  Method 2: Dynamic Programming (Iterative - Faster)\n");
        int paths2 = countPathsDP(rows, cols);
        printf("✅ Number of unique paths: %d\n", paths2);

        // Verify both methods match
        if (paths1 == paths2) {
            printf("\n✔️  Both methods verified! Results match.\n");
        }

        // Option to continue
        printf("\n" "─────────────────────────────\n");
        printf("Do you want to try another maze? (1=Yes, 0=No): ");
        int choice;
        if (scanf("%d", &choice) != 1 || choice != 1) {
            printf("\n👋 Thank you for using Maze Path Counter!\n");
            break;
        }
        printf("\n");
    }

    return 0;
}
