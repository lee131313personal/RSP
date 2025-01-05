#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector;

    // Demonstrating push_back
    std::cout << "Adding elements using push_back:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        myVector.push_back(i);
        std::cout << "Added " << i << std::endl;
    }

    // Demonstrating pop_back
    std::cout << "\nRemoving the last element using pop_back:" << std::endl;
    myVector.pop_back();
    std::cout << "Last element removed." << std::endl;

    // Demonstrating resize
    std::cout << "\nResizing the vector to 3 elements:" << std::endl;
    myVector.resize(3);

    // Displaying the contents of the vector
    std::cout << "\nCurrent contents of the vector:" << std::endl;
    for (int i = 0; i < myVector.size(); ++i) {
        std::cout << "Element at index " << i << ": " << myVector[i] << std::endl;
    }

    return 0;
}
