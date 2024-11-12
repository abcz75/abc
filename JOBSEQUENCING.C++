#include <stdio.h>
#define MAX 100
int main() {
    int n;
    int jobID[MAX], deadline[MAX], profit[MAX];
    int result[MAX];  // To store the sequence of job IDs
    int slot[MAX] = {0}; // To track free time slots
    int maxProfit = 0; // Total profit initialized to zero

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Input job details
    for (int i = 0; i < n; i++) {
        printf("Enter details for job %d (ID, Deadline, Profit): ", i + 1);
        scanf("%d %d %d", &jobID[i], &deadline[i], &profit[i]);
    }

    // Simple selection sort to sort jobs by profit in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                // Swap profits
                int tempProfit = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempProfit;

                // Swap job IDs
                int tempID = jobID[j];
                jobID[j] = jobID[j + 1];
                jobID[j + 1] = tempID;

                // Swap deadlines
                int tempDeadline = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = tempDeadline;
            }
        }
    }

    // Iterate through all jobs in sorted order
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job before its deadline
        for (int j = (deadline[i] < MAX ? deadline[i] : MAX) - 1; j >= 0; j--) {
            if (slot[j] == 0) { // If the slot is free
                slot[j] = 1;       // Mark the slot as occupied
                result[j] = jobID[i]; // Store the job ID
                maxProfit += profit[i]; // Add profit to total
                break; // Exit the loop after assigning the job
            }
        }
    }

    // Print the result
    printf("Job sequence for maximum profit:\n");
    for (int i = 0; i < MAX; i++) {
        if (slot[i]) { // If the slot is occupied
            printf("Job ID: %d\n", result[i]);
        }
    }
    printf("Total profit: %d\n", maxProfit);

    return 0;
}
