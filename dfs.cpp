#include <iostream>
#include <vector>
#include <string>

using namespace std;

// DFS function
void dfsTraversal(const vector<vector<int>>& adjList, int currentNode, vector<bool>& visited, const vector<string>& nodeLabels) {
    // Mark the current node as visited
    visited[currentNode] = true;

    // Process the current node
    cout << nodeLabels[currentNode] << " ";

    // Recursively visit all unvisited neighbors
    for (int neighbor : adjList[currentNode]) {
        if (!visited[neighbor]) {
            dfsTraversal(adjList, neighbor, visited, nodeLabels);
        }
    }
}

int main() {
    // Node labels for reference
    vector<string> nodeLabels = {"A", "B", "C", "D", "F"};

    // Adjacency list representation of the graph
    vector<vector<int>> adjList = {
        {1, 3},       // A: B, D
        {0, 2, 4},    // B: A, C, F
        {1, 4},       // C: B, F
        {0, 4},       // D: A, F
        {1, 2, 3}     // F: B, C, D
    };

    // Visited array to track visited nodes
    vector<bool> visited(adjList.size(), false);

    // Perform DFS starting from Node A (index 0)
    cout << "DFS Traversal starting from A: ";
    dfsTraversal(adjList, 0, visited, nodeLabels);
    cout << endl;

    return 0;
}

