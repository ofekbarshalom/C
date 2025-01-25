#include <stdio.h>
#define MAX_ITEMS 5 // Define the maximum number of items

int knapsack(int values[], int weights[], int sackSize, int isSelected[]) {
    int dp[MAX_ITEMS + 1][sackSize + 1]; // DP table
    int i, w;

    // Initialize the DP table
    for (i = 0; i <= MAX_ITEMS; i++) {
        for (w = 0; w <= sackSize; w++) {
            dp[i][w] = 0;
        }
    }

    // Fill the DP table
    for (i = 1; i <= MAX_ITEMS; i++) {
        for (w = 0; w <= sackSize; w++) {
            if (weights[i - 1] <= w) { 
                // Item can be included
                if (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) {
                    dp[i][w] = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            } else {
                // Item cannot be included
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtrack to find the selected items
    int totalValue = dp[MAX_ITEMS][sackSize];
    w = sackSize;

    for (i = MAX_ITEMS; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) { // Item i-1 was selected
            isSelected[i - 1] = 1;
            w -= weights[i - 1];
        } else {
            isSelected[i - 1] = 0;
        }
    }

    return totalValue; // Return the maximum profit
}

int main() {
    int values[MAX_ITEMS];
    int weights[MAX_ITEMS];
    int sackSize;
    int isSelected[MAX_ITEMS] = {0}; // Array to track selected items

    // User inputs the values and weights arrays
    printf("Enter the item values and weights:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &values[i]);

        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weights[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &sackSize);

    // Call the knapsack function
    int maxProfit = knapsack(values, weights, sackSize, isSelected);
    
    printf("\nMaximum profit: %d\n", maxProfit);
    printf("Selected items (1: selected, 0: not selected):\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("Item %d: %s\n", i + 1, isSelected[i] ? "Selected" : "Not Selected");
    }

    return 0;
}
