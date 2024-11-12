#include <stdio.h>
#include <stdlib.h>

// Max number of vertices in the graph
#define MAX_VERTICES 100

// Queue structure for BFT
struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to enqueue an element
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;  // If queue is empty
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to dequeue an element
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;  // Reset queue after last element
    } else {
        q->front++;
    }
    return item;
}

// Function to perform BFT (Breadth-First Traversal)
void BFT(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start) {
    // Array to track visited nodes
    int visited[MAX_VERTICES] = {0};

    // Initialize queue
    struct Queue q;
    initQueue(&q);

    // Start with the given start node
    visited[start] = 1;
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        // Dequeue the front element
        int currentNode = dequeue(&q);
        printf("%d ", currentNode);  // Visit the node (print it)

        // Enqueue all unvisited neighbors
        for (int i = 0; i < vertices; i++) {
            if (graph[currentNode][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    // Adjacency matrix for the graph
    // For example, the graph:
    // 0 - 1 - 2
    // |   |
    // 3 - 4
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 1, 0},  // 0 is connected to 1 and 3
        {1, 0, 1, 0, 1},  // 1 is connected to 0, 2, and 4
        {0, 1, 0, 0, 0},  // 2 is connected to 1
        {1, 0, 0, 0, 1},  // 3 is connected to 0 and 4
        {0, 1, 0, 1, 0}   // 4 is connected to 1 and 3
    };
    
    int vertices = 5;  // Number of vertices in the graph
    int start = 0;     // Starting node for BFT (0-based index)

    printf("Breadth-First Traversal starting from node %d: ", start);
    BFT(graph, vertices, start);

    return 0;
}

