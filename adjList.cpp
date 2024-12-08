#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Node labels for reference
    vector<string> nodeLabels = {"A", "B", "C", "D", "F"};

    // Adjacency list representation
    vector<vector<int>> adjList = {
        {1, 3},       // A: B, D
        {0, 2, 4},    // B: A, C, F
        {1, 4},       // C: B, F
        {0, 4},       // D: A, F
        {1, 2, 3}     // F: B, C, D
    };

    // Display the adjacency list
    cout << "Adjacency List Representation:" << endl;
    for (int i = 0; i < adjList.size(); ++i) {
        cout << nodeLabels[i] << ": ";
        for (int neighbor : adjList[i]) {
            cout << nodeLabels[neighbor] << " ";
        }
        cout << endl;
    }

    return 0;
}

