#include <stdio.h>
#define MAX_ITEMS 100
#define MAX_CAPACITY 1000
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n; // Number of items
    int W; // Maximum capacity of the knapsack
    int weights[MAX_ITEMS], values[MAX_ITEMS];
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];

    // Input number of items and capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    // Input weights and values
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &weights[i], &values[i]);
    }

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0; // Base case
            } else if (weights[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j]; // Item cannot be included
            }
        }
    }

    // The maximum value is found at dp[n][W]
    printf("Maximum value in knapsack = %d\n", dp[n][W]);

    return 0;
}
