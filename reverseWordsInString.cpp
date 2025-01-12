class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Trim whitespace and split the words
        vector<string> words;
        stringstream ss(s);
        string word;

        // Extract words into a vector
        while (ss >> word) {
            words.push_back(word);
        }

        // Step 2: Reverse the order of words
        reverse(words.begin(), words.end());

        // Step 3: Join the words back into a single string
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) {
                result += " "; // Add space between words
            }
        }

        return result;
    }
};
