#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create an unordered_map
    std::unordered_map<int, std::string> myMap;

    // Inserting elements into the unordered_map
    myMap.insert({1, "Apple"});
    myMap.insert({2, "Banana"});
    myMap.insert({3, "Cherry"});

    // Inserting elements using the subscript operator
    myMap[4] = "Date";
    myMap[5] = "Elderberry";

    // Display the elements in the unordered_map
    std::cout << "Elements in the unordered_map:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Find an element in the unordered_map
    int keyToFind = 3;
    auto it = myMap.find(keyToFind);
    if (it != myMap.end()) {
        std::cout << "Found key " << keyToFind << " with value: " << it->second << std::endl;
    } else {
        std::cout << "Key " << keyToFind << " not found in the unordered_map" << std::endl;
    }

    // Delete an element from the unordered_map
    int keyToDelete = 2;
    size_t removed = myMap.erase(keyToDelete);
    if (removed) {
        std::cout << "Removed key " << keyToDelete << " from the unordered_map" << std::endl;
    } else {
        std::cout << "Key " << keyToDelete << " not found in the unordered_map" << std::endl;
    }

    // Display the elements in the unordered_map after deletion
    std::cout << "Elements in the unordered_map after deletion:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Check if a key exists in the unordered_map
    int keyToSearch = 4;
    if (myMap.count(keyToSearch)) {
        std::cout << "Key " << keyToSearch << " exists in the unordered_map" << std::endl;
    } else {
        std::cout << "Key " << keyToSearch << " does not exist in the unordered_map" << std::endl;
    }

    return 0;
}

