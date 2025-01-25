#include <stdio.h>
#define INF 9999

void shortestPathWeight(int n, int mat[n][n], int start, int end){
    int dist[n][n]; // Distance matrix

    // Convert adjacency matrix to distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0 && i != j) {
                dist[i][j] = INF; // No direct edge
            } else {
                dist[i][j] = mat[i][j]; // Copy edge weight
            }
        }
    }

    // Run Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest path weight
    if (dist[start][end] == INF) {
        printf("There is no path between node %d and node %d.\n", start, end);
    } else {
        printf("The shortest path weight between node %d and node %d is: %d\n", start, end, dist[start][end]);
    }
}


int main(){
    int n;

    printf("Enter the size of the matrix: \n");
    scanf("%d", &n);

    int mat[n][n];

    // Input the matrix elements
    printf("Enter the matrix numbers: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }

    // Print the matrix
    printf("the matrix is: \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }

    int start, end;

    // Input start and end nodes
    printf("Enter the start node: ");
    scanf("%d", &start);
    printf("Enter the end node: ");
    scanf("%d", &end);

    shortestPathWeight(n, mat, start, end);

    return 0;
}
