#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define maximum number of nodes
#define MAX_NODES 100

// Queue structure to store nodes for BFS
typedef struct {
    int items[MAX_NODES];
    int front, rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to enqueue an element into the queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;  // If queue is empty
    q->rear++;
    q->items[q->rear] = value;
}

// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1; // Indicating an error
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        // Reset the queue after all elements are dequeued
        q->front = q->rear = -1;
    }
    return item;
}

// Function to perform BFS traversal on the graph represented by an adjacency list
void bfs(int adjacencyList[MAX_NODES][MAX_NODES], int numNodes, int start) {
    bool visited[MAX_NODES] = {false};  // To keep track of visited nodes
    Queue q;
    initQueue(&q);
    
    visited[start] = true;  // Mark the starting node as visited
    enqueue(&q, start);     // Enqueue the starting node

    printf("BFS Traversal starting from node %d: ", start);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);  // Dequeue a node
        printf("%d ", node);      // Process the node (print it)
        
        // Visit all the neighbors of the node
        for (int i = 0; i < numNodes; i++) {
            if (adjacencyList[node][i] == 1 && !visited[i]) {
                visited[i] = true;   // Mark the neighbor as visited
                enqueue(&q, i);      // Enqueue the neighbor
            }
        }
    }
    printf("\n");
}

int main() {
    int numNodes, startNode;
    
    // Read the number of nodes in the graph
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Create an adjacency list to represent the graph
    int adjacencyList[MAX_NODES][MAX_NODES] = {0};  // Initialize all entries to 0
    
    // Read the adjacency list (graph)
    printf("Enter the adjacency list (0 or 1 for each pair):\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &adjacencyList[i][j]);
        }
    }

    // Read the starting node for BFS
    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    // Perform BFS traversal
    bfs(adjacencyList, numNodes, startNode);

    return 0;
}

