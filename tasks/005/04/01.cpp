#include <iostream>
#include <vector>

using namespace std;

const int INF = 10000;

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
                cout << "10000 ";
            }
            else {
                cout << distanceMatrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
