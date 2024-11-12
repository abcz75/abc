#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to perform Depth-First Traversal (DFS) using recursion
void DFT(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start, int visited[MAX_VERTICES]) {
    // Mark the current node as visited
    visited[start] = 1;
    printf("%d ", start);  // Visit the node (print it)

    // Recur for all adjacent vertices
    for (int i = 0; i < vertices; i++) {
        // If there is an edge and the vertex is not visited
        if (graph[start][i] == 1 && !visited[i]) {
            DFT(graph, vertices, i, visited);
        }
    }
}

int main() {
    // Example graph as an adjacency matrix:
    // Graph:
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
    int visited[MAX_VERTICES] = {0};  // Array to track visited vertices

    // Start DFT (DFS) from vertex 0
    printf("Depth-First Traversal starting from node 0: ");
    DFT(graph, vertices, 0, visited);

    return 0;
}

