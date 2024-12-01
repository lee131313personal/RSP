#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    // Fix the heap property upwards
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

public:
    // Insert a new value into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1); // Fix the heap property
    }

    // Display the heap array
    void displayHeap() {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap maxHeap;

    // Input array
    std::vector<int> input = {10, 20, 15, 30, 40, 50, 60};

    std::cout << "Building Max Heap:" << std::endl;

    for (int num : input) {
        std::cout << "Inserting " << num << ": ";
        maxHeap.insert(num);
        maxHeap.displayHeap();
    }

    std::cout << "Final Max Heap: ";
    maxHeap.displayHeap();

    return 0;
}
