class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        if (word2.length() == 0 && word1.length() != 0) return word1;
        if (word1.length() == 0 && word2.length() != 0) return word2;
        if (word1.length() == 0 && word2.length() == 0) return "";

        string result = "";
        std::string::iterator it1 = word1.begin();
        std::string::iterator it2 = word2.begin();
        while (it1 != word1.end() && it2 != word2.end()) {
            result.push_back(*it1);
            result.push_back(*it2);
            it1++;
            it2++;
        }
        if (it1 == word1.end()) {
            while (it2 != word2.end()) {
                result.push_back(*it2);
                it2++;
            }
        }
        if (it2 == word2.end()) {
            while (it1 != word1.end()) {
                result.push_back(*it1);
                it1++;
            }
        }
        return result;
    }
};
