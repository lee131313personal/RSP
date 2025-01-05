#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {2, 3, 4, 5};

    // Inserting an element at the front
    myVector.insert(myVector.begin(), 1);

    // Displaying the contents of the vector
    std::cout << "Contents of the vector after insertion: ";
    for (int element : myVector) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
