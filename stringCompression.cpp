class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;  // Pointer to write the compressed result
        int i = 0;      // Pointer to iterate through the input array

        while (i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;

            // Count the occurrences of the current character
            while (i < chars.size() && chars[i] == currentChar) {
                i++;
                count++;
            }

            // Write the character to the compressed array
            chars[write++] = currentChar;

            // If count > 1, write the count as well
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }

        // The `write` pointer now represents the new length of the array
        return write;
    }
};
