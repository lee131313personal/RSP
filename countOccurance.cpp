#include <iostream>
#include <unordered_map>

// Function to count occurrences of each character in a string
std::unordered_map<char, int> countOccurrence(const std::string& s) {
    // Map to count occurrences of each character
    std::unordered_map<char, int> char_count;

    // Count each character's occurrences in the string
    for (char c : s) {
        char_count[c]++;
    }

    return char_count;
}

int main() {
    // Test the function with the string "banana"
    std::string str = "bananafcdfcdscd";
    auto char_count = countOccurrence(str);

    // Display the entire character count map
    std::cout << "Character count map:" << std::endl;
    for (const auto& pair : char_count) {
        char character = pair.first;
        int occurrence = pair.second;
        std::cout << character << ": " << occurrence << std::endl;
    }

    return 0;
}

