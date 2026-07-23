#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
void dfs(int node, int **adj, int *adjSize, bool *visited) {
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, adj, adjSize, visited);
        }
    }
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    // Allocate memory for adjacency list sizes
    int *adjSize = (int *)calloc(n, sizeof(int));

    // Count degree of each node
    for (int i = 0; i < edgesSize; i++) {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }

    // Allocate adjacency list
    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        adj[i] = (int *)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0; // Reset for filling
    }

    // Fill adjacency list
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    // Visited array
    bool *visited = (bool *)calloc(n, sizeof(bool));

    // Perform DFS
    dfs(source, adj, adjSize, visited);

    bool ans = visited[destination];

    // Free memory
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSize);
    free(visited);

    return ans;
}

// Example usage
int main() {
    int n = 3;

    int edgeData[2][2] = {{0,1}, {1,2}};
    int *edges[2];
    for(int i = 0; i < 2; i++)
        edges[i] = edgeData[i];

    int edgesColSize[2] = {2,2};

    int source = 0, destination = 2;

    if(validPath(n, edges, 2, edgesColSize, source, destination))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
