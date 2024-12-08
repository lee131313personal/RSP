#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Node labels for reference
    vector<string> nodeLabels = {"A", "B", "C", "D", "F"};

    // Edge list representation
    vector<pair<int, int>> edgeList = {
        {0, 1}, // A - B
        {0, 3}, // A - D
        {1, 2}, // B - C
        {1, 4}, // B - F
        {2, 4}, // C - F
        {3, 4}  // D - F
    };

    // Display the edge list
    cout << "Edge List Representation:" << endl;
    for (const auto& edge : edgeList) {
        cout << "(" << nodeLabels[edge.first] << ", " << nodeLabels[edge.second] << ")" << endl;
    }

    return 0;
}

