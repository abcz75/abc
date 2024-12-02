#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    int id;       // Job ID
    int deadline; // Deadline of the job
    int profit;   // Profit of the job
} Job;

// Comparator function to sort jobs by profit in descending order
int compare(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit;
}

// Function to perform job scheduling
void jobScheduling(Job jobs[], int n) {
    // Sort jobs based on descending profit
    qsort(jobs, n, sizeof(Job), compare);

    int result[n];  // To store the scheduled job IDs
    int slot[n];    // To keep track of occupied time slots

    // Initialize all slots as free
    for (int i = 0; i < n; i++) {
        slot[i] = 0;
    }

    // Try to schedule each job
    for (int i = 0; i < n; i++) {
        // Find a free slot for the job starting from its deadline
        for (int j = (jobs[i].deadline < n ? jobs[i].deadline : n) - 1; j >= 0; j--) {
            if (slot[j] == 0) {  // If slot is free
                slot[j] = 1;     // Mark slot as occupied
                result[j] = jobs[i].id; // Schedule the job
                break;
            }
        }
    }

    // Print scheduled jobs
    printf("Scheduled Jobs: ");
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("%d ", result[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job *jobs = (Job *)malloc(n * sizeof(Job));

    printf("Enter job details (ID, Deadline, Profit) for each job:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobScheduling(jobs, n);

    free(jobs);  // Free allocated memory
    return 0;
}