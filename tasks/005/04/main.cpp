#include <iostream>
#include <vector>

using namespace std;

const int INF = 10000;

void printMatrix(const vector<vector<int>>& matrix, const string& name)
{
    cout << name << " matrix:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val == INF) {
                cout << "INF ";
            }
            else {
                cout << val << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void floydWarshall(vector<vector<int>>& distanceMatrix, vector<vector<int>>& next)
{
    int n = distanceMatrix.size();

    // Initialize next matrix for path reconstruction
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            next[i][j] = j;
        }
    }

    // Initial state
    printMatrix(distanceMatrix, "Initial distance");
    printMatrix(next, "Initial next");

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distanceMatrix[i][k] + distanceMatrix[k][j] < distanceMatrix[i][j]) {
                    distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                    next[i][j] = next[i][k];

                    // Print the state after each update
                    printMatrix(distanceMatrix, "Updated distance");
                    printMatrix(next, "Updated next");
                }
            }
        }
    }
}

void printShortestPath(int start, int end, const vector<vector<int>>& next)
{
    cout << "Shortest path from " << start << " to " << end << ": ";
    cout << start;

    while (start != end) {
        start = next[start][end];
        cout << " -> " << start;
    }

    cout << endl;
}

int main()
{
    // Initialize the adjacency matrix with INF
    vector<vector<int>> distanceMatrix(8, vector<int>(8, INF));

    // Given relationships
    distanceMatrix[0][1] = 16;  // A->B
    distanceMatrix[0][6] = 11;  // A->G
    distanceMatrix[0][3] = 2;   // A->D
    distanceMatrix[1][2] = 6;   // B->C
    distanceMatrix[3][2] = 8;   // D->C
    distanceMatrix[3][4] = 3;   // D->E
    distanceMatrix[5][6] = 7;   // F->G
    distanceMatrix[5][4] = 2;   // F->E
    distanceMatrix[7][5] = 4;   // H->F
    distanceMatrix[7][1] = 5;   // H->B

    // Set diagonal elements to 0
    for (int i = 0; i < 8; ++i) {
        distanceMatrix[i][i] = 0;
    }

    // Print the initial distance matrix
    cout << "Initial distance matrix:\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (distanceMatrix[i][j] == INF) {
                cout << "INF ";
            }
            else {
                cout << distanceMatrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    // Run Floyd-Warshall algorithm
    vector<vector<int>> next(8, vector<int>(8, 0));
    floydWarshall(distanceMatrix, next);

    // Print the final distance matrix after running Floyd-Warshall
    cout << "\nFinal distance matrix after Floyd-Warshall:\n";
    printMatrix(distanceMatrix, "Final distance");

    // Print the final next matrix after running Floyd-Warshall
    cout << "\nFinal next matrix after Floyd-Warshall:\n";
    printMatrix(next, "Final next");

    // Find and print shortest paths from A to other nodes
    for (int i = 1; i < 8; ++i) {
        printShortestPath(0, i, next);
        cout << "Shortest distance: " << distanceMatrix[0][i] << endl;
    }

    return 0;
}
