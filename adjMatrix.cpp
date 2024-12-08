#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Number of nodes in the graph
    const int numNodes = 5;

    // Node labels for reference
    vector<string> nodeLabels = {"A", "B", "C", "D", "F"};

    // Adjacency matrix representation
    vector<vector<int>> adjMatrix = {
        {0, 1, 0, 1, 0}, // A is connected to B, D
        {1, 0, 1, 0, 1}, // B is connected to A, C, F
        {0, 1, 0, 0, 1}, // C is connected to B, F
        {1, 0, 0, 0, 1}, // D is connected to A, F
        {0, 1, 1, 1, 0}  // F is connected to B, C, D
    };

    // Display the adjacency matrix with labels
    cout << "Adjacency Matrix:" << endl;
    cout << "    ";
    for (const auto& label : nodeLabels) {
        cout << label << " ";
    }
    cout << endl;

    for (int i = 0; i < numNodes; ++i) {
        cout << nodeLabels[i] << " | ";
        for (int j = 0; j < numNodes; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
Adjacency Matrix:
    A B C D F 
A | 0 1 0 1 0 
B | 1 0 1 0 1 
C | 0 1 0 0 1 
D | 1 0 0 0 1 
F | 0 1 1 1 0 
*/
