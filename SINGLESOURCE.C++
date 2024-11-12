#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Define a structure for an edge
struct Edge {
    int src, dest, weight;
};

// Function to print the shortest distance from the source
void printDistances(int dist[], int V) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Function to find the vertex with the minimum distance
int findMinVertex(int dist[], bool visited[], int V) {
    int minDistance = INT_MAX;
    int minVertex = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < minDistance) {
            minDistance = dist[i];
            minVertex = i;
        }
    }

    return minVertex;
}

// Dijkstra's algorithm function
void dijkstra(int V, int E, struct Edge edges[], int src) {
    int dist[V];        // Distance array
    bool visited[V];    // Visited array

    // Initialize distances and visited status
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX; // Set all distances to infinity
        visited[i] = false; // Mark all vertices as unvisited
    }
    dist[src] = 0; // Distance to the source is 0

    // Process each vertex
    for (int i = 0; i < V - 1; i++) {
        int u = findMinVertex(dist, visited, V); // Find the closest unvisited vertex
        if (u == -1) break; // If no vertex is reachable, exit the loop
        visited[u] = true;  // Mark it as visited

        // Relax all edges originating from u
        for (int j = 0; j < E; j++) {
            if (edges[j].src == u) {
                int v = edges[j].dest;
                int weight = edges[j].weight;

                if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Print the distances
    printDistances(dist, V);
}

int main() {
    int V, E, src;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];
    printf("Enter the edges in the format (source, destination, weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    // Call Dijkstra's algorithm
    dijkstra(V, E, edges, src);

    return 0;
}
