#include <stdio.h>

#define MAX_ITEMS 100

int maxProfit = 0;

void knapsack(int weights[], int values[], int n, int capacity, int index, int currentWeight, int currentProfit) {
    if (index == n) {
        if (currentProfit > maxProfit) {
            maxProfit = currentProfit;
        }
        return;
    }

    if (currentWeight + weights[index] <= capacity) {
        knapsack(weights, values, n, capacity, index + 1, currentWeight + weights[index], currentProfit + values[index]);
    }

    knapsack(weights, values, n, capacity, index + 1, currentWeight, currentProfit);
}

int main() {
    int n, capacity;
    int weights[MAX_ITEMS], values[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &values[i]);
    }

    knapsack(weights, values, n, capacity, 0, 0, 0);

    printf("Maximum profit: %d\n", maxProfit);

    return 0;
}