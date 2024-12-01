#include <iostream>
#include <vector>
#include <algorithm>

// Function to maintain the max heap property
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;            // Initialize largest as root
    int left = 2 * i + 1;       // Left child
    int right = 2 * i + 2;      // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements from the heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to the end
        std::swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Input array
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Original array: ";
    printArray(arr);

    // Perform heap sort
    heapSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
