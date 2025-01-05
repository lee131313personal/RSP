#include <iostream>
#include <map>
#include <vector>

// Function to demonstrate std::map::emplace
void demonstrateMapEmplace() {
    std::map<int, std::string> myMap;

    // Using emplace to insert key-value pairs
    myMap.emplace(1, "One");
    myMap.emplace(2, "Two");
    myMap.emplace(3, "Three");

    // Attempting to insert a duplicate key (will not insert)
    myMap.emplace(1, "Uno");

    std::cout << "Contents of the map:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

// Function to demonstrate std::vector::emplace_back
void demonstrateVectorEmplaceBack() {
    std::vector<std::pair<int, std::string>> myVector;
    // Using emplace_back to insert elements at the end of the vector
    myVector.emplace_back(4, "Four");
    myVector.emplace_back(2, "Two");
    myVector.emplace_back(3, "Three");

    std::cout << "Contents of the vector:" << std::endl;
    for (const auto& element : myVector) {
        std::cout << element.first << ": " << element.second << std::endl;
    }
}

int main() {
    std::cout << "Demonstrating std::map::emplace" << std::endl;
    demonstrateMapEmplace();

    std::cout << "\nDemonstrating std::vector::emplace_back" << std::endl;
    demonstrateVectorEmplaceBack();

    return 0;
}

