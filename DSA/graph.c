#include <stdio.h>

#define N 6  

void updateEdge(int adj[N][N], int u, int v, int value) {
    adj[u-1][v-1] = value;   // -1 because array index starts from 0
}

// Function to print adjacency matrix
void printMatrix(int adj[N][N]) {
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

// Function to check in-degree and out-degree
void checkDegrees(int adj[N][N]) {
    int in, out;
    
    printf("\nNode\tIn-degree\tOut-degree\tStatus\n");
    
    for(int i = 0; i < N; i++) {
        in = 0;
        out = 0;

        // Out-degree
        for(int j = 0; j < N; j++) {
            out += adj[i][j];
        }

        // In-degree
        for(int j = 0; j < N; j++) {
            in += adj[j][i];
        }

        printf("%d\t%d\t\t%d\t\t", i+1, in, out);

        if(in == out)
            printf("Balanced\n");
        else
            printf("Not Balanced\n");
    }
}

// Function to check symmetry condition
int isSymmetric(int adj[N][N]) {
    int in, out;

    for(int i = 0; i < N; i++) {
        in = 0;
        out = 0;

        for(int j = 0; j < N; j++) {
            out += adj[i][j];
            in += adj[j][i];
        }

        if(in != out)
            return 0;   // not symmetric
    }

    return 1;   // symmetric
}

int main() {

    // Initialize adjacency matrix
    int adj[N][N] = {0};

    // Add edges based on your graph
    updateEdge(adj, 1, 2, 1);
    updateEdge(adj, 1, 3, 1);
    updateEdge(adj, 2, 3, 1);
    updateEdge(adj, 2, 4, 1);
    updateEdge(adj, 3, 4, 1);
    updateEdge(adj, 3, 5, 1);
    updateEdge(adj, 4, 5, 1);
    updateEdge(adj, 4, 6, 1);
    updateEdge(adj, 5, 6, 1);

    // Print matrix
    printMatrix(adj);

    // Check degrees
    checkDegrees(adj);

    // Check symmetry
    if(isSymmetric(adj))
        printf("\nGraph is Symmetric (All nodes have equal in & out degree)\n");
    else
        printf("\nGraph is NOT Symmetric\n");

    return 0;
}