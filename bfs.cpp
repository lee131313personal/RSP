#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

// BFS function
void bfsTraversal(const vector<vector<int>>& adjList, int startNode, const vector<string>& nodeLabels) {
    vector<bool> visited(adjList.size(), false); // Track visited nodes
    queue<int> q;                               // Queue for BFS

    // Start from the given node
    q.push(startNode);
    visited[startNode] = true;

    cout << "BFS Traversal starting from " << nodeLabels[startNode] << ": ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Process the current node
        cout << nodeLabels[current] << " ";

        // Enqueue unvisited neighbors
        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
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

    // Perform BFS starting from Node A (index 0)
    bfsTraversal(adjList, 0, nodeLabels);

    return 0;
}

